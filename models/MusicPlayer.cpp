//
// Created by Hugo on 19/03/2026.
//

#include "MusicPlayer.h"

#include <iostream>

#include "SFML/System/Sleep.hpp"

/**
 *
 * @param song Object that represents the song.
 * @return false if it can't find the song, true if it can.
 */
bool MusicPlayer::playSong(const Song &song) {
    if (music.getStatus() == sf::Music::Status::Playing)
        music.stop();

    /*if (!music.openFromFile(library.getAllSongs().at(songNumber).getLocation())) {
        return false;
    }*/
    if (!music.openFromFile(song.getLocation())) {
        return false;
    }

    music.play();
    return true;
}
/**
 * Stopes the current music.
 * Returns true if it's currently playing a song.
 */
bool MusicPlayer::stopSong() {
    if (music.getStatus() == sf::Music::Status::Playing) {
        music.stop();
        return true;
    }
    return false;
}

/**
 * Pauses the music if it's playing songs. Play's if it's paused.
 */
void MusicPlayer::pauseSong() {
    if (music.getStatus() == sf::Music::Status::Paused) {
        music.play();
    } else {
        music.pause();
    }
}

/**
 *
 * @param volume Value to change the volume at
 * @return true if it was able to change the vale or false if it couldn't
 */
bool MusicPlayer::setVolume(float volume) {
    if (volume >= 0.0f && volume <= 100.0f) {
        music.setVolume(volume);
        return true;
    }
    return false;
}

/**
 *
 * @return returns the volume of the sound.
 */
float MusicPlayer::getVolume() const {
    return music.getVolume();
}

void MusicPlayer::setMute(bool mute) {
    float initialVolume = music.getVolume();
    if (mute == true) {
        music.setVolume(0.0f);
    } else {
        music.setVolume(initialVolume);
    }
}

/**
 * Set's the current song in a loop.
 */
void MusicPlayer::setLoop() {
    if (music.isLooping() == false) {
        music.setLooping(true);
    } else {
        music.setLooping(false);
    }
}

/**
 *
 * @return The current play time.
 */
sf::Time MusicPlayer::getCurrentSongTime() const{
    return music.getPlayingOffset();
}

void MusicPlayer::playPlaylist(const Playlist &playlist){
    for (int i = 0; i < playlist.getPlaySongs().size(); i++) {

        playSong(*playlist.getPlaySongs().at(i));

        while (music.getStatus() == sf::Music::Status::Playing) {
            sf::sleep(sf::milliseconds(100));
        }
    }
}
