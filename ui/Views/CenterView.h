//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#define CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QStackedLayout>
#include "../../models/Facade.h"
#include "sidePanel/MediaPlayerView.h"
#include "sidePanel/MusicListView.h"


class CenterView : public QWidget {
private:
    Facade &facade;
    QHBoxLayout *centerContainer = nullptr;
    QHBoxLayout *centerLayout = nullptr;
    QVBoxLayout *rightVBox = nullptr;
    MediaPlayerView *mediaPlayerView = nullptr;
    MusicListView *musicListView = nullptr;
    void createViews();
    void registerHandlers();
    void update();
public:
    CenterView(Facade &facade, QWidget *parent = nullptr);
    ~CenterView() = default;

};



#endif //CARENTERTAINMENTSYSTEM_CENTERVIEW_H
