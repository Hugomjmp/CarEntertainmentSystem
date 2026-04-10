#include <QApplication>

#include <iostream>
#include "MainWindow.h"
#include "models/Facade.h"
#include <pigpio.h>

int main(int argc, char *argv[]) {
    /*Facade facade;
    gpioInitialise();
    QApplication app(argc, argv);
    MainWindow w(facade);
    w.setFixedSize(1024,600);
    w.setWindowTitle("Car Media");
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    //w.showFullScreen();
    w.show();

    int result = app.exec();
    gpioTerminate();
    return result;*/

    gpioInitialise();

    int handle = serOpen("/dev/serial0", 9600, 0);
    if (handle == -1) {
        std::cerr << "Error opening serial port" << std::endl;
    }
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    while (true) {
        int count = serRead(handle, buffer, sizeof(buffer) - 1);

        if (count > 0) {
            buffer[count] = '\0';
            std::cout << buffer << std::endl;
        }

        gpioDelay(100000);
    }

    serClose(handle);


    gpioTerminate();

}
