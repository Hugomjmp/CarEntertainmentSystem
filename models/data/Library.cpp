//
// Created by Hugo on 19/03/2026.
//

#include "Library.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>

#include "MetaData.h"
#include "../../Settings/Folders.h"

Library::Library() {
    scanMusicFolder();
    loadPlaylists();
}

Library::~Library() {
    for (int i = 0; i < playList.size(); i++) {
        delete playList.at(i);
    }
}

void Library::scanMusicFolder() {
    std::string title;
    for (const auto& file: std::filesystem::directory_iterator(Folder::musicFolder)) {

        title = file.path().string().erase(0,6);
        title.erase(title.size() - 4);
        Song song(title,"",0,0,"",0,file.path().string());
        allSongs.push_back(song);
    }
    /*std::cout << allSongs.at(9) << std::endl;
    std::ifstream ifs(allSongs.at(9).getLocation(), std::ios::binary);
    ifs.seekg(0, std::ios::beg);
    char header[10];
    ifs.read(header, 10);
    int versionMajor, versionMinor;
    versionMajor = header[3];
    versionMinor = header[4];
    std::cout << header[0]<<header[1]<<header[2] <<"v2." << versionMajor << "." << versionMinor << std::endl;
    int tagSize =
    ((header[6] & 0x7F) << 21) |
    ((header[7] & 0x7F) << 14) |
    ((header[8] & 0x7F) << 7)  |
    (header[9] & 0x7F);

    std::cout << "Tag size: " << tagSize << " bytes" << std::endl;*/
    MetaData::searchFile(allSongs.at(9).getLocation());
    //std::cout << "songTitle: " << MetaData::getTitle() << std::endl;
    /*char all[22269];
    ifs.read(all, 22269);
    std::cout.write(all, 22269);*/
    //std::cout << all << std::endl;

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

Playlist * Library::getPlaylist(std::string playerListName) const {
    for (int i = 0; i < playList.size(); i++) {
        if (playList.at(i)->getPlaylistName() == playerListName) {
            return playList.at(i);
        }
    }
    return nullptr;
}

const std::vector<Playlist*> & Library::getAllPlaylists() const {
    return playList;
}

void Library::savePlaylists() const{
    std::ofstream ofs("playlist.bin", std::ios::binary);
    if (!ofs.is_open()) {
        std::cerr << "Unable to save playlist " << std::endl;
        return;
    }

    ofs << playList.size() << std::endl;
    for (auto& p : playList) {
        ofs << p->getPlaylistName() << std::endl;
        ofs << p->getPlaySongs().size() << std::endl;
        for (auto& s : p->getPlaySongs()) {
            ofs << *s;
        }
    }
}

void Library::loadPlaylists() {
    std::cout << "Loading playlists..." << std::endl;
    std::string name, songLine, title, album, yearStr, songNumberStr, genre, durationStr, location;
    std::stringstream ss;
    int nSongs = 0, nPlaylists = 0, songNumber = 0, year = 0, duration = 0;

    std::ifstream ifs("playlist.bin");
    if (!ifs.is_open()) {
        std::cerr << "Unable to load playlist " << std::endl;
        return;
    }
    for (auto& p : playList) {
        delete p;
    }

    playList.clear();

    ifs >> nPlaylists;
    ifs.ignore();
    for (int i = 0; i < nPlaylists; i++) {
        std::getline(ifs, name);
        Playlist *p = new Playlist(name);
        ifs >> nSongs;
        ifs.ignore();
        for (int j = 0; j < nSongs; j++) {
            std::getline(ifs, songLine);
            ss << songLine << std::endl;

            std::getline(ss, title, ';');
            std::getline(ss, album, ';');
            std::getline(ss, yearStr, ';');
            std::getline(ss, songNumberStr, ';');
            std::getline(ss, genre, ';');
            std::getline(ss, durationStr, ';');
            std::getline(ss, location, '\n');

            year = std::stoi(yearStr);
            songNumber = std::stoi(songNumberStr);
            duration = std::stoi(durationStr);
            Song song(title, album, songNumber, year, genre, duration, location);
            p->addSong(song);
        }
        playList.push_back(p);
    }


    ifs.close();
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
