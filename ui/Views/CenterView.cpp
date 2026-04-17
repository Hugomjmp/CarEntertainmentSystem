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
    //update();
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
    songName->setText("");
    std::string title = facade.getSong().getTitle()
                        + " - " +
                        facade.getSong().getArtist();

    songName->setText(title.c_str());

    progressBar->setHidden(false);
    auto &data = facade.getSong().getImage();
    if (data.size() == 0) {
        musicImage->setPixmap(
            QPixmap("resources/img/defaultMusic.png").scaled(
                musicImage->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
            )
        );
    } else {
        image.loadFromData(data.data(), data.size());
        image.loadFromData(facade.getSong().getImage());
        musicImage->setPixmap(
        QPixmap::fromImage(image).scaled(
                musicImage->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
            )
        );
    }
}

void CenterView::registerHandlers() {
    QObject::connect(playButton, &QPushButton::clicked, this, &CenterView::handlePlayClicked);
    QObject::connect(pauseButton, &QPushButton::clicked, this, &CenterView::handlePauseClicked);
    QObject::connect(nextButton, &QPushButton::clicked, this, &CenterView::handleNextClicked);
    QObject::connect(previousButton, &QPushButton::clicked, this, &CenterView::handlePreviousClicked);
    QObject::connect(repeatButton, &QPushButton::clicked, this, &CenterView::handleRepeatClicked);
    QObject::connect(&facade, &Facade::positionChanged, this, &CenterView::handleUpdatePosition);
    QObject::connect(&facade, &Facade::durationChanged, this, &CenterView::handleUpdateDuration);
}

QString CenterView::msToString(qint64 ms) {
    int totalSeconds = ms / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    return QString("%1:%2")
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
}

void CenterView::handleUpdatePosition(qint64 position) {
    currentSongTime->setText(msToString(position));
    progressBar->setValue(position);
}

void CenterView::handleUpdateDuration(qint64 duration) {
    progressBar->setMaximum(duration);
    finalSongTime->setText(msToString(duration));
}

void CenterView::handlePlayClicked() {
    facade.play();
    update();
    //facade.getSongDuration();
    stack->setCurrentIndex(1);
}

void CenterView::handlePauseClicked() {
    facade.pause();
    update();
    stack->setCurrentIndex(0);
}

void CenterView::handleNextClicked() {
    facade.nextSong();
    update();
}

void CenterView::handlePreviousClicked() {
    facade.previousSong();
    update();
}

void CenterView::handleRepeatClicked() {
    std::cout<<"Loop clicked"<<std::endl;
    update();
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

    previousButton = new QPushButton("", this);
    previousButton->setIcon(QIcon("resources/img/backward-step-solid_W"));
    previousButton->setIconSize(QSize(25,25));
    previousButton->setStyleSheet("border: none; ");

    nextButton= new QPushButton("", this);
    nextButton->setIcon(QIcon("resources/img/forward-step-solid_W"));
    nextButton->setIconSize(QSize(25,25));
    nextButton->setStyleSheet("border: none; ");

    repeatButton = new QPushButton("", this);
    repeatButton->setIcon(QIcon("resources/img/repeat-solid_W"));
    repeatButton->setIconSize(QSize(25,25));
    repeatButton->setStyleSheet("border: none; ");

    playButton = new QPushButton("", this);
    playButton->setIcon(QIcon("resources/img/play-solid_W.png"));
    playButton->setIconSize(QSize(25,25));
    playButton->setStyleSheet("border: none; ");

    pauseButton = new QPushButton("", this);
    pauseButton->setIcon(QIcon("resources/img/pause-solid_W.png"));
    pauseButton->setIconSize(QSize(25,25));
    pauseButton->setStyleSheet("border: none; ");



    HBoxButtons->addWidget(previousButton);
    stack->addWidget(playButton);
    stack->addWidget(pauseButton);
    stack->setCurrentIndex(0);  //for testing
    HBoxButtons->addWidget(stackContainer);
    HBoxButtons->addWidget(nextButton);
    HBoxButtons->addWidget(repeatButton);

    HBoxButtonsWidget->setLayout(HBoxButtons);
}

void CenterView::leftVBoxConfig() {
    leftBoxWidget = new QWidget(this);
    leftBoxWidget->setContentsMargins(0,0,0,0);

    leftVBox = new QVBoxLayout(leftBoxWidget);
    leftVBox->setContentsMargins(0,0,0,0);
    leftVBox->setSpacing(0);
    leftVBox->setAlignment(Qt::AlignCenter);

    songName = new QLabel("", leftBoxWidget);
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

    currentSongTime = new QLabel("");
    currentSongTime->setStyleSheet("color: white; "
                        "font-weight: bold; "
                        "font-family: Arial; "
                        "font-size: 14px;"
                        );

    finalSongTime = new QLabel("");
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
    progressBar->setMaximum(100);
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
    progressBar->setValue(0);  //for testing
    progressBar->hide();



}
