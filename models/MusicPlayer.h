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
    int currentSong = 0;
    bool playlistLoop = false;
    bool mute = false;
public:

    MusicPlayer(Library &lib) : library(lib) {}
    ~MusicPlayer() = default;

    bool playSong(const Song &song);
    bool stopSong();
    void pauseSong();
    bool setVolume(float volume);
    float getVolume() const;
    void setMute();
    void setLoop();
    sf::Time getCurrentSongTime() const;
    void playPlaylist(const Playlist &playlist);
    void setPlaylistLoop();
    void nextSong(const Playlist &playlist);
    void previousSong(const Playlist &playlist);
};


#endif //CARENTERTAINMENTSYSTEM_MUSICPLAYER_H