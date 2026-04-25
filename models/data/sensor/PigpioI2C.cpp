//
// Created by Hugo on 25/04/2026.
//

#include "PigpioI2C.h"

void PigpioI2C::write(const uint8_t *data, int size) {
    gpio.writeI2C(handle, data, size);
}

void PigpioI2C::read(uint8_t *data, int size) {
    gpio.readI2C(handle, data, size);
}
