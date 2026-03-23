
#ifndef CARENTERTAINMENTSYSTEM_LIBRARY_H
#define CARENTERTAINMENTSYSTEM_LIBRARY_H
#include <vector>

#include "Playlist.h"
#include "Song.h"


class Library {
private:
    std::vector<Song> allSongs;
    std::vector<Playlist*> playList;
public:
    Library();
    ~Library();
    void scanMusicFolder();
    std::vector<Song>& getAllSongs();
    bool createPlaylist(std::string playerListName);
    void editPlaylist(std::string playerListName);
    void deletePlaylist(std::string playerListName);
    Playlist& getPlaylist(std::string playerListName) const;
    const std::vector<Playlist*> & getAllPlaylists() const;
};

    std::ostream& operator<<(std::ostream &os, const std::vector<Playlist*> &playlist);

#endif //CARENTERTAINMENTSYSTEM_LIBRARY_H