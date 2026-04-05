//
// Created by Hugo on 05/04/2026.
//

#include "LeftView.h"

void LeftView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    label = new QLabel("text",this);
    label->setStyleSheet("background-color: green");

    layout->addWidget(label);
}

void LeftView::update() {
}

void LeftView::registerHandlers() {
}

LeftView::LeftView(QWidget *parent) {


    createViews();
    registerHandlers();
    update();

}

LeftView::~LeftView() {
    delete label;
    delete layout;
}
