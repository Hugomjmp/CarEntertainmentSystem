#include <iostream>

#include "models/MakeFolder.h"
#include "models/MusicPlayer.h"
#include "models/data/Library.h"
#include "models/data/Playlist.h"
#include "UI/ConsoleUI.h"


void libraryMenu(const ConsoleUI& consoleUI, Library& library) {
    int option = 0;
    std::string playlistName;
    while (option != 7) {
        consoleUI.showLibraryMenu();
        std::cin >> option;
        switch (option) {
            case 1:
                for (int i = 0; i < library.getAllSongs().size(); i++) {
                    std::cout << i << " - " << library.getAllSongs().at(i).getTitle() << std::endl;
                }
            break;

            case 2: {
                std::cin.ignore();
                std:getline(std::cin, playlistName);
                library.createPlaylist(playlistName);
            }
            break;
            case 3: {
                library.editPlaylist(playlistName);
            }
            break;
            case 4: {
                library.deletePlaylist(playlistName);
            }
            break;
            case 5: {
                std::cout << library.getAllPlaylists();
            }
            break;
            case 6: {
                std::cin.ignore();
                std::getline(std::cin, playlistName);
                library.getPlaylist(playlistName);
            }
            break;
        }
    }
}

int main() {
    int option = 0;
    int songNumber = 0;
    float volume = 100;

    /* First create folders if there aren't any */
    MakeFolder mkFolder;
    mkFolder.checkFolder();

    ConsoleUI consoleUI;

    Library library;
    library.scanMusicFolder();

    MusicPlayer music_player;

    while (option != 8) {
        consoleUI.showMainMenu();
        std::cin >> option;
        switch (option) {
            case 1:
                for (int i = 0; i < library.getAllSongs().size(); i++) {
                    std::cout << i << " - " << library.getAllSongs().at(i).getTitle() << std::endl;
                }

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
            case 7:
                libraryMenu(consoleUI, library);
                break;
        }
    }
    return 0;
}
