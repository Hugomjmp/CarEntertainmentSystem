//
// Created by Hugo on 21/04/2026.
//

#include "MediaPlayerView.h"

#include <iostream>

MediaPlayerView::MediaPlayerView(Facade &facade, QWidget *parent) : facade(facade) {
    createViews();
    registerHandlers();
    update();
}

void MediaPlayerView::createViews() {
    VBoxConfig();
}

void MediaPlayerView::update() {
    mediaName->setText("");
    progressBar->setValue(0);
    progressBar->hide();
    currentSongTime->hide();
    finalSongTime->hide();

    switch (facade.getSourceType()) {
        case LOCAL_MUSIC: {
            currentSongTime->show();
            finalSongTime->show();
            repeatButton->show();
            std::string title = facade.getSong().getTitle()
                                + " - " +
                                facade.getSong().getArtist();
            mediaName->setText(QString::fromStdString(title));
            progressBar->show();
            if (facade.getPlayStatus())
                stack->setCurrentIndex(1);
            else
                stack->setCurrentIndex(0);

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
            break;
        case INTERNET_RADIO: {
            std::string title = facade.getStation().getName();
            mediaName->setText(title.c_str());
            repeatButton->hide();
            if (facade.getPlayStatus())
                stack->setCurrentIndex(1);
            else
                stack->setCurrentIndex(0);

            image.loadFromData(facade.getStation().getFavicon());
            musicImage->setPixmap(
            QPixmap::fromImage(image).scaled(
                    musicImage->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );

        }
            break;
    }
}

void MediaPlayerView::registerHandlers() {
    QObject::connect(playButton, &QPushButton::clicked, this, &MediaPlayerView::handlePlayClicked);
    QObject::connect(pauseButton, &QPushButton::clicked, this, &MediaPlayerView::handlePauseClicked);
    QObject::connect(nextButton, &QPushButton::clicked, this, &MediaPlayerView::handleNextClicked);
    QObject::connect(previousButton, &QPushButton::clicked, this, &MediaPlayerView::handlePreviousClicked);
    QObject::connect(repeatButton, &QPushButton::clicked, this, &MediaPlayerView::handleRepeatClicked);
    QObject::connect(&facade, &Facade::positionChanged, this, &MediaPlayerView::handleUpdatePosition);
    QObject::connect(&facade, &Facade::durationChanged, this, &MediaPlayerView::handleUpdateDuration);
    QObject::connect(&facade, &Facade::sourceTypeChanged, this, &MediaPlayerView::update);
}

void MediaPlayerView::VBoxConfig() {
    //leftBoxWidget = new QWidget(this);
    //leftBoxWidget->setContentsMargins(0,0,0,0);
    this->setContentsMargins(0,0,0,0);

    VBox = new QVBoxLayout(this);
    VBox->setContentsMargins(0,0,0,0);
    VBox->setSpacing(0);
    VBox->setAlignment(Qt::AlignCenter);

    mediaName = new QLabel("", this);
    mediaName->setStyleSheet("color: white; "
                            "font-weight: bold; "
                            "font-family: Arial; "
                            "font-size: 18px;"
                            "margin: 0 0 50px 0 0"
                            );

    musicImage = new QLabel(this);
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

    VBox->addWidget(mediaName,0,Qt::AlignCenter);
    VBox->addWidget(musicImage,0,Qt::AlignCenter);
    VBox->addWidget(HBoxSongTimeWidget,0,Qt::AlignCenter);
    VBox->addWidget(progressBar,0,Qt::AlignCenter);
    VBox->addWidget(HBoxButtonsWidget,0,Qt::AlignCenter);

    this->setLayout(VBox);
}

void MediaPlayerView::hboxSongButtons() {
    HBoxButtonsWidget = new QWidget(this);
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

    previousButton = new QPushButton("", HBoxButtonsWidget);
    previousButton->setIcon(QIcon("resources/img/backward-step-solid_W"));
    previousButton->setIconSize(QSize(25,25));
    previousButton->setStyleSheet("border: none; ");

    nextButton= new QPushButton("", HBoxButtonsWidget);
    nextButton->setIcon(QIcon("resources/img/forward-step-solid_W"));
    nextButton->setIconSize(QSize(25,25));
    nextButton->setStyleSheet("border: none; ");

    repeatButton = new QPushButton("", HBoxButtonsWidget);
    repeatButton->setIcon(QIcon("resources/img/repeat-solid_W"));
    repeatButton->setIconSize(QSize(25,25));
    repeatButton->setStyleSheet("border: none; ");

    playButton = new QPushButton("", HBoxButtonsWidget);
    playButton->setIcon(QIcon("resources/img/play-solid_W.png"));
    playButton->setIconSize(QSize(25,25));
    playButton->setStyleSheet("border: none; ");

    pauseButton = new QPushButton("", HBoxButtonsWidget);
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

void MediaPlayerView::hboxSongTime() {
    HBoxSongTimeWidget = new QWidget(this);
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

void MediaPlayerView::timeLapseBar() {
    progressBar = new QProgressBar(this);
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

void MediaPlayerView::handleUpdatePosition(qint64 position) {
    if (facade.getSourceType() == LOCAL_MUSIC) {
        currentSongTime->setText(msToString(position));
        progressBar->setValue(position);
    }
}

void MediaPlayerView::handleUpdateDuration(qint64 duration) {
    if (facade.getSourceType() == LOCAL_MUSIC) {
        progressBar->setMaximum(duration);
        finalSongTime->setText(msToString(duration));
    }
}

void MediaPlayerView::handlePlayClicked() {
    facade.play();
    update();
    //facade.getSongDuration();
    stack->setCurrentIndex(1);
}

void MediaPlayerView::handlePauseClicked() {
    facade.pause();
    update();
    stack->setCurrentIndex(0);
}

void MediaPlayerView::handleNextClicked() {
    facade.nextSong();
    update();
}

void MediaPlayerView::handlePreviousClicked() {
    facade.previousSong();
    update();
}

void MediaPlayerView::handleRepeatClicked() {
    facade.loopSong();
    update();
}


QString MediaPlayerView::msToString(qint64 ms) {
    int totalSeconds = ms / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    return QString("%1:%2")
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
}