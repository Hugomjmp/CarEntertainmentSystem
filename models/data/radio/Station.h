//
// Created by Hugo on 18/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_STATION_H
#define CARENTERTAINMENTSYSTEM_STATION_H
#include <string>
#include <vector>


class Station {
private:
    std::string name;
    std::string codec;
    std::string url;
    std::string homepage;
    std::string favicon;
    std::string countryCode;
    std::string countryName;
    std::string countrySubdivisionCode;
    std::string countrySubdivision;
    std::string languageCodes;
    std::string languages;
    std::string geoInfo;
public:
    Station(
        const std::string& name, const std::string& codec,
        const std::string& url, const std::string& homepage,
        const std::string& favicon, const std::string& countryCode,
        const std::string& countryName, const std::string& countrySubdivisionCode,
        const std::string& countrySubdivision, const std::string& languageCodes,
        const std::string& languages, const std::string& geoInfo
    ) : name(name), codec(codec), url(url),
        homepage(homepage), favicon(favicon),
        countryCode(countryCode), countryName(countryName),
        countrySubdivisionCode(countrySubdivisionCode),
        countrySubdivision(countrySubdivision), languageCodes(languageCodes),
        languages(languages), geoInfo(geoInfo) {}
    ~Station() = default;
    const std::string& getUrl() const;
    const std::string& getName() const;
    const std::string& getFavicon() const;
    friend std::ostream& operator<< (std::ostream& os, const Station& s);
};



#endif //CARENTERTAINMENTSYSTEM_STATION_H
