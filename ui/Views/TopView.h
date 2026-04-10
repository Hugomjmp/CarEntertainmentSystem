//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_TOPVIEW_H
#define CARENTERTAINMENTSYSTEM_TOPVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>

class TopView : public QWidget {
private:
    QGridLayout *layout = nullptr;
    QPixmap fan, bluetooth, wifi, cellService, gps, gearSettingsImg;
    QLabel *temperature = nullptr, *fanStatus = nullptr, *time = nullptr;
    QLabel *fanSpeedIcon = nullptr, *bluetoothIcon = nullptr, *wifiIcon = nullptr,
            *cellServiceIcon = nullptr, *gpsIcon = nullptr, *gearSettingsIcon = nullptr;
    QWidget *firstCell = nullptr, *secondCell = nullptr;
    QHBoxLayout *firstCellLayout = nullptr;
    QHBoxLayout *secondCellLayout = nullptr;

    QTimer *timer = nullptr;

    void createViews();
    void update();
    void registerHandlers();
    void loadImages();
    void firstCellConfig();
    void secondCellConfig();
public:
    TopView(QWidget *parent = nullptr);
    ~TopView() = default;


};



#endif //CARENTERTAINMENTSYSTEM_TOPVIEW_H
