
#ifndef CARENTERTAINMENTSYSTEM_MUSIC_H
#define CARENTERTAINMENTSYSTEM_MUSIC_H
#include <string>


class Song {
private:
    std::string title;
    std::string album;
    int year;
    int number;
    std::string genre;
    int duration;
    std::string location;
public:
    Song(const std::string& title, const std::string& album, int year, int number, const std::string& genre, int duration, const std::string& location)
        : title(title), album(album), year(year), number(number), genre(genre), duration(duration), location(location) {}
    ~Song() = default;

    std::string getTitle() const;
    std::string getAlbum() const;
    int getYear() const;
    int getNumber() const;
    std::string getGenre() const;
    int getDuration() const;
    std::string getLocation() const;

    friend std::ostream& operator<<(std::ostream& os, const Song& song);
};



#endif //CARENTERTAINMENTSYSTEM_MUSIC_H