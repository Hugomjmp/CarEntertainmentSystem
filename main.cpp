#include <iostream>

#include "models/MakeFolder.h"
#include "models/MusicPlayer.h"
#include "models/data/Library.h"
#include "models/data/Playlist.h"
#include "Settings/Settings.h"
#include "UI/ConsoleUI.h"


/* METODOS APENAS PARA TESTE DE IMPLEMENTAÇÃO */
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
void playlistMenu(const ConsoleUI& consoleUI, Library& library, const std::string playlistName) {
    int option = 0;

    int songNumber = 0;
    Playlist * p = nullptr;

    /* TODO
     * fazer verificação para o caso que não exista essa playlist...
     */

    while (option != 6) {
        for (int i = 0; i < library.getAllPlaylists().size(); i++) {
            if (library.getPlaylist(playlistName).getPlaylistName() == playlistName) {
                consoleUI.showPlayListMenu(playlistName);
                p = &library.getPlaylist(playlistName);
                break;
            }
        }

        std::cin.ignore();
        std::cin >> option;
        switch (option) {
            case 1:
                for (int i = 0; i < library.getAllSongs().size(); i++) {
                    std::cout << i << " - " << library.getAllSongs().at(i).getTitle() << std::endl;
                }
                std::cin.ignore();
                std::cin >> songNumber;
                p->addSong(library.getSong(songNumber));
                break;
            case 2:
                for (int i = 0; i < p->getPlaySongs().size(); i++) {
                    std::cout << i << " - " << p->getPlaySongs().at(i)->getTitle() << std::endl;
                }
                std::cin.ignore();
                std::cin >> songNumber;
                p->removeSong(songNumber);
                break;
            case 3:
                for (int i = 0; i < p->getPlaySongs().size(); i++) {
                    std::cout << i << " " << p->getPlaySongs().at(i)->getTitle() << std::endl;
                }
                break;
        }
    }

}
int main() {
    int option = 0;
    int songNumber = 0;
    float volume = 100;
    std::string playlistName;
    /* First create folders if there aren't any */
    MakeFolder mkFolder;
    mkFolder.checkFolder();
    Settings setting;

    ConsoleUI consoleUI;

    Library library;

    MusicPlayer music_player(library);

    while (option != 10) {
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
                music_player.playSong(library.getSong(songNumber));
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
            case 8:
                music_player.setLoop();
                break;
            case 9:
                std::cin.ignore();
                std::cin >> playlistName;
                playlistMenu(consoleUI, library, playlistName);
                break;
        }
    }
    return 0;
}
