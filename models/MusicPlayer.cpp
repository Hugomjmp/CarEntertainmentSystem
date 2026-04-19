//
// Created by Hugo on 19/03/2026.
//

#include "MusicPlayer.h"

#include <iostream>
#include <QDebug>
//#include "SFML/System/Sleep.hpp"
MusicPlayer::MusicPlayer() {
    player = new QMediaPlayer;
    audio = new QAudioOutput;
    player->setAudioOutput(audio);

    QObject::connect(player, &QMediaPlayer::positionChanged, this, &MusicPlayer::positionChanged);
    QObject::connect(player, &QMediaPlayer::durationChanged, this, &MusicPlayer::durationChanged);
}

MusicPlayer::~MusicPlayer() {
    delete audio;
    delete player;
}

/**
 *
 * @param song Object that represents the song.
 * @return false if it can't find the song, true if it can.
 */
bool MusicPlayer::playSong(const Song &song) {
    if (player->playbackState() == QMediaPlayer::PlayingState)
        player->stop();

    player->setSource(QUrl::fromLocalFile(QString::fromStdString(song.getLocation())));

    if (player->error() != QMediaPlayer::NoError)
        return false;

    player->play();

    return true;
}

/**
 *
 * @param station Object that represents the radio station.
 * @return false if it can't play the station, true if it can.
 */
bool MusicPlayer::playRadio(const Station &station) {
    if (player->playbackState() == QMediaPlayer::PlayingState)
        player->stop();

    player->setSource(QUrl::fromLocalFile(QString::fromStdString(station.getUrl())));

    if (player->error() != QMediaPlayer::NoError)
        return false;
    player->play();

    return true;
}

/**
 * Stopes the current music.
 * Returns true if it's currently playing a song.
 */
bool MusicPlayer::stopSong() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->stop();
        return true;
    }
    return false;
}

/**
 * Pauses the music if it's playing songs. Play's if it's paused.
 */
void MusicPlayer::pauseSong() {
    if (player->playbackState() == QMediaPlayer::PausedState) {
        player->play();
    } else {
        player->pause();
    }
}

/**
 *
 * @param volume Value to change the volume at
 * @return true if it was able to change the vale or false if it couldn't
 */
bool MusicPlayer::setVolume(float volume) {
    if (volume >= 0.0f && volume <= 100.0f) {
        audio->setVolume(volume);
        return true;
    }
    /*if (volume >= 0.0f && volume <= 100.0f) {
        music.setVolume(volume);
        return true;
    }*/
    return false;
}

/**
 *
 * @return returns the volume of the sound.
 */
float MusicPlayer::getVolume() {
    return audio->volume();
    //return music.getVolume();
}

void MusicPlayer::setMute() {
    float initialVolume = audio->volume();
    if (mute == false) {
        audio->setVolume(0.0f);
        mute = true;
    } else {
        audio->setVolume(initialVolume);
        mute = false;
    }
}

/**
 *
 * @return The current play time.
 */
std::string MusicPlayer::getCurrentSongTime() const{
    return std::to_string(player->position());
}

/**
 *
 * @return The total song time.
 */
std::string MusicPlayer::getSongDuration() const {
    return std::to_string(player->duration());
}
