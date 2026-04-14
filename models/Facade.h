//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FACADE_H
#define CARENTERTAINMENTSYSTEM_FACADE_H
#include "MakeFolder.h"
#include "MusicPlayer.h"
#include "data/Library.h"
#include "data/Media.h"
#include "data/sensor/GPIO.h"


class Facade : public QObject {
    Q_OBJECT
private:
    GPIO * gpio = nullptr;
    MakeFolder *make_Folder = nullptr;
    Library *library = nullptr;
    MusicPlayer *music_Player = nullptr;
    Media *media = nullptr;
    bool isPlaying = false;
public:
    Facade();
    ~Facade();
    void play();
    void pause();
    void nextSong();
    void previousSong();
    double getVolume() const;
    void setVolume(double volume);
    const Song & getSong() const;
    void setMute();
    std::string getSongDuration() const;
    std::string getSongCurrentTime() const;
    MusicPlayer * getMusicPlayer() const;
    GPIO * getGPIO() const;
signals:
    void positionChanged(qint64  position);
    void durationChanged(qint64 duration);
};



#endif //CARENTERTAINMENTSYSTEM_FACADE_H
