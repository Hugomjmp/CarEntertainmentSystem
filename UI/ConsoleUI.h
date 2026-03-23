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
    void showMainMenu() const;
    void showLibraryMenu() const;
};


#endif //CARENTERTAINMENTSYSTEM_CONSOLEUI_H