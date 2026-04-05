#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

#include "UI/Views/BottomView.h"
#include "UI/Views/CenterView.h"
#include "UI/Views/LeftView.h"
#include "UI/Views/RightView.h"
#include "UI/Views/TopView.h"

#ifndef CARENTERTAINMENTSYSTEM_MAINWINDOW_H
#define CARENTERTAINMENTSYSTEM_MAINWINDOW_H



class MainWindow : public QMainWindow{
private:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    TopView *topView;
    BottomView *bottomView;
    LeftView *leftView;
    RightView *rightView;
    CenterView *centerView;

    void createViews();
    void update();
    void registerHandlers();

    void setupLayout();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};



#endif //CARENTERTAINMENTSYSTEM_MAINWINDOW_H
