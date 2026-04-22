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


    mediaPlayerView = new MediaPlayerView(facade);
    musicListView = new MusicListView(facade);

    //rightBoxWidget = musicListView;

    centerContainer->addWidget(mediaPlayerView,1);
    //centerContainer->addWidget(musicListView,1);


    this->setLayout(centerContainer);

}

void CenterView::update() {
}

void CenterView::registerHandlers() {
}