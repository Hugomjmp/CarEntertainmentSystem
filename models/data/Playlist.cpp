//
// Created by Hugo on 19/03/2026.
//

#include "Playlist.h"

/* TODO */
/* falta verificações */
bool Playlist::addSong(Song song) {
    /*for (int i = 0; i < Songs.size(); i++) {
        if ()
    }*/
    Songs.push_back(song);
    return true;
}

bool Playlist::removeSong(int index) {
    return false;
}

const std::vector<Song> & Playlist::getPlaylist() {
    return Songs;
}

std::string Playlist::getPlaylistName() const {
    return PlaylistName;
}
