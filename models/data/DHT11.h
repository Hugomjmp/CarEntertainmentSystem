//
// Created by Hugo on 25/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_TEMPERATURE_H
#define CARENTERTAINMENTSYSTEM_TEMPERATURE_H
#include <array>
#include <pigpio.h>
#include "../../Settings/Settings.h"
/**
 * Class that represents the DHT11, DHT22 temperature and Humidity sensor.
 */
class DHT11 {
private:
    int DHT_PIN = Settings::DHT11Settings::DHT_PIN;
    double temperature;
    double humidity;
    void startSignal();
    bool waitForData(int pin, int level, int timeout);
public:
    DHT11();
    ~DHT11() = default;
    void readSensorData();
    double getTemperature() const;
    double getHumidity() const;
};


#endif //CARENTERTAINMENTSYSTEM_TEMPERATURE_H