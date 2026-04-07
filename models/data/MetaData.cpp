//
// Created by Hugo on 07/04/2026.
//

#include "MetaData.h"

#include <fstream>
#include <iostream>
#include <ostream>
std::string MetaData::file;
MetaData::MetaData() {
}

void MetaData::searchFile(std::string newFileSearch) {
    char header[10];
    int metaDataSize = 0;
    std::string title;
    std::string frameID;
    file = newFileSearch;
    std::cout << "Searching for file: " << file << std::endl;
    std::ifstream ifs(file, std::ios::binary);
    ifs.seekg(0, std::ios::beg);
    ifs.read(header, 10);
    metaDataSize =
        ((header[6] & 0x7F) << 21) |
        ((header[7] & 0x7F) << 14) |
        ((header[8] & 0x7F) << 7) |
        (header[9] & 0x7F);

    std::cout << "File size: " << metaDataSize << " bytes" << std::endl;
    char frameHeader[10];
    int frameSize = 0;

    while (ifs.tellg() < metaDataSize) {
        ifs.read(frameHeader, 10);
        frameID.assign(frameHeader,4);
        //std::string frameID(frameHeader,4);
        std::cout << "frameID: " << frameID << std::endl;
        frameSize =
            (unsigned char)frameHeader[4] << 24 |
            (unsigned char)frameHeader[5] << 16 |
            (unsigned char)frameHeader[6] << 8  |
            (unsigned char)frameHeader[7];

        std::cout << "frameSize: " << frameSize << " bytes" << std::endl;
        ifs.seekg(frameSize, std::ios::cur);
        if (frameSize == 0) {
            break;
        }
    }
    /*char frameHeader[10];
    int frameSize = 0;
    ifs.read(frameHeader, 10);
    frameID.assign(frameHeader,4);
    //std::string frameID(frameHeader,4);
    std::cout << "frameID: " << frameID << std::endl;
    frameSize =
        (unsigned char)frameHeader[4] << 24 |
        (unsigned char)frameHeader[5] << 16 |
        (unsigned char)frameHeader[6] << 8  |
        (unsigned char)frameHeader[7];

    std::cout << "frameSize: " << frameSize << " bytes" << std::endl;
    ifs.seekg(frameSize, std::ios::cur);
    ifs.read(frameHeader, 10);
    frameID.assign(frameHeader,4);
    std::cout << "frameID: " << frameID << std::endl;
    frameSize =
        (unsigned char)frameHeader[4] << 24 |
        (unsigned char)frameHeader[5] << 16 |
        (unsigned char)frameHeader[6] << 8  |
        (unsigned char)frameHeader[7];

    std::cout << "frameSize: " << frameSize << " bytes" << std::endl;
    //-----------title-----------------
    ifs.seekg(frameSize, std::ios::cur);
    ifs.read(frameHeader, 10);
    frameID.assign(frameHeader,4);
    std::cout << "frameID: " << frameID << std::endl;

    frameSize =
        (unsigned char)frameHeader[4] << 24 |
        (unsigned char)frameHeader[5] << 16 |
        (unsigned char)frameHeader[6] << 8  |
        (unsigned char)frameHeader[7];

    std::cout << "frameSize: " << frameSize << " bytes" << std::endl;

    char * frameData = new char[frameSize];
    ifs.read(frameData, frameSize);

    title.assign(frameData,frameSize);
    std::cout << "title:" << title << std::endl;
    //---------------------------
    //ifs.seekg(frameSize, std::ios::cur);
    ifs.read(frameHeader, 10);
    frameID.assign(frameHeader,4);
    std::cout << "frameID: " << frameID << std::endl;
    frameSize =
        (unsigned char)frameHeader[4] << 24 |
        (unsigned char)frameHeader[5] << 16 |
        (unsigned char)frameHeader[6] << 8  |
        (unsigned char)frameHeader[7];

    std::cout << "frameSize: " << frameSize << " bytes" << std::endl;*/

    ifs.close();
    //delete [] frameData;
}

std::string MetaData::getTitle() {
    return "";
}

std::string MetaData::getAlbum() {
    return "";
}

int MetaData::getYear() {
    return 0;
}

int MetaData::getNumber() {
    return 0;
}

std::string MetaData::getGenre() {
    return "";
}

int MetaData::getDuration() {
    return 0;
}
