#include <SPI.h>
#include <Ethernet.h>
#include "index.h"

// Unique MAC address to create an IP address from
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Backup IP address
IPAddress ip(10, 0, 0, 155);
IPAddress myDns(10, 0, 0, 155); 

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
        String toSt = Ethernet.localIP().toString();
        client.println(index_html);
        //client.println("<html>Test</html>");
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

void readHTML() {
  
}
