//
// Created by Hugo on 05/04/2026.
//

#include "TopView.h"

#include <iostream>

TopView::TopView(QWidget *parent) : QWidget(parent) {

    createViews();
    registerHandlers();
    update();
}

TopView::~TopView() {
    delete layout;
    delete firstCell;
    delete secondCell;
    delete temperature;
    delete fanStatus;
    delete time;
    delete fanSpeedIcon;
    delete bluetoothIcon;
    delete wifiIcon;
    delete cellServiceIcon;
    delete gpsIcon;
    delete cellServiceIcon;
    delete firstCell;
    delete secondCell;
    delete firstCellLayout;
    delete secondCellLayout;


}
void TopView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    temperature = new QLabel("24ºC",this);
    temperature->setStyleSheet("color: white; font-weight: bold; font-family: Arial;font-size: 15px;");
    loadImages();
    firstCellConfig();
    secondCellConfig();


    layout->addWidget(temperature);
    layout->addWidget(firstCell,0,1);
    layout->addWidget(secondCell,0,2);

}

void TopView::update() {
}

void TopView::registerHandlers() {
}

void TopView::loadImages() {
    fan.load("resources/img/fan-solid_W.png");
    bluetooth.load("resources/img/bluetooth-b-brands-solid_off_W.png");
    wifi.load("resources/img/wifi-solid_none_W.png");
    cellService.load("resources/img/signal-solid_0bar_W.png");
    gps.load("resources/img/location-dot-solid_noLocation_W.png");
    gearSettingsImg.load("resources/img/gear-solid_W.png");

}

void TopView::firstCellConfig() {
    firstCell = new QWidget(this);
    firstCellLayout = new QHBoxLayout(firstCell);
    firstCellLayout->setContentsMargins(0,0,0,0);
    firstCellLayout->setSpacing(0);

    fanSpeedIcon = new QLabel(firstCell);
    fanSpeedIcon->setFixedSize(25,25);

    fanSpeedIcon->setPixmap(
        fan.scaled(
            fanSpeedIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );


    //this will change later, just for testing
    fanStatus = new QLabel("OFF", firstCell);
    fanStatus->setStyleSheet("color: white; font-weight: bold; font-family: Arial;font-size: 15px;");



    firstCellLayout->addWidget(fanSpeedIcon);
    firstCellLayout->addWidget(fanStatus);


}

void TopView::secondCellConfig() {
    secondCell = new QWidget(this);
    secondCellLayout = new QHBoxLayout(secondCell);
    secondCellLayout->setContentsMargins(0,0,0,0);
    secondCellLayout->setSpacing(0);

    bluetoothIcon = new QLabel(secondCell);
    bluetoothIcon->setFixedSize(25,25);

    bluetoothIcon->setPixmap(
        bluetooth.scaled(
            bluetoothIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    wifiIcon = new QLabel(secondCell);
    wifiIcon->setFixedSize(25,25);
    wifiIcon->setPixmap(
        wifi.scaled(
            wifiIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    cellServiceIcon = new QLabel(secondCell);
    cellServiceIcon->setFixedSize(25,25);

    cellServiceIcon->setPixmap(
        cellService.scaled(
            cellServiceIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    gpsIcon = new QLabel(secondCell);
    gpsIcon->setFixedSize(25,25);

    gpsIcon->setPixmap(
        gps.scaled(
            gpsIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
    gearSettingsIcon = new QLabel(secondCell);
    gearSettingsIcon->setFixedSize(25,25);

    gearSettingsIcon->setPixmap(
        gearSettingsImg.scaled(
            gearSettingsIcon->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );

    secondCellLayout->addWidget(bluetoothIcon);
    secondCellLayout->addWidget(wifiIcon);
    secondCellLayout->addWidget(cellServiceIcon);
    secondCellLayout->addWidget(gpsIcon);
    secondCellLayout->addWidget(gearSettingsIcon);
}
