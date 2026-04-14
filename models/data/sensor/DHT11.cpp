//
// Created by Hugo on 25/03/2026.
//

#include "../sensor/DHT11.h"

DHT11::DHT11() {
}

void DHT11::startSignal() {

    gpioSetMode(DHT_PIN, PI_OUTPUT);
    gpioWrite(DHT_PIN, PI_LOW);
    gpioDelay(18000); //18ms

    gpioWrite(DHT_PIN, PI_HIGH);
    gpioDelay(40); //40us

    gpioSetMode(DHT_PIN, PI_INPUT);
}

void DHT11::readSensorData() {
    uint8_t data[5] = {0,0,0,0,0};

    temperature = 0;
    humidity = 0;
    gpioSleep(PI_TIME_RELATIVE, 2,0);
    startSignal();


    if (!waitForData(DHT_PIN, PI_HIGH, 200)) return;
    if (!waitForData(DHT_PIN, PI_LOW, 200)) return;
    if (!waitForData(DHT_PIN, PI_HIGH, 200)) return;


    for (int i = 0; i < 40; i++) {

        //while (gpioRead(DHT_PIN) == PI_LOW) {}
        if (!waitForData(DHT_PIN, PI_LOW, 200)) return;

        uint32_t t = gpioTick();

        //while (gpioRead(DHT_PIN) == PI_HIGH) {}
        if (!waitForData(DHT_PIN, PI_HIGH, 200)) return;
        uint32_t duration = gpioTick() - t;

        if (duration > 50) {
            data[i/8] |= (1 << (7 - (i % 8)));
        }

    }

    if ((data[0] + data[1] + data[2] + data[3]) != data[4]) {
        /*std::cerr << "Checksum error!" << std::endl;*/
        return;
    }

    temperature = data[0];
    humidity = data[2];



}

bool DHT11::waitForData(int pin, int level, int timeout) {

    uint32_t t = gpioTick();
    while (gpioRead(pin) == (level)) {
        if (gpioTick() - t > static_cast<uint32_t>(timeout)) {
            /*std::cerr << "Timeout!" << std::endl;*/
            return false;
        }
    }
    return true;
}

double DHT11::getTemperature() const {
    return temperature;
}

double DHT11::getHumidity() const {
    return humidity;
}
