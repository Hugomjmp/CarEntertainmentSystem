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

    this->setLayout(mainLayout);
    //"border: 2px solid #ffffff"
    this->setStyleSheet("background-color: #121212;");

    createToolBar();
    createOption1();
    createOption2();

    mainLayout->addLayout(toolBar);
    mainLayout->addLayout(option1);
    mainLayout->addLayout(option2);

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
    option1btn = new QPushButton();

    option1 = new QHBoxLayout();
    option1->setContentsMargins(0,0,0,0);
    option1->setSpacing(10);

    internetRadioImg = new QLabel();
    internetRadioImg->setFixedSize(200,60);
    internetRadioImg->setPixmap(
        QPixmap("resources/img/dark_logo.png").scaled(
            internetRadioImg->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );



    option1Label = new QLabel("Internet Radio");
    option1Label->setStyleSheet("color: white;"
        "font-family: Arial;"
        "font-weight: bold;"
        "font-size: 18px;");
    option1->addWidget(internetRadioImg);
    option1->addWidget(option1Label);
    option1btn->setLayout(option1);
}

void SourceView::createOption2() {
    option2btn = new QPushButton();
    option2 = new QHBoxLayout();
    option2->setContentsMargins(0,0,0,0);
    option2->setSpacing(0);


    localMusicImg = new QLabel();
    localMusicImg->setFixedSize(200,60);
    localMusicImg->setPixmap(
        QPixmap("resources/img/music-solid_W.png").scaled(
            localMusicImg->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );



    option2Label = new QLabel("Local Music");
    option2Label->setStyleSheet("color: white;"
        "font-family: Arial;"
        "font-weight: bold;"
        "font-size: 18px;");
    option2->addWidget(localMusicImg);
    option2->addWidget(option2Label);
    option2btn->setLayout(option1);
}

void SourceView::handleInternetButton() {
    if (facade.getSourceType() != INTERNET_RADIO) {
        facade.setSourceType(INTERNET_RADIO);
    }
}

void SourceView::handleLocalButton() {
    if (facade.getSourceType() != LOCAL_MUSIC) {
        facade.setSourceType(LOCAL_MUSIC);
    }
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
