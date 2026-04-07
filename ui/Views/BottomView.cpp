//
// Created by Hugo on 05/04/2026.
//

#include "BottomView.h"

void BottomView::createViews() {
    stack = new QStackedLayout(this);
    stack->setContentsMargins(0,0,0,0);
    stack->setSpacing(0);
    /*layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);*/

    loadImages();

    volumeHighIcon = new QLabel(this);
    volumeLowIcon = new QLabel(this);
    volumeMedIcon = new QLabel(this);
    volumeNoneIcon = new QLabel(this);
    volumeMuteIcon = new QLabel(this);

    volumeHighIcon->setFixedSize(25,25);
    volumeLowIcon->setFixedSize(25,25);
    volumeMedIcon->setFixedSize(25,25);
    volumeNoneIcon->setFixedSize(25,25);
    volumeMuteIcon->setFixedSize(25,25);

    volumeHighIcon->setPixmap(
        volumeHigh.scaled(
            volumeHighIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    volumeLowIcon->setPixmap(
        volumeLow.scaled(
            volumeLowIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    volumeMedIcon->setPixmap(
        volumeMed.scaled(
            volumeMedIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    volumeNoneIcon->setPixmap(
        volumeNone.scaled(
            volumeNoneIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    volumeMuteIcon->setPixmap(
        volumeMute.scaled(
            volumeMuteIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    //layout->addWidget(volumeHighIcon);
    stack->addWidget(volumeHighIcon);
    stack->addWidget(volumeLowIcon);
    stack->addWidget(volumeMedIcon);
    stack->addWidget(volumeNoneIcon);
    stack->addWidget(volumeMuteIcon);
    volumeSlider = new QSlider(Qt::Horizontal);
    stack->setCurrentWidget(volumeHighIcon);


    /*layout->addWidget(volumeLowIcon);
    layout->addWidget(volumeMedIcon);
    layout->addWidget(volumeNoneIcon);
    layout->addWidget(volumeMuteIcon);*/
}

void BottomView::update() {
}

void BottomView::registerHandlers() {
}

BottomView::BottomView(QWidget *parent) {

    createViews();
    registerHandlers();
    update();
}


void BottomView::loadImages() {
    volumeHigh.load("resources/img/volume-high-solid_W.png");
    volumeLow.load("resources/img/volume-low-solid_W.png");
    volumeMed.load("resources/img/volume-med-solid_W.png");
    volumeNone.load("resources/img/volume-none-solid_W.png");
    volumeMute.load("resources/img/volume-xmark-solid_W.png");
}
