//
// Created by Hugo on 14/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_GPIO_H
#define CARENTERTAINMENTSYSTEM_GPIO_H

//#include <pigpiod_if2.h>

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
    //uint32_t getCurrentTick();
};



#endif //CARENTERTAINMENTSYSTEM_GPIO_H
