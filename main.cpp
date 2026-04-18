#include <iostream>
#include <QApplication>

#include "MainWindow.h"
#include "models/Facade.h"
#include <QLoggingCategory>
//#include <pigpio.h>
#include <QAudioSource>
#include <QMediaDevices>
#include <QAudioDevice>

int main(int argc, char *argv[]) {

    QLoggingCategory::setFilterRules(
    "*.debug=false\n"
    "*.info=false\n"
    "qt.multimedia.*=false\n"
    "qt.multimedia.ffmpeg.*=false"
);
    QApplication app(argc, argv);
    Facade facade;
    /*gpioCfgPermissions(0);
    if (gpioInitialise() < 0) {
        std::cerr << "Erro pigpio" << std::endl;
    }*/

    /*FOR TESTING PORPOSES*/
    /*const QList<QAudioDevice> devices = QMediaDevices::audioInputs();
    for (const QAudioDevice &device : devices) {
        std::cout << device.description().toStdString() << std::endl;
    }

    QAudioDevice btDevice;
    for (const QAudioDevice &device : devices) {
        if (device.description().contains("Bluetooth", Qt::CaseInsensitive)) {
            btDevice = device;
            break;
        }
    }

    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleFormat(QAudioFormat::Int16);

    QAudioSource *source = new QAudioSource(btDevice, format, nullptr);
    QIODevice *io = source->start();*/
    /*------------------*/

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
