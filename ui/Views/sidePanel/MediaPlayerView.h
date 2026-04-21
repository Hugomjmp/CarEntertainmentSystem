//
// Created by Hugo on 21/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MEDIAPLAYERVIEW_H
#define CARENTERTAINMENTSYSTEM_MEDIAPLAYERVIEW_H
#include <qboxlayout.h>
#include <qwidget.h>
#include <../../../models/Facade.h>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QStackedLayout>

class MediaPlayerView : public QWidget {
private:
    Facade &facade;
    QLabel *mediaName = nullptr, *currentSongTime = nullptr, *finalSongTime = nullptr,
        *musicImage = nullptr;
    QPushButton *playButton = nullptr, *pauseButton = nullptr, *repeatButton = nullptr,
            *nextButton = nullptr, *previousButton = nullptr;
    QWidget *HBoxButtonsWidget = nullptr,
            *stackContainer = nullptr,
            *HBoxSongTimeWidget = nullptr;
    QImage image;
    QHBoxLayout *HBoxButtons = nullptr, *HBoxSongTime = nullptr;
    QProgressBar *progressBar = nullptr;
    QStackedLayout *stack = nullptr;
    QVBoxLayout *VBox = nullptr;
    void createViews();
    void update();
    void registerHandlers();
    void VBoxConfig();
    void hboxSongButtons();
    void hboxSongTime();
    void timeLapseBar();
    void handlePlayClicked();
    void handlePauseClicked();
    void handleNextClicked();
    void handlePreviousClicked();
    void handleRepeatClicked();
    void handleUpdatePosition(qint64 position);
    void handleUpdateDuration(qint64 duration);
    QString msToString(qint64 ms);
public:
    MediaPlayerView(Facade &facade, QWidget *parent = nullptr);
    ~MediaPlayerView() = default;
};



#endif //CARENTERTAINMENTSYSTEM_MEDIAPLAYERVIEW_H
