//
// Created by Hugo on 07/04/2026.
//

#include "MetaData.h"

#include <fstream>
#include <iostream>
#include <ostream>
std::string MetaData::file;
std::string MetaData::title;
std::string MetaData::artist;
std::string MetaData::album;
int MetaData::year;
int MetaData::number;
std::string MetaData::genre;
int MetaData::duration;

MetaData::MetaData() {
}

/**
 *
 * @param newFileSearch location of the file to extract metadata.
 */
void MetaData::searchFile(std::string newFileSearch) {
    char header[10];
    int metaDataSize = 0;



    file = newFileSearch;

    std::ifstream ifs(file, std::ios::binary);
    ifs.seekg(0, std::ios::beg);
    ifs.read(header, 10);
    int versionMajor, versionMinor;
    versionMajor = header[3];
    versionMinor = header[4];

    metaDataSize =
        ((header[6] & 0x7F) << 21) |
        ((header[7] & 0x7F) << 14) |
        ((header[8] & 0x7F) << 7) |
        (header[9] & 0x7F);

    switch (versionMajor) {
        case 3:
            ID3v2_30(ifs, metaDataSize);
            break;
        case 4:
            ID3v2_40(ifs,metaDataSize);
            break;
    }
    ifs.close();
}

/**
 *
 * @return Title of the song from the mp3 file.
 */
std::string MetaData::getTitle() {
    return title;
}

/**
 *
 * @return Album of the song from the mp3 file.
 */
std::string MetaData::getAlbum() {
    return album;
}

/**
 *
 * @return Year of the song from the mp3 file.
 */
int MetaData::getYear() {
    return year;
}

/**
 *
 * @return Number of the song from the mp3 file.
 */
int MetaData::getNumber() {
    return number;
}

/**
 *
 * @return Genre of the song from the mp3 file.
 */
std::string MetaData::getGenre() {
    return genre;
}

/**
 *
 * @return Duration of the song from the mp3 file.
 */
int MetaData::getDuration() {
    return duration;
}

/**
 *
 * @return Artist of the song from the mp3 file.
 */
std::string MetaData::getArtist() {
    return artist;
}

/**
 * Used for the ID3v2.3.0 version.
 * @param ifs The file to search from.
 * @param metaDataSize The size of the metadata.
 */
void MetaData::ID3v2_30(std::ifstream &ifs, const int& metaDataSize) {
    char frameHeader[10];
    int frameSize = 0, genreCode = 0;
    std::string data, frameID;
    const char* genreList[80] = {
        "Blues" , "Classic Rock", "Country", "Dance", "Disco",
        "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age",
        "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae", "Rock",
        "Techno", "Industrial", "Alternative", "Ska", "Death Metal",
        "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop",
        "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical", "Instrumental",
        "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise", "AlternRock",
        "Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop",
        "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial",
        "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock",
        "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk",
        "Jungle", "Native American", "Cabaret", "New Wave", "Psychadelic",
        "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk",
        "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock"
    };

    std::streampos tagEnd = 10 + metaDataSize;
    title = "";
    artist = "";
    album = "";
    genre = "";
    year = 0;
    number = 0;
    while (ifs.tellg() < tagEnd) {

        ifs.read(frameHeader, 10);
        frameID.assign(frameHeader,4);
        if (frameHeader[0] == 0)
            break;

        frameSize =
            (unsigned char)frameHeader[4] << 24 |
            (unsigned char)frameHeader[5] << 16 |
            (unsigned char)frameHeader[6] << 8  |
            (unsigned char)frameHeader[7];


        char* frameData = new char[metaDataSize];

        ifs.read(frameData, frameSize);

        if (frameSize > 1) {
            data.assign(frameData + 1,frameSize - 1);
        }

        if (frameID == "TIT2") {
            title = data;
        } else if (frameID == "TPE1") {
            artist = data;
        } else if (frameID == "TALB") {
            album = data;
        } else if (frameID == "TYER") {
            year = atoi(data.c_str());
        } else if (frameID == "TRCK") {
            number = atoi(data.c_str());
        } else if (frameID == "TCON") {
            genreCode = atoi(data.substr(1, genre.size() - 2).c_str());
            genre = genreList[genreCode];
        } else if (frameID == "APIC") {
            /*TODO*/
        }
        delete [] frameData;
    }
}

/**
 * Used for the ID3v2.4.0 version.
 * @param ifs The file to search from.
 * @param metaDataSize The size of the metadata.
 */
void MetaData::ID3v2_40(std::ifstream &ifs, const int& metaDataSize) {
    char frameHeader[10];
    int frameSize = 0, genreCode = 0;
    std::string data, frameID;
    const char* genreList[80] = {
        "Blues" , "Classic Rock", "Country", "Dance", "Disco",
        "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age",
        "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae", "Rock",
        "Techno", "Industrial", "Alternative", "Ska", "Death Metal",
        "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop",
        "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical", "Instrumental",
        "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise", "AlternRock",
        "Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop",
        "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial",
        "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock",
        "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk",
        "Jungle", "Native American", "Cabaret", "New Wave", "Psychadelic",
        "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk",
        "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock"
    };

    std::streampos tagEnd = 10 + metaDataSize;
    title = "";
    artist = "";
    album = "";
    genre = "";
    year = 0;
    number = 0;
    while (ifs.tellg() < tagEnd) {

        ifs.read(frameHeader, 10);
        frameID.assign(frameHeader,4);
        if (frameHeader[0] == 0)
            break;

        frameSize =
            ((frameHeader[4] & 0x7F) << 21) |
            ((frameHeader[5] & 0x7F) << 14) |
            ((frameHeader[6] & 0x7F) << 7)  |
            (frameHeader[7] & 0x7F);


        char* frameData = new char[metaDataSize];

        ifs.read(frameData, frameSize);

        if (frameSize > 1) {
            data.assign(frameData + 1,frameSize - 1);
        }

        if (frameID == "TIT2") {
            title = data;
        } else if (frameID == "TPE1") {
            artist = data;
        } else if (frameID == "TALB") {
            album = data;
        } else if (frameID == "TDRC") {
            year = atoi(data.c_str());
        } else if (frameID == "TRCK") {
            number = atoi(data.c_str());
        } else if (frameID == "TCON") {
            genreCode = atoi(data.substr(1, genre.size() - 2).c_str());
            genre = genreList[genreCode];
        } else if (frameID == "APIC") {
            /* TODO */
        }
        delete [] frameData;
    }
}
