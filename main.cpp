#include <iostream>
#include <thread>

#include "models/MakeFolder.h"
#include "models/data/Library.h"
#include "models/data/Playlist.h"
#include "ui/ConsoleUI.h"
#include <QApplication>

#include "MainWindow.h"
#include "models/Facade.h"
/*#include <pigpio.h>*/

int main(int argc, char *argv[]) {
    Facade facade;
    QApplication app(argc, argv);
    MainWindow w(facade);
    w.setFixedSize(1024,600);
    w.setWindowTitle("Car Media");
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    //w.showFullScreen();
    w.show();

    return app.exec();

}
