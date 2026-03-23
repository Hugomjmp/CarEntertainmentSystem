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
    std::vector<Song> Songs;
public:
    Playlist(const std::string& name) : PlaylistName(name) {}
    ~Playlist() = default;
    bool addSong(Song song);
    bool removeSong(int index);
    std::string getPlaylistName() const;
    const std::vector<Song>& getPlaylist();
};


#endif //CARENTERTAINMENTSYSTEM_PLAYLIST_H