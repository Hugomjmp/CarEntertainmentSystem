//
// Created by Hugo on 18/04/2026.
//

#include "SourceView.h"

SourceView::SourceView(Facade &facade,QWidget *parent) : facade(facade) {
    createViews();
    registerHandlers();
    update();



}


void SourceView::createViews() {
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);

    //"border: 2px solid #ffffff"
    this->setStyleSheet("background-color: #121212;");

    createToolBar();
    createOption1();
    createOption2();

    mainLayout->addLayout(toolBar);
    mainLayout->addWidget(option1btn);
    mainLayout->addWidget(option2btn);

}

void SourceView::createToolBar() {
    toolBar = new QHBoxLayout();
    toolBar->setContentsMargins(0,0,0,0);
    toolBar->setSpacing(50);

    title = new QLabel("Source Selection",this);
    title->setStyleSheet("color: white;"
                         "font-family: Arial;"
                         "font-weight: bold;"
                         "font-size: 18px;");

    closeWindowbtn = new QPushButton(this);
    closeWindowbtn->setIcon(QIcon("resources/img/x-solid_W.png"));
    closeWindowbtn->setIconSize(QSize(25,25));
    closeWindowbtn->setStyleSheet("border: none;");

    toolBar->addWidget(title);
    toolBar->addWidget(closeWindowbtn);
    toolBar->setAlignment(Qt::AlignRight);
}

void SourceView::createOption1() {
    option1btn = new QPushButton("Internet Radio");
    option1btn->setIcon(QIcon("resources/img/dark_logo.png"));
    option1btn->setIconSize(QSize(200,60));
    option1btn->setStyleSheet(
        "text-align: left;"
        "color: white;"
        "font-family: Arial;"
        "font-weight: bold;"
        "font-size: 18px;"
        "border: none;"
        "padding-left: 10px;"
    );
}

void SourceView::createOption2() {
    option2btn = new QPushButton("Local Music");
    option2btn->setIcon(QIcon("resources/img/music-solid_W.png"));
    option2btn->setIconSize(QSize(200,60));
    option2btn->setStyleSheet(
        "text-align: left;"
        "color: white;"
        "font-family: Arial;"
        "font-weight: bold;"
        "font-size: 18px;"
        "border: none;"
        "padding-left: 10px;"
    );
}

void SourceView::handleInternetButton() {
    if (facade.getSourceType() != INTERNET_RADIO) {
        facade.setSourceType(INTERNET_RADIO);
        facade.play();
    }
    this->close();
}

void SourceView::handleLocalButton() {
    if (facade.getSourceType() != LOCAL_MUSIC) {
        facade.setSourceType(LOCAL_MUSIC);
        facade.play();
    }
    this->close();
}

void SourceView::update() {
}

void SourceView::registerHandlers() {
    QObject::connect(closeWindowbtn, &QPushButton::clicked,this, &SourceView::handleCloseButton);
    QObject::connect(option1btn, &QPushButton::clicked, this, &SourceView::handleInternetButton);
    QObject::connect(option2btn, &QPushButton::clicked, this, &SourceView::handleLocalButton);
}

void SourceView::handleCloseButton() {
    this->close();
}
