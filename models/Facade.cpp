//
// Created by Hugo on 07/04/2026.
//

#include "Facade.h"

#include <iostream>

Facade::Facade() {
    make_Folder = new MakeFolder();
    library = new Library();
    music_Player = new MusicPlayer(*library);
    make_Folder->checkFolder();

    //makeFolder.checkFolder();
}

Facade::~Facade() {
    delete make_Folder;
    delete library;
    delete music_Player;
}

void Facade::play() {
    std::cout << "Facade play" << std::endl;
    std::cout << library->getSong(5);
    music_Player->playSong(library->getSong(5));
}
