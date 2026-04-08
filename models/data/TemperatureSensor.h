//
// Created by Hugo on 25/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_TEMPERATURE_H
#define CARENTERTAINMENTSYSTEM_TEMPERATURE_H
#include <cstdint>

/**
 * Class that represents the DHT11, DHT22 temperature and Humidity sensor.
 */
class TemperatureSensor {
private:
    float temperature;
    float humidity;
public:
    TemperatureSensor();
    ~TemperatureSensor() = default;
    
};


#endif //CARENTERTAINMENTSYSTEM_TEMPERATURE_H