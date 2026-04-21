//
// Created by Hugo on 21/04/2026.
//

#include "SessionState.h"

#include <iostream>


SessionState::SessionState() {
}

void SessionState::saveSessionState(const int& track, const int& station) const {

    std::ofstream ofs("session_state.txt", std::ios::trunc);
    if (!ofs.is_open()) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }
    ofs << "LOCAL_MUSIC" << std::endl;
    ofs << track << std::endl;

    ofs << "INTERNET_RADIO" << std::endl;
    ofs << station << std::endl;
    ofs.close();
}

const int & SessionState::recoverTrackNumber() {
    std::string line;
    std::ifstream ifs("session_state.txt");
    if (!ifs.is_open()) {
        std::cerr << "Unable to open file for reading" << std::endl;
        return stationNumber;
    }

    //track = recoveredTrackNumber;
    while (std::getline(ifs, line)) {
        if (line == "LOCAL_MUSIC") {
            break;
        }
    }

    ifs >> trackNumber;
    ifs.ignore();

    ifs.close();
    return trackNumber;
}

const int & SessionState::recoverStationNumber() {
    std::string line;
    std::ifstream ifs("session_state.txt");
    if (!ifs.is_open()) {
        std::cerr << "Unable to open file for reading" << std::endl;
        return stationNumber;
    }

    while (std::getline(ifs, line)) {
        if (line == "INTERNET_RADIO") {
            break;
        }
    }

    ifs >> stationNumber;
    ifs.ignore();

    ifs.close();

    return stationNumber;
}
