//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#define CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
#include <QGridLayout>
#include <QStackedLayout>
#include <qwidget.h>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

#include "../../models/Facade.h"

class BottomView : public QWidget {
private:
    Facade &facade;
    QPushButton *volumeHigh = nullptr, *volumeMed = nullptr, *volumeLow = nullptr, *volumeNone = nullptr, *volumeMute = nullptr;
    QSlider *volumeSlider = nullptr;
    QHBoxLayout *layout = nullptr;
    QWidget *volumeWidget = nullptr;
    QStackedLayout *stack = nullptr;
    QTimer *pressTimer = nullptr;
    bool longPressTriggered = false;
    void createViews();
    void update();
    void registerHandlers();
    void loadImages();
    void volumeSliderValueChanged();
    void enableSlider();
    void handleMute();
public:
    BottomView(Facade &facade, QWidget *parent = nullptr);
    ~BottomView() = default;

};



#endif //CARENTERTAINMENTSYSTEM_BOTTOMVIEW_H
