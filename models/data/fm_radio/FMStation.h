//
// Created by Hugo on 25/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FMSTATION_H
#define CARENTERTAINMENTSYSTEM_FMSTATION_H

#include <string>

class FMStation {
private:
    float frequency;
    std::string stationName;
public:
    FMStation(const float &frequency, const std::string& stationName) : frequency(frequency), stationName(stationName) {}
    ~FMStation() = default;
    const float &getFrequency() const;
    const std::string &getStationName() const;

};


#endif //CARENTERTAINMENTSYSTEM_FMSTATION_H
