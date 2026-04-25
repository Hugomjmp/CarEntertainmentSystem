//
// Created by Hugo on 22/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FMRADIO_H
#define CARENTERTAINMENTSYSTEM_FMRADIO_H

#include <cstdint>

#include "../sensor/GPIO.h"
#include "../sensor/II2C.h"


class FMRadio {
private:
    std::uint8_t data[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
    bool muted = false;
    float currentFrequency = 87.5;
    II2C &i2c;
public:
    FMRadio(II2C &i2c);
    ~FMRadio() = default;
    void setFrequency(const float &frequency);
    void scan();
    void mute();
    void readRSSI();
    const float& getFrequency() const;
};



#endif //CARENTERTAINMENTSYSTEM_FMRADIO_H
