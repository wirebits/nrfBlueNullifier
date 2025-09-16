/*
 * nrfBlueNullifier
 * DIY project to jam classic bluetooth signals using 2 nrf24L01 modules.
 * Author - WireBits
 */

#include <RF24.h>
#include <esp_bt.h>
#include <esp_wifi.h>
#include <esp_bt_main.h>

SPIClass *sp = nullptr;
SPIClass *hp = nullptr;

RF24 radioA(16, 15, 19909090);
RF24 radioB(22, 21, 19909090);

int HSPIchannel = 45;
int VSPIchannel = 45;
unsigned int HSPIflag = 0;
unsigned int VSPIflag = 0;

void channelSweeper() {
  if (VSPIflag == 0) VSPIchannel += 4; else VSPIchannel -= 4;
  if (HSPIflag == 0) HSPIchannel += 2; else HSPIchannel -= 2;
  if ((VSPIchannel > 79) && (VSPIflag == 0)) VSPIflag = 1; else if ((VSPIchannel < 2) && (VSPIflag == 1)) VSPIflag = 0;
  if ((HSPIchannel > 79) && (HSPIflag == 0)) HSPIflag = 1; else if ((HSPIchannel < 2) && (HSPIflag == 1)) HSPIflag = 0;
  radioA.setChannel(HSPIchannel);
  radioB.setChannel(VSPIchannel);
}

void randomChannel() {
  radioA.setChannel(random(80));
  radioB.setChannel(random(80));
  delayMicroseconds(random(60));
}

void initHSPI() {
  hp = new SPIClass(HSPI);
  hp->begin();
  if (radioA.begin(hp)) {
    radioA.setAutoAck(false);
    radioA.stopListening();
    radioA.setRetries(0, 0);
    radioA.setPayloadSize(32);
    radioA.setAddressWidth(5);
    radioA.setPALevel(RF24_PA_MAX, true);
    radioA.setDataRate(RF24_2MBPS);
    radioA.setCRCLength(RF24_CRC_DISABLED);
    radioA.startConstCarrier(RF24_PA_MAX, HSPIchannel);
  }
}

void initVSPI() {
  sp = new SPIClass(VSPI);
  sp->begin();
  if (radioB.begin(sp)) {
    radioB.setAutoAck(false);
    radioB.stopListening();
    radioB.setRetries(0, 0);
    radioB.setPayloadSize(32);
    radioB.setAddressWidth(5);
    radioB.setPALevel(RF24_PA_MAX, true);
    radioB.setDataRate(RF24_2MBPS);
    radioB.setCRCLength(RF24_CRC_DISABLED);
    radioB.startConstCarrier(RF24_PA_MAX, VSPIchannel);
  }
}

void setup() {
  esp_bt_controller_deinit();
  esp_wifi_stop();
  esp_wifi_deinit();
  esp_wifi_disconnect();
  if (esp_bluedroid_get_status() == ESP_BLUEDROID_STATUS_ENABLED) {
    esp_bluedroid_deinit();
    esp_bluedroid_disable();
  }
  initHSPI();
  initVSPI();
}

void loop() {
  channelSweeper();
  randomChannel();

}
