//
// Created by Hugo on 05/04/2026.
//

#include "RightView.h"

void RightView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    label = new QLabel("text",this);
    label->setStyleSheet("background-color: blue");

    layout->addWidget(label);
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

RightView::~RightView() {
    delete label;
    delete layout;
}
