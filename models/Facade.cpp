//
// Created by Hugo on 07/04/2026.
//

#include "Facade.h"

#include <iostream>

Facade::Facade() {
    gpio = new GPIO();
    make_Folder = new MakeFolder();
    library = new Library();
    onlineRadio = new OnlineRadioLibrary();
    music_Player = new MusicPlayer(/**library*/);
    make_Folder->checkFolder();
    media = new Media(*library);
    media->setTrack(session.recoverTrackNumber());
    internetRadio = new InternetRadio(*onlineRadio);
    internetRadio->setStationNumber(session.recoverStationNumber());

    connect(music_Player, &MusicPlayer::positionChanged,
        this, &Facade::positionChanged);
    connect(music_Player, &MusicPlayer::durationChanged,
        this, &Facade::durationChanged);
    setSourceType(LOCAL_MUSIC); //to remove later
}

Facade::~Facade() {
    delete gpio;
    delete make_Folder;
    delete library;
    delete onlineRadio;
    delete music_Player;
    session.saveSessionState(media->getTrack(),internetRadio->getStationNumber());
    delete media;
    delete internetRadio;
}

GPIO * Facade::getGPIO() const {
    return gpio;
}

void Facade::setSourceType(SourceType newSourceType) {
    sourceType = newSourceType;
}

const SourceType & Facade::getSourceType() const {
    return sourceType;
}

bool Facade::getPlayStatus() const {
    return isPlaying;
}

void Facade::play() {
    switch (sourceType) {
        case LOCAL_MUSIC: {
            music_Player->playSong(*media->getSongData());
            isPlaying = true;
        }
            break;
        case INTERNET_RADIO: {
            music_Player->playRadio(*internetRadio->getStation());
            isPlaying = true;
        }
            break;
    }
    emit sourceTypeChanged();
}

void Facade::pause() {
    switch (sourceType) {
        case LOCAL_MUSIC: {
            music_Player->pauseSong();
            isPlaying = false;
        }
            break;
        case INTERNET_RADIO: {
            music_Player->stopSong();
            isPlaying = false;
        }
            break;
    }

}

void Facade::nextSong() {
    switch (sourceType) {
        case LOCAL_MUSIC: {
            media->nextSong();
            isPlaying = true;
            music_Player->playSong(*media->getSongData());
        }
            break;
        case INTERNET_RADIO: {
            internetRadio->nextStation();
            isPlaying = true;
            music_Player->playRadio(*internetRadio->getStation());
        }
            break;
    }
}

void Facade::previousSong() {
    switch (sourceType) {
        case LOCAL_MUSIC: {
            media->previousSong();
            isPlaying = true;
            music_Player->playSong(*media->getSongData());
        }
            break;
        case INTERNET_RADIO: {
            internetRadio->previousStation();
            isPlaying = true;
            music_Player->playRadio(*internetRadio->getStation());
        }
            break;
    }

}

const Song & Facade::getSong() const {
    return *media->getSongData();
}

const Station & Facade::getStation() const {
    return *internetRadio->getStation();
}

const std::vector<Station> & Facade::getStations() const {
    return onlineRadio->getStationLibrary();
}

float Facade::getVolume() const {
    return music_Player->getVolume();
}

void Facade::setVolume(double volume) {
    music_Player->setVolume(volume);
}

void Facade::setMute() {
    music_Player->setMute();
}

std::string Facade::getSongDuration() const {
    return music_Player->getSongDuration();
}

std::string Facade::getSongCurrentTime() const {
    return music_Player->getCurrentSongTime();
}

MusicPlayer * Facade::getMusicPlayer() const {
    return music_Player;
}

const std::vector<Song> & Facade::getSongs() const {
    return library->getAllSongs();
}

void Facade::setTrack(int newTrackNumber) {
    media->setTrack(newTrackNumber);
}

void Facade::setStation(int newStationNumber) {
    internetRadio->setStationNumber(newStationNumber);
}
