//
// Created by Hugo on 05/04/2026.
//

#include "TopView.h"

#include <iostream>
#include <QTimer>

#include "../../models/data/DHT11.h"

TopView::TopView(QWidget *parent) : QWidget(parent) {

    createViews();
    registerHandlers();
    update();
}

void TopView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    temperature = new QLabel("19ºC",this);
    temperature->setStyleSheet("color: white; font-weight: bold; font-family: Arial;font-size: 18px;");
    temperature->setMaximumWidth(100);
    loadImages();
    firstCellConfig();
    secondCellConfig();


    layout->addWidget(temperature,0,1);
    layout->addWidget(firstCell,0,2);
    layout->addWidget(secondCell,0,3);

}

void TopView::update() {
}


/*
 * REVIEW THIS AFTER....
 */
void TopView::registerHandlers() {
    timer = new QTimer(this);


    QObject::connect(timer, &QTimer::timeout, this, [=]() {
        DHT11 dht11;
        dht11.readSensorData();
        temperature->setText(QString::number(dht11.getTemperature()) + "ºC" );
    });
    QObject::connect(timer, &QTimer::timeout, this, [=]() {
        const auto now = std::chrono::zoned_time{std::chrono::current_zone(), std::chrono::system_clock::now()};
        std::string timeStamp = std::format("{:%H:%M}", now);
        time->setText(QString::fromStdString(timeStamp));
    });
    timer->start(2000);

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
    firstCellLayout->setSpacing(10);

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

    bluetoothIcon = new QLabel(secondCell);
    bluetoothIcon->setFixedSize(15,25);

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

    //to remove later, just for testing
    time = new QLabel("12:30",secondCell);
    time->setStyleSheet(
     "color: white;"
        "font-weight: bold;"
        "font-family: Arial;"
        "font-size: 24px;"
    );

    secondCellLayout->addWidget(bluetoothIcon);
    secondCellLayout->addWidget(wifiIcon);
    secondCellLayout->addWidget(cellServiceIcon);
    secondCellLayout->addWidget(gpsIcon);
    secondCellLayout->addWidget(gearSettingsIcon);
    secondCellLayout->addWidget(time);
    secondCellLayout->setSpacing(5);
    secondCellLayout->setAlignment(Qt::AlignRight);
}
