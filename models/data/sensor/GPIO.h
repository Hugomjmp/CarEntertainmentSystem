//
// Created by Hugo on 14/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_GPIO_H
#define CARENTERTAINMENTSYSTEM_GPIO_H

#include <pigpiod_if2.h>

class GPIO {
private:
    int pi;

public:
    GPIO();
    ~GPIO();
    int getPi() const;
    void setMode(int pin, int mode);
    void write(int pin, int value);
    int read(int pin);
    void delayMicroseconds(int microseconds);
    int openI2C(const uint8_t &address, const int &bus);
    void closeI2C(const int& handle) const;
    int writeI2C(const int &handle, const uint8_t *data, int size) const;
    int readI2C(const int &handle, uint8_t * data, int size) const;
};



#endif //CARENTERTAINMENTSYSTEM_GPIO_H
