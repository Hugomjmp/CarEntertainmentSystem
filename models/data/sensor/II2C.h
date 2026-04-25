//
// Created by Hugo on 25/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_II2C_H
#define CARENTERTAINMENTSYSTEM_II2C_H
#include <cstdint>


class II2C {
public:
    virtual void write(const uint8_t *data, int size) = 0;
    virtual void read(uint8_t *data, int size) = 0;
};


#endif //CARENTERTAINMENTSYSTEM_II2C_H
