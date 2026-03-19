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
    os << song.title << " "
        << song.album << " "
        << song.year << " "
        << song.number << " "
        << song.genre << " "
        << song.duration << " "
        << song.location <<
        std::endl;
    return os;
}

