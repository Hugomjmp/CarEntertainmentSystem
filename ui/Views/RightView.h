//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_RIGHTVIEW_H
#define CARENTERTAINMENTSYSTEM_RIGHTVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class RightView : public QWidget {
private:
    QPixmap phone, apps, car;
    QLabel *phoneImg = nullptr, *appsImg = nullptr, *carImg = nullptr;
    QGridLayout *layout = nullptr;

    void createViews();
    void update();
    void registerHandlers();
    void loadImages();
public:
    RightView(QWidget *parent = nullptr);
    ~RightView() = default;

};



#endif //CARENTERTAINMENTSYSTEM_RIGHTVIEW_H
