//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#define CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class BottomView : public QWidget {
private:
    QLabel *label = nullptr;
    QGridLayout *layout = nullptr;
    void createViews();
    void update();
    void registerHandlers();
public:
    BottomView(QWidget *parent = nullptr);
    ~BottomView();

};



#endif //CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
