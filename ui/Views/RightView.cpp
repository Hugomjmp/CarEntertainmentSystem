//
// Created by Hugo on 05/04/2026.
//

#include "RightView.h"

void RightView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    loadImages();

    phoneImg = new QLabel(this);
    appsImg = new QLabel(this);
    carImg = new QLabel(this);

    phoneImg->setFixedSize(25,25);
    phoneImg->setPixmap(
        phone.scaled(
            phoneImg->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    appsImg->setFixedSize(25,25);
    appsImg->setPixmap(
        apps.scaled(
            appsImg->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    carImg->setFixedSize(25,25);
    carImg->setPixmap(
        car.scaled(
            carImg->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    layout->addWidget(phoneImg);
    layout->addWidget(appsImg);
    layout->addWidget(carImg);
}

void RightView::update() {
}

void RightView::registerHandlers() {
}

RightView::RightView(QWidget *parent) {


    createViews();
    registerHandlers();
    update();
}


void RightView::loadImages() {
    phone.load("resources/img/phone-solid_W.png");
    apps.load("resources/img/grip-solid_W.png");
    car.load("resources/img/car-solid_W.png");
}
