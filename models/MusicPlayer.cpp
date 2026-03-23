//
// Created by Hugo on 19/03/2026.
//

#include "MusicPlayer.h"


MusicPlayer::MusicPlayer() {
    library.scanMusicFolder();
}

/**
 *
 * @param songNumber Song number to be played
 * @return false if it can't find the song, true if it can.
 */
bool MusicPlayer::playSong(int songNumber) {
    if (music.getStatus() == sf::Music::Status::Playing)
        music.stop();

    if (!music.openFromFile(library.getAllSongs().at(songNumber).getLocation())) {
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

void MusicPlayer::setMute(bool mute) {
    float initialVolume = music.getVolume();
    if (mute == true) {
        music.setVolume(0.0f);
    } else {
        music.setVolume(initialVolume);
    }
}

/**
 *
 */
void MusicPlayer::setLoop() {
    if (music.isLooping() == false) {
        music.setLooping(true);
    } else {
        music.setLooping(false);
    }
}

sf::Time MusicPlayer::getCurrentSongTime() {
    return music.getPlayingOffset();
}
