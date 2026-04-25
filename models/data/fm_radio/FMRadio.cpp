//
// Created by Hugo on 22/04/2026.
//

#include "../fm_radio/FMRadio.h"

FMRadio::FMRadio(II2C &i2c) : i2c(i2c) {

    data[2] = 0xB0; //3 byte
    data[3] = 0x10; //4 byte
    data[4] = 0x00; //5 byte

}

void FMRadio::setFrequency(const float &frequency){
    unsigned int pll = (4 * (frequency * 1000000 + 225000)) / 32768;

    data[0] = pll >> 8;
    data[1] = pll & 0xFF;

    i2c.write(data,5);
    currentFrequency = frequency;
}

void FMRadio::scan() {

}

void FMRadio::mute() {
    if (muted) {
        muted = false;
        data[2] = 0xB6;
    } else {
        muted = true;
        data[2] = 0xB0;
    }
    i2c.write(data,5);
}

void FMRadio::readRSSI() {

}

const float & FMRadio::getFrequency() const {
    return currentFrequency;
}
