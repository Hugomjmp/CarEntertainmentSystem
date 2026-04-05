//
// Created by Hugo on 05/04/2026.
//

#include "LeftView.h"
LeftView::LeftView(QWidget *parent) {


    createViews();
    registerHandlers();
    update();

}

LeftView::~LeftView() {
    delete layout;
    delete sourceIcon;
    delete navigationIcon;
    delete fanIcon;
}

void LeftView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    loadImages();

    sourceIcon = new QLabel(this);
    sourceIcon->setFixedSize(25,25);

    sourceIcon->setPixmap(
    source.scaled(
        sourceIcon->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    )
);
    navigationIcon = new QLabel(this);
    navigationIcon->setFixedSize(25,25);
    navigationIcon->setPixmap(
        navigation.scaled(
            navigationIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    fanIcon = new QLabel(this);
    fanIcon->setFixedSize(25,25);
    fanIcon->setPixmap(
        fan.scaled(
            fanIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    layout->addWidget(sourceIcon);
    layout->addWidget(navigationIcon);
    layout->addWidget(fanIcon);
}

void LeftView::update() {
}

void LeftView::registerHandlers() {
}

void LeftView::loadImages() {
    source.load("resources/img/music-solid_W.png");
    navigation.load("resources/img/location-arrow-solid_W.png");
    fan.load("resources/img/fan-solid_W.png");
}
