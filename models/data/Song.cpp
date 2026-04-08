//
// Created by Hugo on 19/03/2026.
//

#include "Song.h"

#include <ostream>

std::string Song::getTitle() const {
    return title;
}

std::string Song::getAlbum() const {
    return album;
}

std::string Song::getArtist() const {
    return artist;
}

int Song::getYear() const {
    return year;
}

int Song::getNumber() const {
    return number;
}

std::string Song::getGenre() const {
    return genre;
}

int Song::getDuration() const {
    return duration;
}

std::string Song::getLocation() const {
    return location;
}

std::ostream & operator<<(std::ostream &os, const Song &song) {
    os << song.getTitle() << ";"
        << song.getAlbum() << ";"
        << song.getArtist() << ";"
        << song.getYear() << ";"
        << song.getNumber() << ";"
        << song.getGenre() << ";"
        << song.getDuration() << ";"
        << song.getLocation() <<
        std::endl;
    return os;
}

