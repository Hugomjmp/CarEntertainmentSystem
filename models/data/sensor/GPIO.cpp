//
// Created by Hugo on 14/04/2026.
//

#include "GPIO.h"

#include <iostream>

GPIO::GPIO() {
    /*pi = pigpio_start(nullptr, nullptr);
    if (pi < 0) {
        std::cerr << "Error opening pigpio" << std::endl;
    }*/
}

GPIO::~GPIO() {
    /*if (pi >= 0) {
        pigpio_stop(pi);
    }*/
}

int GPIO::getPi() const {
    //return pi;
}

void GPIO::setMode(int pin, int mode) {
    //set_mode(pi, pin, mode);
}

void GPIO::write(int pin, int value) {
    //gpio_write(pi, pin, value);
}

int GPIO::read(int pin) {
    //return gpio_read(pi, pin);
}

void GPIO::delayMicroseconds(int microseconds) {
    //time_sleep(microseconds/ 1000000.0);
}

/*uint32_t GPIO::getCurrentTick() {
    return get_current_tick(pi);
}*/
