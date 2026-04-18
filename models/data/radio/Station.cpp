//
// Created by Hugo on 18/04/2026.
//

#include "Station.h"

#include <ostream>

const std::string & Station::getUrl() const {
    return url;
}

const std::string & Station::getName() const {
    return name;
}

const std::string & Station::getFavicon() const {
    return favicon;
}

std::ostream & operator<<(std::ostream &os, const Station &s) {
    os << "Station: \n"
    << "name = " << s.name << "\n"
    << "codec = " << s.codec << "\n"
    << "url = " << s.url << "\n"
    << "homepage = " << s.homepage << "\n"
    << "favicon = " << s.favicon << "\n"
    << "countryCode = " << s.countryCode << "\n"
    << "country = " << s.countryName << "\n"
    << "countrySubdivisionCode = " << s.countrySubdivisionCode << "\n"
    << "countrySubdivision = " << s.countrySubdivision << "\n"
    << "languagesCodes = " << s.languageCodes << "\n"
    << "languages = " << s.languages << "\n"
    << "geoInfo = " << s.geoInfo
    << std::endl;
    return os;
}
