//
// Created by Hugo on 14/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_GPIO_H
#define CARENTERTAINMENTSYSTEM_GPIO_H

#include <pigpiod_if2.h>

class GPIO {
private:
    int pi;
    int I2C_TEA5767 = 0;
    void openI2C(const uint8_t &address, const int &bus);
public:
    GPIO();
    ~GPIO();
    int getPi() const;
    void setMode(int pin, int mode);
    void write(int pin, int value);
    int read(int pin);
    void delayMicroseconds(int microseconds);


    void closeI2C() const;
    void writeI2C(const int &pi, const int &handle, char *value);

    int getHandle() const;
};



#endif //CARENTERTAINMENTSYSTEM_GPIO_H
