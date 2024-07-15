#include <SPI.h>
#include <Ethernet.h>

// Unique MAC address to create an IP address from
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Allocate a chunk of memory to store the QR code
uint8_t qrcodeBytes[qrcode_getBufferSize()];

qrcode_initText(&qrcode, qrcodeBytes, 3, ECC_LOW, "HELLO WORLD");

EthernetServer server(80); // IP Address uses HTTP

void setup() {
  pinMode(8, INPUT_PULLUP); // Turn off radio pin on LoRa board, unused
  Ethernet.init(10); // CS pin
  
  Serial.begin(9600);

  Ethernet.begin(mac); // No IP specified, makes unique IP
  while(Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Please connect an ethernet shield.");
  }

  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
