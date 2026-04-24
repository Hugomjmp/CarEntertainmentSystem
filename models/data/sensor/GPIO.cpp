//
// Created by Hugo on 14/04/2026.
//

#include "GPIO.h"

#include <iostream>

GPIO::GPIO() {
    pi = pigpio_start(nullptr, nullptr);
    if (pi < 0) {
        std::cerr << "Error opening pigpio" << std::endl;
    }
    openI2C(0x60,1);
}

GPIO::~GPIO() {
    if (pi >= 0) {
        pigpio_stop(pi);
    }
    closeI2C();

}

int GPIO::getPi() const {
    return pi;
}

void GPIO::setMode(int pin, int mode) {
    set_mode(pi, pin, mode);
}

void GPIO::write(int pin, int value) {
    gpio_write(pi, pin, value);
}

int GPIO::read(int pin) {
    return gpio_read(pi, pin);
}

void GPIO::delayMicroseconds(int microseconds) {
    time_sleep(microseconds/ 1000000.0);
}

void GPIO::openI2C(const uint8_t &address, const int &bus) {
    I2C_TEA5767 = i2c_open(pi, bus,address,0);
}

void GPIO::closeI2C() const {
    i2c_close(pi, I2C_TEA5767);
}

void GPIO::writeI2C(const int &pi, const int &handle, char *value) {
    i2c_write_device(pi, handle,value, 5);
}


int GPIO::getHandle() const {
    return I2C_TEA5767;
}
