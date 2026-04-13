#include <QApplication>

#include <iostream>
#include "MainWindow.h"
#include "models/Facade.h"
#include <QLoggingCategory>
//#include <pigpio.h>

int main(int argc, char *argv[]) {

    QLoggingCategory::setFilterRules(
    "*.debug=false\n"
    "*.info=false\n"
    "qt.multimedia.*=false\n"
    "qt.multimedia.ffmpeg.*=false"
);
    QApplication app(argc, argv);
    Facade facade;
    //gpioInitialise();

    MainWindow w(facade);
    w.setFixedSize(1024,600);
    w.setWindowTitle("Car Media");
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    //w.showFullScreen();
    w.show();

    int result = app.exec();
    //gpioTerminate();
    return result;
}
