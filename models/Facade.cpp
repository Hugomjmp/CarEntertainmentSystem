//
// Created by Hugo on 07/04/2026.
//

#include "Facade.h"

#include <iostream>

Facade::Facade() {
    make_Folder = new MakeFolder();
    library = new Library();
    music_Player = new MusicPlayer(/**library*/);
    make_Folder->checkFolder();
    media = new Media(*library);

    connect(music_Player, &MusicPlayer::positionChanged,
        this, &Facade::positionChanged);
    connect(music_Player, &MusicPlayer::durationChanged,
        this, &Facade::durationChanged);
}

Facade::~Facade() {
    delete make_Folder;
    delete library;
    delete music_Player;
}

void Facade::play() {
    music_Player->playSong(*media->getSongData());
    isPlaying = true;
}

void Facade::pause() {
    music_Player->pauseSong();
    isPlaying = false;
}

void Facade::nextSong() {
    media->nextSong();
    isPlaying = true;
    music_Player->playSong(*media->getSongData());
}

void Facade::previousSong() {
    media->previousSong();
    isPlaying = true;
    music_Player->playSong(*media->getSongData());
}

const Song & Facade::getSong() const {
    return *media->getSongData();
}

double Facade::getVolume() const {
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
