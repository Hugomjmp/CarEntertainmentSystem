//
// Created by Hugo on 21/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
#define CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
#include "enums/SourceType.h"
#include <fstream>

class SessionState {
private:
    int trackNumber = 0;
    int stationNumber = 0;

public:
    SessionState();
    ~SessionState() = default;
    void saveSessionState(const int& track, const int& station) const;
    const int & recoverTrackNumber();
    const int & recoverStationNumber();

};



#endif //CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
