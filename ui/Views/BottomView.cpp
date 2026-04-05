//
// Created by Hugo on 05/04/2026.
//

#include "BottomView.h"

void BottomView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    label = new QLabel("text",this);
    label->setStyleSheet("background-color: purple");

    layout->addWidget(label);
}

void BottomView::update() {
}

void BottomView::registerHandlers() {
}

BottomView::BottomView(QWidget *parent) {

    createViews();
    registerHandlers();
    update();
}

BottomView::~BottomView() {
    delete label;
    delete layout;
}
