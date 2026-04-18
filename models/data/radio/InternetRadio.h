//
// Created by Hugo on 18/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_INTERNETRADIO_H
#define CARENTERTAINMENTSYSTEM_INTERNETRADIO_H
#include "OnlineRadioLibrary.h"


class InternetRadio {
private:
    OnlineRadioLibrary& radio_library;
    int stationNumber = 0;
    int getRadioLibrarySize() const;
public:
    InternetRadio(OnlineRadioLibrary& library) : radio_library(library) {}
    ~InternetRadio() = default;
    std::string getStationName() const;
    const Station* getStation() const;

    void nextStation();
    void previousStation();

};



#endif //CARENTERTAINMENTSYSTEM_INTERNETRADIO_H
