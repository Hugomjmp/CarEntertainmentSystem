#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    gridLayout = new QGridLayout(centralWidget);

    topView = new TopView();
    bottomView = new BottomView();
    leftView = new LeftView();
    rightView = new RightView();
    centerView = new CenterView();

    createViews();
    update();
    registerHandlers();
}

MainWindow::~MainWindow() {
    delete centralWidget;
    delete gridLayout;
    delete topView;
    delete bottomView;
    delete leftView;
    delete rightView;
    delete centerView;
}

void MainWindow::createViews() {
    this->setStyleSheet("background-color: #121212");
    setupLayout();


    /*QLabel *label = new QLabel("Text",this);
    QLabel *label1 = new QLabel("Text1",this);
    QLabel *label2 = new QLabel("Text2",this);
    QLabel *label3 = new QLabel("Text3",this);
    QLabel *label4 = new QLabel("Text4",this);
    label->setStyleSheet("background-color: red");
    label1->setStyleSheet("background-color: green");
    label2->setStyleSheet("background-color: blue");
    label3->setStyleSheet("background-color: gray");
    label4->setStyleSheet("background-color: purple");*/

    /*gridLayout->addWidget(label,0,0,5,1);
    gridLayout->addWidget(label1,0,1,1,3);
    gridLayout->addWidget(label2,4,1,1,3);
    gridLayout->addWidget(label3,1,1,3,3);
    gridLayout->addWidget(label4,0,4,5,1);*/
    gridLayout->addWidget(topView,0,1,1,3);
    gridLayout->addWidget(leftView,0,0,5,1);
    gridLayout->addWidget(rightView,0,4,5,1);
    gridLayout->addWidget(centerView,1,1,3,3);
    gridLayout->addWidget(bottomView,4,1,1,3);
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
