//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_TOPVIEW_H
#define CARENTERTAINMENTSYSTEM_TOPVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class TopView : public QWidget {
private:
    QGridLayout *layout = nullptr;
    QLabel *label = nullptr;

    void createViews();
    void update();
    void registerHandlers();
public:
    TopView(QWidget *parent = nullptr);
    ~TopView();


};



#endif //CARENTERTAINMENTSYSTEM_TOPVIEW_H
