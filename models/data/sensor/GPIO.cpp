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
    //openI2C(0x60,1);
}

GPIO::~GPIO() {
    if (pi >= 0) {
        pigpio_stop(pi);
    }
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

int GPIO::openI2C(const uint8_t &address, const int &bus) {
    return i2c_open(pi, bus, address,0);
}

void GPIO::closeI2C(const int& handle) const {
    i2c_close(pi, handle);
}

int GPIO::writeI2C(const int &handle, const uint8_t *data, int size) const {
    return i2c_write_device(pi,handle,(char*) data,size);

}

int GPIO::readI2C(const int &handle, uint8_t *data, int size) const {
    return i2c_read_device(pi, handle,(char*) data,size);
}

