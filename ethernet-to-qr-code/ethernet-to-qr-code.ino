#include <SPI.h>
#include <Ethernet.h>

// Unique MAC address to create an IP address from
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

EthernetServer server(80); // IP Address uses HTTP

void setup() {
  pinMode(8, INPUT_PULLUP); // Turn off radio pin on LoRa board, unused
  Ethernet.init(10); // CS pin
  
  // Serial testing
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
