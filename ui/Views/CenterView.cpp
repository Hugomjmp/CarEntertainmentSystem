//
// Created by Hugo on 05/04/2026.
//

#include "CenterView.h"

CenterView::CenterView(QWidget *parent) {

    loadImages();
    createViews();
    registerHandlers();
    update();
}

CenterView::~CenterView() {
    delete musicPicture;
    delete previousIcon;
    delete pauseIcon;
    delete nextIcon;
    delete repeatIcon;
    delete HBoxButtons;
    delete leftVBox;
    delete rightVBox;
    delete layout;
    delete progressBar;
    delete HBoxButtonsWidget;
    delete leftBoxWidget;
    delete rightBoxWidget;
    delete playIcon;
    delete stack;
    delete stackContainer;
    delete centerLayout;
}

void CenterView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);


    
    leftVBoxConfig();

    rightBoxWidget = new QWidget(this); // to remove later
    rightBoxWidget->setContentsMargins(0,0,0,0);

    rightBoxWidget->setStyleSheet("background-color: blue;");

    layout->addWidget(leftBoxWidget,0,1);
    layout->addWidget(rightBoxWidget,0,2);



    //layout->addWidget();
}

void CenterView::update() {
}

void CenterView::registerHandlers() {
}

void CenterView::loadImages() {
    musicImage.load("resources/img/defaultMusic.png");
    previousSong.load("resources/img/backward-step-solid_W.png");
    playSong.load("resources/img/play-solid_W.png");
    pauseSong.load("resources/img/pause-solid_W.png");
    nextSong.load("resources/img/forward-step-solid_W.png");
    repeat.load("resources/img/repeat-solid_W.png");
}

void CenterView::hboxSongButtons() {
    HBoxButtonsWidget = new QWidget(this);
    HBoxButtons = new QHBoxLayout(HBoxButtonsWidget);
    HBoxButtons->setContentsMargins(0,0,0,0);
    HBoxButtons->setSpacing(50);
    HBoxButtons->setAlignment(Qt::AlignCenter);

    stackContainer = new QWidget(this);
    stackContainer->setContentsMargins(0,0,0,0);
    stackContainer->setFixedSize(25,25);
    stack = new QStackedLayout(stackContainer);
    stack->setContentsMargins(0,0,0,0);
    stack->setSpacing(0);

    previousIcon = new QLabel(HBoxButtonsWidget);
    previousIcon->setPixmap(
        previousSong.scaled(
            previousIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    nextIcon = new QLabel(HBoxButtonsWidget);
    nextIcon->setPixmap(
        nextSong.scaled(
            nextIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    repeatIcon = new QLabel(HBoxButtonsWidget);
    repeatIcon->setPixmap(
        repeat.scaled(
            repeatIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    playIcon = new QLabel(HBoxButtonsWidget);
    playIcon->setPixmap(
        playSong.scaled(
            playIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    pauseIcon = new QLabel(HBoxButtonsWidget);
    pauseIcon->setPixmap(
        pauseSong.scaled(
            pauseIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    previousIcon->setFixedSize(25,25);
    nextIcon->setFixedSize(25,25);
    repeatIcon->setFixedSize(25,25);
    playIcon->setFixedSize(25,25);
    pauseIcon->setFixedSize(25,25);

    HBoxButtons->addWidget(previousIcon);
    stack->addWidget(playIcon);
    stack->addWidget(pauseIcon);
    stack->setCurrentIndex(0);
    HBoxButtons->addWidget(stackContainer);
    HBoxButtons->addWidget(nextIcon);
    HBoxButtons->addWidget(repeatIcon);
    HBoxButtonsWidget->setStyleSheet("background-color: orange;");
}

void CenterView::leftVBoxConfig() {
    leftBoxWidget = new QWidget(this);
    leftBoxWidget->setContentsMargins(0,0,0,0);

    leftVBox = new QVBoxLayout(leftBoxWidget);
    leftVBox->setContentsMargins(0,0,0,0);
    leftVBox->setSpacing(0);
    leftVBox->setAlignment(Qt::AlignHCenter);

    songName = new QLabel("Song Name", leftBoxWidget);
    songName->setStyleSheet("color: white; font-weight: bold; font-family: Arial; font-size: 18px;");

    musicPicture = new QLabel(leftBoxWidget);
    musicPicture->setPixmap(
        musicImage.scaled(
            musicPicture->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    musicPicture->setFixedSize(200,200);
    //ADD PROGRESS BAR HERE LATER
    hboxSongButtons();


    leftBoxWidget->setStyleSheet("background-color: green;");
    leftVBox->addWidget(songName);
    leftVBox->addWidget(musicPicture);
    leftVBox->addWidget(HBoxButtonsWidget);

}
