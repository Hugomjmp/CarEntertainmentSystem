//
// Created by Hugo on 05/04/2026.
//

#include "CenterView.h"

void CenterView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    label = new QLabel("text",this);
    label->setStyleSheet("background-color: gray");

    layout->addWidget(label);
}

void CenterView::update() {
}

void CenterView::registerHandlers() {
}

CenterView::CenterView(QWidget *parent) {
    createViews();
    registerHandlers();
    update();
}

CenterView::~CenterView() {
    delete label;
    delete layout;
}
