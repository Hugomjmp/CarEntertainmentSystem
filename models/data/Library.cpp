//
// Created by Hugo on 19/03/2026.
//

#include "Library.h"

#include <filesystem>
#include <iostream>

#include "../../Settings/Folders.h"

Library::Library() {
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
