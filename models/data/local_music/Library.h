
#ifndef CARENTERTAINMENTSYSTEM_LIBRARY_H
#define CARENTERTAINMENTSYSTEM_LIBRARY_H
#include <vector>

#include "../playlist/Playlist.h"
#include "Song.h"
//#include "taglib/fileref.h"

class Library {
private:
    std::vector<Song> allSongs;
    std::vector<Playlist*> playList;
    void scanMusicFolder();
public:
    Library();
    ~Library();
    std::vector<Song>& getAllSongs();
    bool createPlaylist(std::string playerListName);
    bool editPlaylist(std::string playerListName);
    bool deletePlaylist(std::string playerListName);
    const Song& getSong(int songNumber) const;
    Playlist* getPlaylist(std::string playerListName) const;
    const std::vector<Playlist*> & getAllPlaylists() const;
    void savePlaylists() const;
    void loadPlaylists();
};
    std::ostream& operator<<(std::ostream & os, const std::vector<Song*> & songs);
    std::ostream& operator<<(std::ostream &os, const std::vector<Playlist*> &playlist);

#endif //CARENTERTAINMENTSYSTEM_LIBRARY_H