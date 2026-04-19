//
// Created by Hugo on 08/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MEDIA_H
#define CARENTERTAINMENTSYSTEM_MEDIA_H
#include "Library.h"


class Media {
private:
    Library &library;
    int track = 0;
    int getPlaylistSize() const;
public:
    Media(Library &library) : library(library){}
    ~Media() = default;
    std::string getSongFromPlaylist() const;
    const Song* getSongData() const;
    void setTrack(int newTrackNumber);
    void nextSong();
    void previousSong();
    const int& getTrack() const;

};



#endif //CARENTERTAINMENTSYSTEM_MEDIA_H
