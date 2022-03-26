/*Pin Coonection
  LoRa Module        Arduino Nano
  3.3V                  3V3
  GND                   GND
  En/NSS                D10
  SCK                   D13
  MISO                  D12
  MOSI                  D11
  RST                   D9

 It is receiver code. It will print received packet from sender and toggle the LED when packet is received.
 Zip file of used libarary (Lora.h) is available in folder please add it in arduino ide.
 */

#include <SPI.h>
#include <LoRa.h>
 int LED_PIN = 4;    //Attach LED on pin 4
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);     // Connected 

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {                // Set frequency for LoRa module. Here it is 433MHz
    Serial.println("Starting LoRa failed!");
  
  }
   else {
   Serial.println("LoRa Initialisation successful");
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));   //Toggle attached LED.
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
