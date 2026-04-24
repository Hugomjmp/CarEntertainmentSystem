//
// Created by Hugo on 22/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FMRADIO_H
#define CARENTERTAINMENTSYSTEM_FMRADIO_H

#include "../sensor/GPIO.h"


class FMRadio {
private:
    GPIO &gpio;
    uint8_t buffer[5];
public:
    FMRadio(GPIO &gpio);
    ~FMRadio() = default;
    void setFrequency(const int &handle, const float &frequency) const;
    void scan();
    void mute();
    void readRSSI();

};



#endif //CARENTERTAINMENTSYSTEM_FMRADIO_H
