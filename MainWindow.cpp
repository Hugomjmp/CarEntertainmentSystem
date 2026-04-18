#include "MainWindow.h"

#include "models/Facade.h"


MainWindow::MainWindow(Facade &facade,QWidget *parent) : facade(facade),QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);

    topView = new TopView(facade);
    bottomView = new BottomView(facade);
    leftView = new LeftView(facade);
    rightView = new RightView();
    centerView = new CenterView(facade);
    createViews();
    update();
    registerHandlers();
}

void MainWindow::createViews() {
    this->setStyleSheet("background-color: #121212");
    setupLayout();

    gridLayout->addWidget(topView,0,1,1,3);
    gridLayout->addWidget(leftView,0,0,5,1);
    gridLayout->addWidget(rightView,0,4,5,1);
    gridLayout->addWidget(centerView,1,1,3,3);
    gridLayout->addWidget(bottomView,4,1,1,3);
    gridLayout->setAlignment(bottomView,Qt::AlignVCenter);
    gridLayout->setContentsMargins(0,0,0,0);
    gridLayout->setSpacing(0);

}

void MainWindow::setupLayout() {
    int rowHeight[5] = {50, 200, 200, 100, 50}; //600
    int columnWidth[5] = {50, 100, 412, 412, 50}; //1024

    for (int r = 0; r < 5; r++) {
        gridLayout->setRowMinimumHeight(r, rowHeight[r]);
    }
    for (int c = 0; c < 5; c++) {
        gridLayout->setColumnMinimumWidth(c, columnWidth[c]);
    }
}

void MainWindow::update() {

}

void MainWindow::registerHandlers() {
}
