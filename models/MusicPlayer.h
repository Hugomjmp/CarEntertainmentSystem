//
// Created by Hugo on 19/03/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MUSICPLAYER_H
#define CARENTERTAINMENTSYSTEM_MUSICPLAYER_H
#include "data/local_music/Library.h"
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <qobject.h>

#include "data/radio/Station.h"
//#include "SFML/Audio/Music.hpp"

/**
 * Class responsible to play the music.
 */
class MusicPlayer : public QObject {
    Q_OBJECT
private:
    QMediaPlayer* player = nullptr;
    QAudioOutput* audio = nullptr;
    //sf::Music music;
    int currentSong = 0;
    bool playlistLoop = false;
    bool mute = false;
    int currentSongTime = 0;
    bool shouldRestorePosition = false;
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
public:
    MusicPlayer();
    ~MusicPlayer();

    bool playSong(const Song &song);
    bool playRadio(const Station &station);
    bool stopSong();
    void pauseSong();
    bool setVolume(float volume);
    float getVolume();
    void setMute();
    std::string getCurrentSongTime() const;
    void setCurrentSongTime(std::string currentSongTime);
    std::string getSongDuration() const;
signals:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);

};


#endif //CARENTERTAINMENTSYSTEM_MUSICPLAYER_H