//
// Created by Hugo on 24/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FMPLAYERVIEW_H
#define CARENTERTAINMENTSYSTEM_FMPLAYERVIEW_H
#include <qboxlayout.h>
#include <QLabel>
#include <QPushButton>
#include <qwidget.h>

#include "../../../models/Facade.h"


class FMPlayerView : public QWidget {
private:
    Facade &facade;
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *hLayout = nullptr;
    QLabel *station = nullptr;
    QPushButton *nextStation = nullptr, *previousStation = nullptr, *searchStation = nullptr;
    QWidget *buttonWidget = nullptr;
    void createViews();
    void registerHandlers();
    void update();
    void buttonView();
    void handleNextStationClicked();
    void handlePreviousStationClicked();
    void handleSearchStationClicked();
public:
    FMPlayerView(Facade &facade, QWidget *parent = nullptr);
    ~FMPlayerView() = default;
};


#endif //CARENTERTAINMENTSYSTEM_FMPLAYERVIEW_H
