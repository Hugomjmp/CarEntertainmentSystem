//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#define CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#include <QGridLayout>
#include <QStackedLayout>
#include <qwidget.h>
#include <QLabel>
#include <QSlider>

class BottomView : public QWidget {
private:
    QPixmap volumeHigh, volumeMed, volumeLow, volumeNone, volumeMute;
    QLabel *volumeHighIcon = nullptr, *volumeMedIcon = nullptr, *volumeLowIcon = nullptr, *volumeNoneIcon = nullptr, *volumeMuteIcon = nullptr;
    QSlider *volumeSlider = nullptr;
    QGridLayout *layout = nullptr;
    QStackedLayout *stack = nullptr;
    void createViews();
    void update();
    void registerHandlers();
    void loadImages();
public:
    BottomView(QWidget *parent = nullptr);
    ~BottomView();

};



#endif //CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
