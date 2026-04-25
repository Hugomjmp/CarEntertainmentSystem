//
// Created by Hugo on 18/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_SOURCEVIEW_H
#define CARENTERTAINMENTSYSTEM_SOURCEVIEW_H
#include <qboxlayout.h>

#include "../../models/Facade.h"
#include <qwindow.h>
#include <qlabel.h>
#include <QPushButton>

class SourceView : public QWidget{
private:
    Facade &facade;
    QWidget *tooBarWidget = nullptr;
    QVBoxLayout *mainLayout;
    QHBoxLayout *toolBar = nullptr;
    QPushButton *closeWindowbtn = nullptr, *option1btn = nullptr, *option2btn = nullptr, *option3btn = nullptr;
    QLabel *title = nullptr;
    void createViews();
    void update();
    void registerHandlers();
    void createToolBar();
    void createOption1();
    void createOption2();
    void createOption3();
    void handleCloseButton();
    void handleInternetButton();
    void handleLocalButton();
    void handleFMButton();
public:
    SourceView(Facade &facade, QWidget *parent = nullptr);
    ~SourceView() = default;

};



#endif //CARENTERTAINMENTSYSTEM_SOURCEVIEW_H
