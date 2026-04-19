//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_METADATA_H
#define CARENTERTAINMENTSYSTEM_METADATA_H
#include <string>
#include <vector>

/**
 * Class to read metadata from the mp3 files.
 * Compatible with ID3v2.3.0 and ID3v2.4.0 .
 */
class MetaData {
private:
    std::string static file;
    std::string static title;
    std::string static artist;
    std::string static album;
    int static year;
    int static number;
    std::string static genre;
    int static duration;
    std::vector<unsigned char> static image;
    void static ID3v2_30(std::ifstream& ifs, const int& metaDataSize);
    void static ID3v2_40(std::ifstream& ifs, const int& metaDataSize);
public:
    MetaData();
    ~MetaData() = default;
    void static searchFile(std::string newFileSearch);
    std::string static getTitle();
    std::string static getArtist();
    std::string static getAlbum();
    int static getYear();
    int static getNumber();
    std::string static getGenre();
    int static getDuration();
    std::vector<unsigned char> static getImage();
};



#endif //CARENTERTAINMENTSYSTEM_METADATA_H
