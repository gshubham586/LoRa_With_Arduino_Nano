
/*Pin Coonection
  LoRa Module        Arduino Nano
  3.3V                  3V3
  GND                   GND
  En/NSS                D10
  SCK                   D13
  MISO                  D12
  MOSI                  D11
  RST                   D9

  Attached +ve terminal of 3.7V battery to Vin pin of Arduino Nnao
  Attached -ve terminal of 3.7V battery to GND pin of Arduino Nnao

  
   It is receiver code. It will send "hello world!" with a increment counter.
  Zip file of used libarary (Lora.h) is available in folder please add it in arduino ide.


  My Test Result 
  * At Tx power <= 16, Sender is able to send data but when I set Tx power gretaer than 16 
    sender is not able to send data.
 */

 



#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(115200);


  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {              // Set frequency for LoRa module. Here it is 433MHz
    Serial.println("LoRa Initialisation failed!");
    while (1);
  }
  else {
   Serial.println("LoRa Initialisation successful");
  }

  LoRa.setTxPower(10);           // Set Tx power of module in dB. Range 0 to 20
  
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello world! ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(1000);
}
