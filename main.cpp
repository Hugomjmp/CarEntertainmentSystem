#include <iostream>

#include "models/MakeFolder.h"
#include "models/MusicPlayer.h"
#include "models/data/Library.h"
#include "UI/ConsoleUI.h"

int main() {
    int option = 0;
    int songNumber = 0;
    float volume = 100;

    MakeFolder mkFolder;
    mkFolder.checkFolder();
    ConsoleUI consoleUI;
    Library library;
    library.scanMusicFolder();
    MusicPlayer music_player;

    while (option != 7) {
        consoleUI.showMainMenu();
        std::cin >> option;
        switch (option) {
            case 1:
                for (int i = 0; i < library.getAllSongs().size(); i++) {
                    std::cout << i << " - " << library.getAllSongs().at(i).getTitle() << std::endl;
                }
                library.getAllSongs();
                break;
            case 2:
                std::cin >> songNumber;
                music_player.playSong(songNumber);
                break;
            case 3:
                std::cin >> volume;
                music_player.setVolume(volume);
                break;
            case 4:
                music_player.pauseSong();
                break;
            case 5:
                music_player.stopSong();
                break;
            case 6:
                std::cout << music_player.getCurrentSongTime().asSeconds() << std::endl;
                break;
        }
    }
    return 0;
}
