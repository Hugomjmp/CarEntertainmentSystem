//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_METADATA_H
#define CARENTERTAINMENTSYSTEM_METADATA_H
#include <string>


class MetaData {
private:
    std::string static file;
    std::string title;
    std::string album;
    int year;
    int number;
    std::string genre;
    int duration;
public:
    MetaData();
    ~MetaData() = default;
    void static searchFile(std::string newFileSearch);
    std::string static getTitle();
    std::string static getAlbum();
    int static getYear();
    int static getNumber();
    std::string static getGenre();
    int static getDuration();
};



#endif //CARENTERTAINMENTSYSTEM_METADATA_H
