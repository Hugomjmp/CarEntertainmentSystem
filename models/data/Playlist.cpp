//
// Created by Hugo on 19/03/2026.
//

#include "Playlist.h"

/* TODO */
/* falta verificações */
bool Playlist::addSong(const Song &song) {
    /*for (int i = 0; i < Songs.size(); i++) {
        if ()
    }*/
    Songs.push_back(new Song(song));
    return true;
}

bool Playlist::removeSong(int index) {
    Songs.erase(Songs.begin() + index);
    return false;
}

void Playlist::setPlaylistName(const std::string &name) {
    PlaylistName = name;
}

const std::vector<Song*> & Playlist::getPlaySongs() const{
    return Songs;
}

std::string Playlist::getPlaylistName() const {
    return PlaylistName;
}
