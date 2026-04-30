//
// Created by Hugo on 30/04/2026.
//

#include "FMLibrary.h"

FMLibrary::FMLibrary() {
}

void FMLibrary::addStation(const FMStation &station) {
    for (int i = 0; i < stations.size(); ++i) {
        if (stations.at(i).getFrequency() == station.getFrequency()) {
            return;
        }
    }
    stations.push_back(station);
}

const std::vector<FMStation> & FMLibrary::getStations() const {
    return stations;
}
