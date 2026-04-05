//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_LEFTVIEW_H
#define CARENTERTAINMENTSYSTEM_LEFTVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class LeftView : public QWidget {
private:
    QLabel *label = nullptr;
    QGridLayout *layout = nullptr;
    void createViews();
    void update();
    void registerHandlers();
public:
    LeftView(QWidget *parent = nullptr);
    ~LeftView();

};



#endif //CARENTERTAINMENTSYSTEM_LEFTVIEW_H
