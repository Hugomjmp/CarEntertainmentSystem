//
// Created by Hugo on 25/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_PIGIOI2C_H
#define CARENTERTAINMENTSYSTEM_PIGIOI2C_H
#include "GPIO.h"
#include "II2C.h"


class PigpioI2C : public II2C{
private:
    GPIO &gpio;
    int handle;
public:
    PigpioI2C(GPIO &gpio, const int &handle) : gpio(gpio), handle(handle) {}
    void write(const uint8_t *data, int size) override;
    void read(uint8_t *data, int size) override;
};


#endif //CARENTERTAINMENTSYSTEM_PIGIOI2C_H
