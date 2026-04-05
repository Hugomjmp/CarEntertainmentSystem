//
// Created by Hugo on 05/04/2026.
//

#include "TopView.h"
TopView::TopView(QWidget *parent) : QWidget(parent) {

    createViews();
    registerHandlers();
    update();
}

TopView::~TopView() {
    delete label;
    delete label;
}
void TopView::createViews() {
    layout = new QGridLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    label = new QLabel("text",this);
    label->setStyleSheet("background-color: red");

    layout->addWidget(label);

}

void TopView::update() {
}

void TopView::registerHandlers() {
}


