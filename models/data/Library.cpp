//
// Created by Hugo on 19/03/2026.
//

#include "Library.h"

#include <filesystem>
#include <iostream>

#include "../../Settings/Folders.h"

Library::Library() {
}


Library::~Library() {
    for (int i = 0; i < playList.size(); i++) {
        delete playList.at(i);
    }
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

bool Library::editPlaylist(std::string playListName) {
    for (int i = 0; i < playList.size(); i++) {
        if (playList.at(i)->getPlaylistName() == playListName) {
            playList.at(i)->setPlaylistName(playListName);
            return true;
        }
    }
    return false;
}

bool Library::deletePlaylist(std::string playListName) {
    for (int i = 0; i < playList.size(); i++) {
        if (playList.at(i)->getPlaylistName() == playListName) {
            Playlist *p = playList.at(i);
            playList.erase(playList.begin() + i);
            delete p;
            return true;
        }
    }
    return false;
}

const Song & Library::getSong(int songNumber) const {
    return allSongs.at(songNumber);
}

Playlist & Library::getPlaylist(std::string playerListName) const {
    for (int i = 0; i < playList.size(); i++) {
        if (playList.at(i)->getPlaylistName() == playerListName) {
            return *playList.at(i);
        }
    }
}

const std::vector<Playlist*> & Library::getAllPlaylists() const {
    return playList;
}

std::ostream& operator<<(std::ostream &os, const std::vector<Song*> &songs) {
    for (int i = 0; i < songs.size(); i++) {
        os << songs.at(i)->getTitle() << " "
            << songs.at(i)->getAlbum() << " "
            << songs.at(i)->getYear() << " "
            << songs.at(i)->getNumber() << " "
            << songs.at(i)->getGenre() << " "
            << songs.at(i)->getLocation() << " "
            << songs.at(i)->getDuration() <<
            std::endl;
    }
    return os;
}

std::ostream & operator<<(std::ostream &os, const std::vector<Playlist*> &list) {
    for (int i = 0; i < list.size(); i++) {
        os << list.at(i)->getPlaylistName()
            << "\n"
            << list.at(i)->getPlaySongs() << std::endl;
    }
    return os;
}
