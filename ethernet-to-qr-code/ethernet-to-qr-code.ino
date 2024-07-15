#include <SPI.h>
#include <Ethernet.h>

// Unique MAC address to create an IP address from
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Backup IP address
IPAddress ip(10, 0, 0, 162);
IPAddress myDns(10, 0, 0, 162); 

EthernetServer server(80); // Address for image host device
EthernetServer server2(8080); // Address for transfer device

EthernetClient client; 

void setup() {
  pinMode(8, INPUT_PULLUP); // Turn off radio pin on LoRa board, unused
  Ethernet.init(10); // CS pin
  
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("begin!");

  if(Ethernet.begin(mac) == 0) { // In case DHCP doesn't work
    Ethernet.begin(mac, ip, myDns);
  }
  while(Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Please connect an ethernet shield.");
    delay(1000);
  }
  while (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
    delay(1000);
  }

  server.begin();
  server2.begin();
  Serial.print("Please access: ");
  Serial.print(Ethernet.localIP());
  Serial.println(" in your web browser.");
  
}

void loop() {
  EthernetClient client = server.available(); // Webpage with QR codes to scan
  EthernetClient client2 = server2.available(); // Webpage that the user sees on the transfer device
  if(client) {
    while(client.connected()) {
      if(client.available()) {
        client.println("<!DOCTYPE HTML>");
        client.println("<html lang='en'>");
        client.println("<head>");
        //client.println("<link rel='stylesheet' href='css/style.css'>");
        client.println("<script src= 'https://cdnjs.cloudflare.com/ajax/libs/qrcodejs/1.0.0/qrcode.min.js'> </script> ");
        client.println("</head>");
        
        client.println("<body>");
        client.println("<H1 class='title' style='text-align: center'>QR Code Image Transfer<H1>");
        client.println("<P>Please scan the QR code below.</P>");
        String toSt = Ethernet.localIP().toString();
        client.println("<div id='qrcode'></div>");

        client.println("<script>");
        client.println("var qrcode = new QRCode('qrcode', 'http://" + toSt + ":8080/')");
        client.println("</script>");
        
        client.println("</body>");
        client.println("</html>");
        
      }

      break;
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
        if(client2) {
          while(client2.connected()) {
            if(client2.available()) {
              client2.println("HI!");
              delay(10);
            }
          }
        }
     
    delay(5000);
}
