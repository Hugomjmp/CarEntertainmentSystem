//
// Created by Hugo on 07/04/2026.
//

#include "Facade.h"

#include <iostream>

#include "data/fm_radio/FMRadio.h"

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
    connect(music_Player, &MusicPlayer::mediaEnded,
        this, &Facade::mediaEnded);
    setSourceType(session.recoverSourceType());

    music_Player->setCurrentSongTime(session.recoverCurrentSongTime());
    play();
    FMRadio fm_radio(*gpio);
    fm_radio.playStation(gpio->getHandle(),90.0);
}

Facade::~Facade() {
    delete gpio;
    delete make_Folder;
    delete library;
    delete onlineRadio;
    delete music_Player;
    session.saveSessionState(media->getTrack(),getSongCurrentTime(),internetRadio->getStationNumber(),getSourceType());
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
    //music_Player->setCurrentSongTime("0");
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

void Facade::loopSong() const {
    music_Player->setLoop();
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

void Facade::setVolume(const double volume) const {
    music_Player->setVolume(volume);
}

void Facade::setMute() const {
    music_Player->setMute();
}

std::string Facade::getSongDuration() const {
    return music_Player->getSongDuration();
}

const std::string Facade::getSongCurrentTime() {
    if (sourceType == LOCAL_MUSIC) {
        return music_Player->getCurrentSongTime();
    }
    return session.recoverCurrentSongTime();

}

MusicPlayer * Facade::getMusicPlayer() const {
    return music_Player;
}

const std::vector<Song> & Facade::getSongs() const {
    return library->getAllSongs();
}

void Facade::setTrack(const int newTrackNumber) const {
    media->setTrack(newTrackNumber);
}

void Facade::setStation(const int newStationNumber) const {
    internetRadio->setStationNumber(newStationNumber);
}

void Facade::mediaEnded(QMediaPlayer::MediaStatus status) {
    if (sourceType == LOCAL_MUSIC) {
        if (status == QMediaPlayer::EndOfMedia && music_Player->isLooping() == 1) {
            nextSong();
        }
    }
}
