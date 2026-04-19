//
// Created by Hugo on 08/04/2026.
//

#include "Media.h"

std::string Media::getSongFromPlaylist() const {
    if (track >= 0 && track < getPlaylistSize()) {
        return library.getSong(track).getLocation();
    }
    return nullptr;
}

const Song * Media::getSongData() const {
    if (&library.getAllSongs().at(track) != nullptr) {
        return &library.getAllSongs().at(track);
    }
    return nullptr;
}

int Media::getPlaylistSize() const {
    return library.getAllSongs().size();
}

void Media::nextSong() {
    if (track >= getPlaylistSize() - 1) {
        track = 0;
        return;
    }
    track++;
}

void Media::previousSong() {
    if (track <= 0) {
        track = getPlaylistSize() - 1;
        return;
    }
    track--;
}

void Media::setTrack(int newTrackNumber) {
    track = newTrackNumber;
}

const int & Media::getTrack() const {
    return track;
}
