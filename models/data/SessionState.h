//
// Created by Hugo on 21/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
#define CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
#include "enums/SourceType.h"
#include <fstream>
#include <iostream>

class SessionState {
private:
    int trackNumber = 0;
    int stationNumber = 0;
    std::string currentSongTime = "";
    SourceType sourceType;
public:
    SessionState();
    ~SessionState() = default;
    void saveSessionState(const int& track, const std::string& currentSongTime, const int& station, const SourceType& source) const;
    const int & recoverTrackNumber();
    const std::string & recoverCurrentSongTime();
    const int & recoverStationNumber();
    SourceType recoverSourceType();

};



#endif //CARENTERTAINMENTSYSTEM_SESSIONSTATE_H
