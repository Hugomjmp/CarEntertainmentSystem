//
// Created by Hugo on 24/04/2026.
//

#include "FMPlayerView.h"

FMPlayerView::FMPlayerView(Facade &facade, QWidget *parent) : facade(facade){


    createViews();
    update();
    registerHandlers();
}

void FMPlayerView::createViews() {
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignVCenter);

    station = new QLabel("FM 90.0");
    station->setStyleSheet(
        "font-size: 50px;"
        "color: white;"
        "font-weight: bold;"
    );
    station->setAlignment(Qt::AlignCenter);
    buttonView();

    mainLayout->addWidget(station);
    mainLayout->addLayout(hLayout);
}

void FMPlayerView::buttonView() {
    hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 100, 0, 0);
    hLayout->setSpacing(80);
    hLayout->setAlignment(Qt::AlignCenter);

    previousStation = new QPushButton("");
    previousStation->setIcon(QIcon("resources/img/backward-solid_W.png"));
    previousStation->setIconSize(QSize(25,25));
    previousStation->setStyleSheet("border: none;");

    nextStation = new QPushButton("");
    nextStation->setIcon(QIcon("resources/img/forward-solid_W.png"));
    nextStation->setIconSize(QSize(25,25));
    nextStation->setStyleSheet("border: none;");

    searchStation = new QPushButton("");
    searchStation->setIcon(QIcon("resources/img/tower-cell-solid_W.png"));
    searchStation->setIconSize(QSize(25,25));
    searchStation->setStyleSheet("border: none;");

    hLayout->addWidget(previousStation);
    hLayout->addWidget(nextStation);
    hLayout->addWidget(searchStation);
}

void FMPlayerView::registerHandlers() {
    QObject::connect(previousStation, &QPushButton::clicked, this, &FMPlayerView::handlePreviousStationClicked);
    QObject::connect(nextStation, &QPushButton::clicked, this, &FMPlayerView::handleNextStationClicked);
    QObject::connect(searchStation, &QPushButton::clicked, this, &FMPlayerView::handleSearchStationClicked);
}

void FMPlayerView::update() {
}

void FMPlayerView::handleNextStationClicked() {
    facade.nextFMStation();
    std::cout << "Next Station Clicked" << std::endl;
}

void FMPlayerView::handlePreviousStationClicked() {
    facade.previousFMStation();
    std::cout << "Previous Station Clicked" << std::endl;
}

void FMPlayerView::handleSearchStationClicked() {
    std::cout << "Search Station Clicked" << std::endl;
}
