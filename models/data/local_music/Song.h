
#ifndef CARENTERTAINMENTSYSTEM_MUSIC_H
#define CARENTERTAINMENTSYSTEM_MUSIC_H
#include <string>
#include <vector>


class Song {
private:
    std::string title;
    std::string album;
    std::string artist;
    int year;
    int number;
    std::string genre;
    int duration;
    std::string location;
    std::vector<unsigned char> image;
public:
    Song(const std::string& title, const std::string& album,const std::string& artist,
        int year, int number, const std::string& genre, int duration,
        const std::string& location, const std::vector<unsigned char>& image
        )
        : title(title), album(album), artist(artist),year(year), number(number),
            genre(genre), duration(duration), location(location), image(image) {}
    ~Song() = default;

    std::string getTitle() const;
    std::string getAlbum() const;
    std::string getArtist() const;
    int getYear() const;
    int getNumber() const;
    std::string getGenre() const;
    int getDuration() const;
    std::string getLocation() const;
    const std::vector<unsigned char>& getImage() const;


};
    std::ostream& operator<<(std::ostream& os, const Song& song);


#endif //CARENTERTAINMENTSYSTEM_MUSIC_H