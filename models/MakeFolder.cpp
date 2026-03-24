//
// Created by Hugo on 19/03/2026.
//

#include "MakeFolder.h"


#include <filesystem>
#include <iostream>

#include "../Settings/Folders.h"


MakeFolder::MakeFolder() {
    std::cout << "Creating first time Folders..." << std::endl;
    for (int i = 0; i < 10; i++) {
        folders[i] = "";
    }
    folders[0] = Folder::musicFolder;
    folders[1] = Folder::configFolder;

}

bool MakeFolder::makeFolder(std::string folderName) {
    std::cout << "Adding " << folderName << " folder..." << std::endl;
    if (std::filesystem::create_directory(folderName)) {
        return true;
    }
    return false;
}


/// Fazer uma proteção para caso não haja permissões
void MakeFolder::checkFolder() {
    for (int i = 0; i < 10; i++) {
        if (!std::filesystem::exists(folders[i]) && !folders[i].empty()) {
            makeFolder(folders[i]);
        }
    }
}
