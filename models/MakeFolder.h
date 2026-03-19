//
// Created by Hugo on 19/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MAKEFOLDER_H
#define CARENTERTAINMENTSYSTEM_MAKEFOLDER_H
#include <string>


class MakeFolder {
private:
    std::string folders[10];
    bool makeFolder(std::string folderName);
public:
    MakeFolder();
    ~MakeFolder() = default;
    void checkFolder();
};


#endif //CARENTERTAINMENTSYSTEM_MAKEFOLDER_H