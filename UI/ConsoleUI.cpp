//
// Created by Hugo on 19/03/2026.
//

#include "ConsoleUI.h"

#include <iostream>

ConsoleUI::ConsoleUI() {
}

void ConsoleUI::showMainMenu() const{
    std::cout << "+-----------------------+" << std::endl;
    std::cout << "|          MENU         |" << std::endl;
    std::cout << "+-----------------------+" << std::endl;
    std::cout << "| 1 - show music        |" << std::endl;
    std::cout << "| 2 - play song         |" << std::endl;
    std::cout << "| 3 - set volume        |" << std::endl;
    std::cout << "| 4 - pause music       |" << std::endl;
    std::cout << "| 5 - stop music        |" << std::endl;
    std::cout << "| 6 - Get Song Time     |" << std::endl;
    std::cout << "| 7 - library Settings  |" << std::endl;
    std::cout << "| 8 - Loop Current Song |" << std::endl;
    std::cout << "| 9 - Playlist Settings |" << std::endl;
    std::cout << "| 10 - Play Playlist    |" << std::endl;
    std::cout << "| 11 - exit program     |" << std::endl;
    std::cout << "+-----------------------+" << std::endl;
    std::cout << "#> ";
}

void ConsoleUI::showLibraryMenu() const {
    std::cout << "+-------------------------+" << std::endl;
    std::cout << "|         LIBRARY         |" << std::endl;
    std::cout << "+-------------------------+" << std::endl;
    std::cout << "| 1 - Show all music      |" << std::endl;
    std::cout << "| 2 - Create new Playlist |" << std::endl;
    std::cout << "| 3 - Edit playlist       |" << std::endl;
    std::cout << "| 4 - Delete Playlist     |" << std::endl;
    std::cout << "| 5 - Show all playlist's |" << std::endl;
    std::cout << "| 6 - Show playlist info  |" << std::endl;
    std::cout << "| 7 - Save Playlists      |" << std::endl;
    std::cout << "| 8 - Load playlists      |" << std::endl;
    std::cout << "| 9 - Back                |" << std::endl;
    std::cout << "+-------------------------+" << std::endl;
    std::cout << "#> ";
}
void ConsoleUI::showPlayListMenu(const std::string & playListName) const {

    std::cout <<  playListName  << std::endl;
    std::cout << "+------------------------+" << std::endl;
    std::cout << "| 1 - Add Song           |" << std::endl;
    std::cout << "| 2 - Remove Song        |" << std::endl;
    std::cout << "| 3 - List Songs         |" << std::endl;
    std::cout << "| 4 -                    |" << std::endl;
    std::cout << "| 5 -                    |" << std::endl;
    std::cout << "| 6 - back               |" << std::endl;
    std::cout << "+------------------------+" << std::endl;
    std::cout << "#> ";
}