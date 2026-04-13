//
// Created by Hugo on 13/04/2026.
//

#include "GPS.h"

#include <cstring>
#include <iostream>
//#include <pigpio.h>
//just for testing
GPS::GPS() {
    /*int handle = serOpen("/dev/serial0", 9600, 0);
    if (handle == -1) {
        std::cerr << "Error opening serial port" << std::endl;
    }
    char buffer[256];
    std::memset(buffer, 0, sizeof(buffer));
    while (true) {
        int count = serRead(handle, buffer, sizeof(buffer) - 1);

        if (count > 0) {
            buffer[count] = '\0';
            std::cout << buffer << std::endl;
        }

        gpioDelay(100000);
    }

    serClose(handle);*/
}



