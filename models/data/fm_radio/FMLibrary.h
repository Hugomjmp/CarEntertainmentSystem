//
// Created by Hugo on 30/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FMLIBRARY_H
#define CARENTERTAINMENTSYSTEM_FMLIBRARY_H
#include <vector>

#include "FMStation.h"


class FMLibrary {
private:
    std::vector<FMStation> stations;
public:
    FMLibrary();
    ~FMLibrary() = default;
    void addStation(const FMStation& station);
    const std::vector<FMStation>& getStations() const;
};


#endif //CARENTERTAINMENTSYSTEM_FMLIBRARY_H
