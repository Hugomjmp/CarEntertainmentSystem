//
// Created by Hugo on 05/04/2026.
//

#include "CenterView.h"

#include <iostream>
#include <QPushButton>

#include "BottomView.h"
#include "../../models/Facade.h"

CenterView::CenterView(Facade &facade, QWidget *parent) : facade(facade) {

    createViews();
    registerHandlers();
    update();
}

void CenterView::createViews() {
    centerContainer = new QHBoxLayout(this);
    centerContainer->setContentsMargins(0,0,0,0);
    centerContainer->setSpacing(0);

    stackedLeftLayout = new QStackedLayout();
    stackedLeftLayout->setContentsMargins(0,0,0,0);
    stackedLeftLayout->setSpacing(0);

    stackedRightLayout = new QStackedLayout();
    stackedRightLayout->setContentsMargins(0,0,0,0);
    stackedRightLayout->setSpacing(0);

    leftWidget = new QWidget();
    leftWidget->setLayout(stackedLeftLayout);

    rightWidget = new QWidget();
    rightWidget->setLayout(stackedRightLayout);

    emptyWidget = new QWidget();

    mediaPlayerView = new MediaPlayerView(facade);
    musicListView = new MusicListView(facade);
    fmPlayerView = new FMPlayerView(facade);


    stackedLeftLayout->addWidget(mediaPlayerView);
    stackedLeftLayout->addWidget(fmPlayerView);

    stackedRightLayout->addWidget(musicListView);
    stackedRightLayout->addWidget(emptyWidget);

    centerContainer->addWidget(leftWidget,1);
    centerContainer->addWidget(rightWidget,1);




    //centerContainer->addWidget(mediaPlayerView,1);
    //centerContainer->addWidget(fmPlayerView,1);
    //centerContainer->addWidget(musicListView,1);
    this->setLayout(centerContainer);
}

void CenterView::update() {
    std::cout << "CenterView::update()" << std::endl;
    switch (facade.getSourceType())
    {
        case LOCAL_MUSIC: {
            stackedLeftLayout->setCurrentIndex(0);
            stackedRightLayout->setCurrentIndex(0);

        }
            break;
        case INTERNET_RADIO: {
            stackedLeftLayout->setCurrentIndex(0);
            stackedRightLayout->setCurrentIndex(0);

        }
            break;
        case FM_RADIO: {
            stackedLeftLayout->setCurrentIndex(1);
            stackedRightLayout->setCurrentIndex(1);
        }
            break;
    }
}

void CenterView::registerHandlers() {
    QObject::connect(&facade, &Facade::sourceTypeChanged, this, &CenterView::update);
}
