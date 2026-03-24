//
// Created by Hugo on 19/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_PLAYLIST_H
#define CARENTERTAINMENTSYSTEM_PLAYLIST_H
#include <vector>

#include "Song.h"


class Playlist {
private:
    std::string PlaylistName;
    std::vector<Song*> Songs;
public:
    Playlist(const std::string& name) : PlaylistName(name) {}
    ~Playlist() = default;
    bool addSong(const Song &song);
    bool removeSong(int index);
    std::string getPlaylistName() const;
    void setPlaylistName(const std::string& name);
    const std::vector<Song*>& getPlaySongs() const;
};


#endif //CARENTERTAINMENTSYSTEM_PLAYLIST_H