//
// Created by Hugo on 18/04/2026.
//

#include "OnlineRadioLibrary.h"

#include <iostream>
#include <qeventloop.h>
#include <qurl.h>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>

OnlineRadioLibrary::OnlineRadioLibrary() {
    loadStationLibrary();
}

void OnlineRadioLibrary::loadStationLibrary() {
    QNetworkAccessManager manager;

    QUrl url("https://de2.api.radio-browser.info/json/stations/bycountry/Portugal");

    QNetworkRequest request(url);

    QNetworkReply* reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());

    QJsonArray array = jsonDocument.array();


    for (const QJsonValue & element: array) {
        auto obj = element.toObject();

        if (obj.contains("codec")) {
            double geoLat = obj["geo_lat"].toDouble();
            double geoLong = obj["geo_long"].toDouble();

            stationLibrary.push_back({
                obj["name"].toString().toStdString(),
                obj["codec"].toString().toStdString(),
                obj["url"].toString().toStdString(),
                obj["homepage"].toString().toStdString(),
                obj["favicon"].toString().toStdString(),
                obj["countrycode"].toString().toStdString(),
                obj["country"].toString().toStdString(),
                obj["countrySubdivisionCode"].toString().toStdString(),
                obj["state"].toString().toStdString(),
                obj["languagecodes"].toString().toStdString(),
                obj["language"].toString().toStdString(),
                std::to_string(geoLat) + " / " + std::to_string(geoLong)
            });
        }
    }
}

std::vector<unsigned char> OnlineRadioLibrary::downloadFavicon(const std::string &url) const {
    if (url.empty()) return {};

    QNetworkAccessManager manager;
    QEventLoop loop;
    std::vector<unsigned char> imageData;

    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(QString::fromStdString(url))));

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            imageData.assign(data.begin(), data.end());
        }
        reply->deleteLater();
        loop.quit();
    });

    loop.exec();
    return imageData;
}

const std::vector<Station> & OnlineRadioLibrary::getStationLibrary() const {
    return stationLibrary;
}
