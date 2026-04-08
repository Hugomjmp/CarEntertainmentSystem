//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FACADE_H
#define CARENTERTAINMENTSYSTEM_FACADE_H
#include "MakeFolder.h"
#include "MusicPlayer.h"
#include "data/Library.h"


class Facade {
private:
    MakeFolder *make_Folder = nullptr;
    Library *library = nullptr;
    MusicPlayer *music_Player = nullptr;
public:
    Facade();
    ~Facade();
    void play();
    void pause();
    void nextSong();
    void previousSong();
    void savePlaylist();
    const Song & getSong() const;

};



#endif //CARENTERTAINMENTSYSTEM_FACADE_H
