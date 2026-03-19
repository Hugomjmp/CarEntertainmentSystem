//
// Created by Hugo on 19/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_CONSOLEUI_H
#define CARENTERTAINMENTSYSTEM_CONSOLEUI_H


class ConsoleUI {
private:
    bool programActive = true;
public:
    ConsoleUI();
    ~ConsoleUI() = default;
    void showMenu();
    void toggleProgram();
    bool isProgramActive();
};


#endif //CARENTERTAINMENTSYSTEM_CONSOLEUI_H