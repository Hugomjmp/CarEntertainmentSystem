//
// Created by Hugo on 22/04/2026.
//

#include "../fm_radio/FMRadio.h"

FMRadio::FMRadio(GPIO &gpio) : gpio(gpio) {

}

void FMRadio::setFrequency(const int &handle, const float &frequency) const{
    unsigned int pll = (4 * (frequency * 1000000 + 225000)) / 32768;

    uint8_t buffer[5];

    buffer[0] = pll >> 8;
    buffer[1] = pll & 0xFF;

    buffer[2] = 0xB0; // stereo ON, mute OFF, search OFF
    buffer[3] = 0x10; // gain / band config
    buffer[4] = 0x00; // deemphasis

    i2c_write_device(gpio.getPi(), handle, (char*)buffer, 5);
}

void FMRadio::scan() {
}

void FMRadio::mute() {
}

void FMRadio::readRSSI() {
}
