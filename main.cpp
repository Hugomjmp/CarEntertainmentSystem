#include <iostream>
#include <SFML/Audio.hpp>

#include "models/MakeFolder.h"
#include "models/data/Library.h"
#include "UI/ConsoleUI.h"

int main() {
    /*int option;
    ConsoleUI consoleUI;

    while (consoleUI.isProgramActive()) {
        consoleUI.showMenu();
        std::cin >> option;

    }*/
    MakeFolder mkFolder;
    mkFolder.checkFolder();
    Library library;
    library.scanMusicFolder();
    std::cout << "Playing music..." << std::endl;
    sf::Music music;
    for (int i = 0; i < library.getAllSongs().size(); i++) {
        std::cout << "Playing -> " << library.getAllSongs().at(i).getTitle() << std::endl;
        if (!music.openFromFile(library.getAllSongs().at(i).getLocation()))
            return -1;

        music.play();

        while (music.getStatus() == sf::Music::Status::Playing) {
            sf::sleep(sf::milliseconds(100));
        }
    }
    /*if (!music.openFromFile("music\\Alegend - In Flight (freetouse.com).mp3"))
        return -1; // error

    music.play();
    while (music.getStatus() == sf::Music::Status::Playing) {
        sf::sleep(sf::milliseconds(100));
    }*/
    std::cout << "Acabou" << std::endl;
    return 0;
}
