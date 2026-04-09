//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FACADE_H
#define CARENTERTAINMENTSYSTEM_FACADE_H
#include "MakeFolder.h"
#include "MusicPlayer.h"
#include "data/Library.h"
#include "data/Media.h"


class Facade {
private:
    MakeFolder *make_Folder = nullptr;
    Library *library = nullptr;
    MusicPlayer *music_Player = nullptr;
    Media *media = nullptr;
    bool isPlaying = false;
public:
    Facade();
    ~Facade();
    void play();
    void pause();
    void nextSong();
    void previousSong();
    double getVolume() const;
    void setVolume(double volume);
    const Song & getSong() const;
    void setMute();
};



#endif //CARENTERTAINMENTSYSTEM_FACADE_H
