//
// Created by Hugo on 19/03/2026.
//

#include "ConsoleUI.h"

#include <iostream>

ConsoleUI::ConsoleUI() {
}

void ConsoleUI::showMainMenu() {
    std::cout << "+-------------------+" << std::endl;
    std::cout << "|         MENU      |" << std::endl;
    std::cout << "+-------------------+" << std::endl;
    std::cout << "| 1 - show music    |" << std::endl;
    std::cout << "| 2 - play song     |" << std::endl;
    std::cout << "| 3 - set volume    |" << std::endl;
    std::cout << "| 4 - pause music   |" << std::endl;
    std::cout << "| 5 - stop music    |" << std::endl;
    std::cout << "| 6 - Get Song Time |" << std::endl;
    std::cout << "| 7 - exit program  |" << std::endl;
    std::cout << "+-------------------+" << std::endl;
    std::cout << "#> ";
}
