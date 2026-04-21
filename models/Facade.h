//
// Created by Hugo on 07/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_FACADE_H
#define CARENTERTAINMENTSYSTEM_FACADE_H
#include "MakeFolder.h"
#include "MusicPlayer.h"
#include "data/SessionState.h"
#include "data/local_music/Library.h"
#include "data/local_music/Media.h"
#include "data/enums/SourceType.h"
#include "data/radio/InternetRadio.h"
#include "data/radio/OnlineRadioLibrary.h"
#include "data/sensor/GPIO.h"


class Facade : public QObject {
    Q_OBJECT
private:
    SessionState session;
    GPIO * gpio = nullptr;
    MakeFolder *make_Folder = nullptr;
    Library *library = nullptr;
    OnlineRadioLibrary * onlineRadio = nullptr;
    MusicPlayer *music_Player = nullptr;
    Media *media = nullptr;
    InternetRadio *internetRadio = nullptr;
    bool isPlaying = false;
    SourceType sourceType;
public:
    Facade();
    ~Facade();
    void setSourceType(SourceType newSourceType);
    const SourceType & getSourceType() const;
    void play();
    void pause();
    void nextSong();
    void previousSong();
    float getVolume() const;
    void setVolume(double volume);
    const Song & getSong() const;
    const Station & getStation() const;
    const std::vector<Station> & getStations() const;
    void setMute();
    std::string getSongDuration() const;
    std::string getSongCurrentTime() const;
    MusicPlayer * getMusicPlayer() const;
    GPIO * getGPIO() const;
    bool getPlayStatus() const;
    const std::vector<Song> & getSongs() const;
    void setTrack(int newTrackNumber);
    void setStation(int newStationNumber);
signals:
    void positionChanged(qint64  position);
    void durationChanged(qint64 duration);
    void sourceTypeChanged();
};



#endif //CARENTERTAINMENTSYSTEM_FACADE_H
