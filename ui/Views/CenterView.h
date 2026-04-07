//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#define CARENTERTAINMENTSYSTEM_CENTERVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>
#include <QProgressBar>
#include <QStackedLayout>

class CenterView : public QWidget {
private:
    //QPixmap musicImage, previousSong, playSong, pauseSong, nextSong, repeat;
    QLabel *songName = nullptr, *currentSongTime = nullptr, *finalSongTime = nullptr,
            *musicImage = nullptr, *previousIcon = nullptr, *playIcon = nullptr,
            *pauseIcon = nullptr, *nextIcon = nullptr, *repeatIcon = nullptr;

    QHBoxLayout *centerContainer = nullptr;
    QHBoxLayout *HBoxButtons = nullptr, *centerLayout = nullptr, *HBoxSongTime = nullptr;
    QVBoxLayout *leftVBox = nullptr, *rightVBox = nullptr;
    QStackedLayout *stack = nullptr;
    QProgressBar *progressBar = nullptr;
    QWidget *HBoxButtonsWidget = nullptr, *leftBoxWidget = nullptr,
            *rightBoxWidget = nullptr, *stackContainer = nullptr,
            *HBoxSongTimeWidget = nullptr;
    void loadImages();
    void hboxSongButtons();
    void hboxSongTime();
    void timeLapseBar();
    void leftVBoxConfig();
    void createViews();
    void update();
    void registerHandlers();
public:
    CenterView(QWidget *parent = nullptr);
    ~CenterView();

};



#endif //CARENTERTAINMENTSYSTEM_CENTERVIEW_H
