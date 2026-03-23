//
// Created by Hugo on 19/03/2026.
//

#include "Library.h"

#include <filesystem>
#include <iostream>

#include "../../Settings/Folders.h"

Library::Library() {
}

/* TODO */
Library::~Library() {

}

void Library::scanMusicFolder() {
    for (const auto& file: std::filesystem::directory_iterator(Folder::musicFolder)) {
        //std::cout << file.path().string() << std::endl;
        Song song(file.path().string().erase(0,6),"",0,0,"",0,file.path().string());
        allSongs.push_back(song);
    }
}

std::vector<Song>& Library::getAllSongs() {
    return allSongs;
}

bool Library::createPlaylist(std::string playerListName) {
    for (int i = 0; i < playList.size(); i++) {
        if (playList.at(i)->getPlaylistName() == playerListName) {
            return false;
        }
    }
    playList.push_back(new Playlist(playerListName));
    return true;
}

void Library::editPlaylist(std::string playerListName) {
}

void Library::deletePlaylist(std::string playerListName) {
}

Playlist & Library::getPlaylist(std::string playerListName) const {
}

const std::vector<Playlist*> & Library::getAllPlaylists() const {
    return playList;
}

std::ostream & operator<<(std::ostream &os, const std::vector<Playlist*> &list) {
    for (int i = 0; i < list.size(); i++) {
        os << list.at(i)->getPlaylistName() << std::endl;
    }
    return os;
}
