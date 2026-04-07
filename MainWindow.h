#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

#include "models/Facade.h"
#include "ui/Views/BottomView.h"
#include "ui/Views/CenterView.h"
#include "ui/Views/LeftView.h"
#include "ui/Views/RightView.h"
#include "ui/Views/TopView.h"

#ifndef CARENTERTAINMENTSYSTEM_MAINWINDOW_H
#define CARENTERTAINMENTSYSTEM_MAINWINDOW_H



class MainWindow : public QMainWindow{
private:
    Facade &facade;
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
    MainWindow(Facade &facade, QWidget *parent = nullptr);
    ~MainWindow() = default;

};



#endif //CARENTERTAINMENTSYSTEM_MAINWINDOW_H
