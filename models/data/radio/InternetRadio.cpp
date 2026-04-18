//
// Created by Hugo on 18/04/2026.
//

#include "InternetRadio.h"

int InternetRadio::getRadioLibrarySize() const {
    return radio_library.getStationLibrary().size();
}

std::string InternetRadio::getStationName() const {
    return "radio_library.getStationName()";
}

const Station * InternetRadio::getStation() const {
    if (&radio_library.getStationLibrary().at(stationNumber) != nullptr) {
        return &radio_library.getStationLibrary().at(stationNumber);
    }
    return nullptr;
}

void InternetRadio::nextStation() {
    if (stationNumber >= getRadioLibrarySize() - 1) {
        stationNumber = 0;
        return;
    }
    stationNumber++;
}

void InternetRadio::previousStation() {
    if (stationNumber <= 0) {
        stationNumber = getRadioLibrarySize() - 1;
        return;
    }
    stationNumber--;
}
