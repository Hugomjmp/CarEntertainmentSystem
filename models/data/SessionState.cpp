//
// Created by Hugo on 21/04/2026.
//

#include "SessionState.h"




SessionState::SessionState() {
}

void SessionState::saveSessionState(const int& track, const std::string& currentSongTime ,const int& station, const SourceType& source) const {
    std::ofstream ofs("session_state.txt", std::ios::trunc);
    if (!ofs.is_open()) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }
    ofs << "LOCAL_MUSIC" << std::endl;
    ofs << track << std::endl;

    ofs << "TIME" << std::endl;
    ofs << currentSongTime << std::endl;

    ofs << "INTERNET_RADIO" << std::endl;
    ofs << station << std::endl;

    ofs << "SOURCE" << std::endl;
    ofs << source << std::endl;
    ofs.close();
}

const int & SessionState::recoverTrackNumber() {
    std::string line;
    bool found = false;
    try {
        std::ifstream ifs("session_state.txt");
        /*if (!ifs.is_open()) {
            std::cerr << "Unable to open file for reading" << std::endl;
            return stationNumber;
        }*/

        while (std::getline(ifs, line)) {
            if (line == "LOCAL_MUSIC") {
                found = true;
                continue;
            }
            if (found) {
                trackNumber = std::stoi(line);
                break;
            }
        }

        ifs.close();

    } catch (std::ofstream::failure& e) {
        trackNumber = 0;
        return trackNumber;
    }

    return trackNumber;

}

const std::string & SessionState::recoverCurrentSongTime() {
    std::string line;
    bool found = false;
    try {
        std::ifstream ifs("session_state.txt");

        while (std::getline(ifs, line)) {
            if (line == "TIME") {
                found = true;
                continue;
            }
            if (found) {
                currentSongTime = line;
                break;
            }
        }

        ifs.close();

    } catch (std::ofstream::failure& e) {
        currentSongTime = "";
        return currentSongTime;
    }

    return currentSongTime;
}

const int & SessionState::recoverStationNumber() {
    std::string line;
    bool found = false;
    try {
        std::ifstream ifs("session_state.txt");

        while (std::getline(ifs, line)) {
            if (line == "INTERNET_RADIO") {
                found = true;
                continue;
            }

            if (found) {
                stationNumber = std::stoi(line);
                break;
            }
        }

        ifs.close();
    } catch (std::ifstream::failure& e) {
        stationNumber = 0;
        return stationNumber;
    }
    return stationNumber;
}

SourceType SessionState::recoverSourceType() {
    std::string line;
    bool found = false;
    try {
        std::ifstream ifs("session_state.txt");

        while (std::getline(ifs, line)) {
            if (line == "SOURCE") {
                found = true;
                continue;

            }
            if (found) {
                if (std::stoi(line) == 0) {
                    sourceType = LOCAL_MUSIC;
                    break;
                }else if (std::stoi(line) == 1) {
                    sourceType = INTERNET_RADIO;
                    break;
                }
            }
        }

        ifs.ignore();
        ifs.close();
    } catch (std::ifstream::failure& e) {
        sourceType = LOCAL_MUSIC;
        return sourceType;
    }
    return sourceType;
}
