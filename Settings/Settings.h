
#ifndef CARENTERTAINMENTSYSTEM_SETTINGS_H
#define CARENTERTAINMENTSYSTEM_SETTINGS_H
#include <string>

class Settings {
public:
    class DHT11Settings {
        public:
        static const int DHT_PIN = 4;
    };
    class TEA5767Settings {
        public:
        static const uint8_t I2C_ADDRESS = 0x60;
    };


};

#endif //CARENTERTAINMENTSYSTEM_SETTINGS_H