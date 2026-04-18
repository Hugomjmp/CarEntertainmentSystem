//
// Created by Hugo on 05/04/2026.
//

#include "LeftView.h"
LeftView::LeftView(Facade &facade, QWidget *parent) : facade(facade) {
    createViews();
    registerHandlers();
    update();
}

void LeftView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    loadImages();

    sourceButton = new QPushButton(this);
    sourceButton->setIcon(QIcon("resources/img/music-solid_W.png"));
    sourceButton->setIconSize(QSize(25,25));
    sourceButton->setStyleSheet("border: none;");

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

    layout->addWidget(sourceButton);
    layout->addWidget(navigationIcon);
    layout->addWidget(fanIcon);
}

void LeftView::update() {
}

void LeftView::registerHandlers() {
    QObject::connect(sourceButton, &QPushButton::clicked, this, &LeftView::handleSourceButtonClicked);
}

void LeftView::handleSourceButtonClicked() {
    sourceView = new SourceView(facade);
    sourceView->setFixedSize(300,350);
    sourceView->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    sourceView->setWindowModality(Qt::ApplicationModal);
    sourceView->show();

}

void LeftView::loadImages() {
    source.load("resources/img/music-solid_W.png");
    navigation.load("resources/img/location-arrow-solid_W.png");
    fan.load("resources/img/fan-solid_W.png");
}
