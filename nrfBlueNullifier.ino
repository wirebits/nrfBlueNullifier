/*
 * nrfBlueNullifier
 * DIY project to jam classic bluetooth signals.
 * Author - WireBits
 */

#include <RF24.h>
#include <esp_bt.h>
#include <esp_bt_main.h>

SPIClass *sp = nullptr;
RF24 radio(22, 21, 19909090);
byte i = 45, ptr_hop = 0, flag = 0;
byte hopping_channel[] = {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80, 82, 84, 86};

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
        radio.startConstCarrier(RF24_PA_MAX, i);
    }
}

void adjustAndSweepChannels() {
    flag = (i > 79) ? 1 : (i < 2 ? 0 : flag);
    i += flag ? -2 : 2;
    for (int j = 0; j <= 79; j++) radio.setChannel(j);
}

void setup() {
    esp_bt_controller_deinit();
    if (esp_bluedroid_get_status() == ESP_BLUEDROID_STATUS_ENABLED) {
        esp_bluedroid_disable();
        esp_bluedroid_deinit();
    }
    nrfSPIInit();
}

void loop() {
        adjustAndSweepChannels();
        ptr_hop = (ptr_hop + 1) % sizeof(hopping_channel);
        radio.setChannel(hopping_channel[ptr_hop]);
}
