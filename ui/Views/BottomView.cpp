//
// Created by Hugo on 05/04/2026.
//

#include "BottomView.h"

#include <iostream>
#include <QTimer>
void BottomView::createViews() {
    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignLeft);
    volumeWidget = new QWidget();
    volumeWidget->setContentsMargins(0,0,00,0);
    volumeWidget->setFixedSize(25,25);

    stack = new QStackedLayout(volumeWidget);
    stack->setContentsMargins(0,0,0,0);
    stack->setSpacing(0);


    loadImages();

    volumeHigh = new QPushButton("", this);
    volumeHigh->setIcon(QIcon("resources/img/volume-high-solid_W.png"));
    volumeHigh->setIconSize(QSize(25,25));
    volumeHigh->setStyleSheet("border: none;");

    volumeLow = new QPushButton("", this);
    volumeLow->setIcon(QIcon("resources/img/volume-low-solid_W.png"));
    volumeLow->setIconSize(QSize(25,25));
    volumeLow->setStyleSheet("border: none;");

    volumeMed = new QPushButton("", this);
    volumeMed->setIcon(QIcon("resources/img/volume-med-solid_W.png"));
    volumeMed->setIconSize(QSize(25,25));
    volumeMed->setStyleSheet("border: none;");

    volumeNone = new QPushButton("", this);
    volumeNone->setIcon(QIcon("resources/img/volume-none-solid_W.png"));
    volumeNone->setIconSize(QSize(25,25));
    volumeNone->setStyleSheet("border: none;");

    volumeMute = new QPushButton("", this);
    volumeMute->setIcon(QIcon("resources/img/volume-xmark-solid_W.png"));
    volumeMute->setIconSize(QSize(25,25));
    volumeMute->setStyleSheet("border: none;");


    stack->addWidget(volumeHigh);
    stack->addWidget(volumeMed);
    stack->addWidget(volumeLow);
    stack->addWidget(volumeNone);
    stack->addWidget(volumeMute);
    stack->setCurrentWidget(volumeHigh);

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setValue(facade.getVolume());
    volumeSlider->setMaximumWidth(120);
    //volumeSlider->setFixedHeight(8);
    volumeSlider->setMinimum(0);
    volumeSlider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "  border: none;"
        "  height: 8px;"
        "  background: #333;"
        "  border-radius: 4px;"
        "}"
        "QSlider::sub-page:horizontal {"
        "  background: white;"
        "  border-radius: 4px;"
        "}"
        "QSlider::add-page:horizontal {"
        "  background: #333;"
        "  border-radius: 4px;"
        "}"
        "QSlider::handle:horizontal {"
        "  background: transparent;"
        "  border: none;"
        "  width: 0px;"
        "}"
    );
    volumeSlider->setVisible(false);
    layout->addWidget(volumeWidget);
    layout->addWidget(volumeSlider);
}

void BottomView::update() {
    if ((facade.getVolume() / 100) >= 0.66) {
        stack->setCurrentIndex(0);
    } else if ((facade.getVolume() / 100) >= 0.33 && (facade.getVolume() / 100) < 0.66) {
        stack->setCurrentIndex(1);
    } else if ((facade.getVolume() / 100) > 0 && (facade.getVolume() / 100) < 0.33) {
        stack->setCurrentIndex(2);
    } else if ((facade.getVolume() / 100) == 0) {
        stack->setCurrentIndex(3);
    }

}

void BottomView::registerHandlers() {
    QObject::connect(volumeSlider, &QSlider::valueChanged,this, &BottomView::volumeSliderValueChanged);
    QObject::connect(volumeMed, &QPushButton::clicked, this, &BottomView::enableSlider);
    QObject::connect(volumeLow, &QPushButton::clicked, this, &BottomView::enableSlider);
    QObject::connect(volumeNone, &QPushButton::clicked, this, &BottomView::enableSlider);
    QObject::connect(volumeMute, &QPushButton::clicked, this, &BottomView::enableSlider);

    QObject::connect(volumeHigh, &QPushButton::pressed, this, [this]() {
        longPressTriggered = false;
        pressTimer->start(200);
    });
    QObject::connect(volumeHigh, &QPushButton::released, this, [this]() {
        pressTimer->stop();

        if (!longPressTriggered) {

        }
    });

}

BottomView::BottomView(Facade & facade ,QWidget *parent) : facade(facade) {
    /*pressTimer = new QTimer;

    connect(pressTimer, &QTimer::timeout, this, [this]() {
    longPressTriggered = true;
    handleMute();
});
    createViews();
    registerHandlers();
    update();*/
}


void BottomView::loadImages() {

}

void BottomView::volumeSliderValueChanged() {
    facade.setVolume(volumeSlider->value());
    update();
}

void BottomView::enableSlider() {
    if (volumeSlider->isVisible()) {
        volumeSlider->setVisible(false);
        update();
        return;
    }
    volumeSlider->setVisible(true);
}

void BottomView::handleMute() {
    facade.setMute();
    stack->setCurrentIndex(4);
    //update();
}
