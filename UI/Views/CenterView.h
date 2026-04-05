//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#define CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class CenterView : public QWidget {
private:
    QLabel *label = nullptr;
    QGridLayout *layout = nullptr;

    void createViews();
    void update();
    void registerHandlers();
public:
    CenterView(QWidget *parent = nullptr);
    ~CenterView();

};



#endif //CARENTERTAINMENTSYSTEM_CENTERVIEW_H
