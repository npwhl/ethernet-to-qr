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
  
  /* Serial testing */
  Serial.begin(9600);

  QRCode qrcode; // QRCode structure
   
  // Allocate a chunk of memory to store the QR code
  uint8_t qrcodeBytes[qrcode_getBufferSize()];

  qrcode_initText(&qrcode, qrcodeBytes, 3, ECC_LOW, "HELLO WORLD");
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
