//
// Created by Hugo on 19/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MUSICPLAYER_H
#define CARENTERTAINMENTSYSTEM_MUSICPLAYER_H
#include "data/Library.h"
#include "SFML/Audio/Music.hpp"

/**
 * Class responsible to play the music.
 */
class MusicPlayer {
private:
    Library &library;
    sf::Music music;
public:

    MusicPlayer(Library &lib) : library(lib) {}
    ~MusicPlayer() = default;

    bool playSong(const Song &song);
    bool stopSong();
    void pauseSong();
    bool setVolume(float volume);
    float getVolume() const;
    void setMute(bool mute);
    void setLoop();
    sf::Time getCurrentSongTime() const;
    void playPlaylist(const Playlist &playlist);
};


#endif //CARENTERTAINMENTSYSTEM_MUSICPLAYER_H