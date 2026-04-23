//
// Created by Hugo on 18/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_ONLINERADIOLIBRARY_H
#define CARENTERTAINMENTSYSTEM_ONLINERADIOLIBRARY_H
#include <vector>

#include "Station.h"
#include <QJsonDocument>
#include <iostream>
#include <qeventloop.h>
#include <qurl.h>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>

class OnlineRadioLibrary {
private:
    std::vector<Station> stationLibrary;
    void loadStationLibrary();
    std::vector<unsigned char> downloadFavicon(const std::string& url) const;
public:
    OnlineRadioLibrary();
    ~OnlineRadioLibrary() = default;
    const std::vector<Station>& getStationLibrary() const;

};



#endif //CARENTERTAINMENTSYSTEM_ONLINERADIOLIBRARY_H
