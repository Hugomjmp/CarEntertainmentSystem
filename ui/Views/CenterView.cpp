//
// Created by Hugo on 05/04/2026.
//

#include "CenterView.h"

#include <iostream>
#include <QPushButton>

#include "BottomView.h"
#include "../../models/Facade.h"

CenterView::CenterView(Facade &facade, QWidget *parent) : facade(facade) {

    loadImages();
    createViews();
    registerHandlers();
    update();
}

void CenterView::createViews() {
    centerContainer = new QHBoxLayout(this);
    centerContainer->setContentsMargins(0,0,0,0);
    centerContainer->setSpacing(0);

    leftVBoxConfig();

    rightBoxWidget = new QWidget; // to remove later
    rightBoxWidget->setContentsMargins(0,0,0,0);




    centerContainer->addWidget(leftBoxWidget);
    centerContainer->addWidget(rightBoxWidget);


    this->setLayout(centerContainer);

}

void CenterView::update() {
}

void CenterView::registerHandlers() {
    QObject::connect(playButton, &QPushButton::clicked, this, &CenterView::handleMouseClicked);

}

void CenterView::handleMouseClicked() {
    facade.play();

}

void CenterView::loadImages() {
    /*musicImage.load("resources/img/defaultMusic.png");
    previousSong.load("resources/img/backward-step-solid_W.png");
    playSong.load("resources/img/play-solid_W.png");
    pauseSong.load("resources/img/pause-solid_W.png");
    nextSong.load("resources/img/forward-step-solid_W.png");
    repeat.load("resources/img/repeat-solid_W.png");*/
}

void CenterView::hboxSongButtons() {
    HBoxButtonsWidget = new QWidget(leftBoxWidget);
    HBoxButtons = new QHBoxLayout(HBoxButtonsWidget);
    HBoxButtons->setContentsMargins(0,30,0,0);
    HBoxButtons->setSpacing(50);
    HBoxButtons->setAlignment(Qt::AlignCenter);

    stackContainer = new QWidget(HBoxButtonsWidget);
    stackContainer->setContentsMargins(0,0,0,0);
    stackContainer->setFixedSize(25,25);
    stack = new QStackedLayout(stackContainer);
    stack->setContentsMargins(0,0,0,0);
    stack->setSpacing(0);
    stack->setAlignment(Qt::AlignCenter);


    previousIcon = new QLabel(HBoxButtonsWidget);
    previousIcon->setFixedSize(25,25);
    previousIcon->setPixmap(
        QPixmap("resources/img/backward-step-solid_W.png").scaled(
            previousIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    nextIcon = new QLabel(HBoxButtonsWidget);
    nextIcon->setFixedSize(25,25);
    nextIcon->setPixmap(
        QPixmap("resources/img/forward-step-solid_W.png").scaled(
            nextIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    repeatIcon = new QLabel(HBoxButtonsWidget);
    repeatIcon->setFixedSize(25,25);
    repeatIcon->setPixmap(
        QPixmap("resources/img/repeat-solid_W.png").scaled(
            repeatIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    playIcon = new QLabel(HBoxButtonsWidget);
    playIcon->setFixedSize(25,25);
    playIcon->setPixmap(
        QPixmap("resources/img/play-solid_W.png").scaled(
            playIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    pauseIcon = new QLabel(HBoxButtonsWidget);
    pauseIcon->setFixedSize(25,25);
    pauseIcon->setPixmap(
        QPixmap("resources/img/pause-solid_W.png").scaled(
            pauseIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );



    HBoxButtons->addWidget(previousIcon);
    /*HBoxButtons->addWidget(playIcon);
    HBoxButtons->addWidget(pauseIcon);*/
    //stack->addWidget(new QPushButton("play"));
    playButton = new QPushButton("play", this);

    stack->addWidget(playButton);
    stack->addWidget(playIcon);
    stack->addWidget(pauseIcon);
    stack->setCurrentIndex(0);



    HBoxButtons->addWidget(stackContainer);
    HBoxButtons->addWidget(nextIcon);
    HBoxButtons->addWidget(repeatIcon);

    HBoxButtonsWidget->setLayout(HBoxButtons);
}

void CenterView::leftVBoxConfig() {
    leftBoxWidget = new QWidget(this);
    leftBoxWidget->setContentsMargins(0,0,0,0);

    leftVBox = new QVBoxLayout(leftBoxWidget);
    leftVBox->setContentsMargins(0,0,0,0);
    leftVBox->setSpacing(0);
    leftVBox->setAlignment(Qt::AlignCenter);

    songName = new QLabel("Song Name", leftBoxWidget);
    songName->setStyleSheet("color: white; "
                            "font-weight: bold; "
                            "font-family: Arial; "
                            "font-size: 18px;"
                            "margin: 0 0 50px 0 0"
                            );

    musicImage = new QLabel(leftBoxWidget);
    musicImage->setFixedSize(200,200);
    musicImage->setPixmap(
        QPixmap("resources/img/defaultMusic.png").scaled(
            musicImage->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );


    hboxSongTime();
    timeLapseBar();
    hboxSongButtons();

    leftVBox->addWidget(songName,0,Qt::AlignCenter);
    leftVBox->addWidget(musicImage,0,Qt::AlignCenter);
    leftVBox->addWidget(HBoxSongTimeWidget,0,Qt::AlignCenter);
    leftVBox->addWidget(progressBar,0,Qt::AlignCenter);
    leftVBox->addWidget(HBoxButtonsWidget,0,Qt::AlignCenter);

    leftBoxWidget->setLayout(leftVBox);

}

void CenterView::hboxSongTime() {
    HBoxSongTimeWidget = new QWidget(leftBoxWidget);
    HBoxSongTimeWidget->setContentsMargins(0,30,0,10);

    HBoxSongTime = new QHBoxLayout(HBoxSongTimeWidget);
    HBoxSongTime->setContentsMargins(0,0,0,0);
    HBoxSongTime->setSpacing(180);
    HBoxSongTime->setAlignment(Qt::AlignCenter);

    currentSongTime = new QLabel("1:00");
    currentSongTime->setStyleSheet("color: white; "
                        "font-weight: bold; "
                        "font-family: Arial; "
                        "font-size: 14px;"
                        );

    finalSongTime = new QLabel("4:20");
    finalSongTime->setStyleSheet("color: white; "
                        "font-weight: bold; "
                        "font-family: Arial; "
                        "font-size: 14px; "
                        );

    HBoxSongTime->addWidget(currentSongTime);
    HBoxSongTime->addWidget(finalSongTime);

    HBoxSongTimeWidget->setLayout(HBoxSongTime);

}

void CenterView::timeLapseBar() {
    progressBar = new QProgressBar(leftBoxWidget);
    progressBar->setMinimumWidth(300);
    progressBar->setTextVisible(false);
    progressBar->setFixedHeight(8);

    progressBar->setStyleSheet(
        "QProgressBar {"
        "  border: none;"
        "  border-radius: 4px;"
        "  background-color: #333;"
        "}"
        "QProgressBar::chunk {"
        "  background-color: white;"
        "  border-radius: 4px;"
        "}"
    );
    progressBar->setValue(20);  //for testing



}
