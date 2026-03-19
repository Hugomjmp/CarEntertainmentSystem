
#ifndef CARENTERTAINMENTSYSTEM_LIBRARY_H
#define CARENTERTAINMENTSYSTEM_LIBRARY_H
#include <vector>

#include "Song.h"


class Library {
private:
    std::vector<Song> allSongs;
public:
    Library();
    ~Library() = default;
    void scanMusicFolder();
    std::vector<Song>& getAllSongs();
};


#endif //CARENTERTAINMENTSYSTEM_LIBRARY_H