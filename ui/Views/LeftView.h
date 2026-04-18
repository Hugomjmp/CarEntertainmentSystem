//
// Created by Hugo on 05/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_LEFTVIEW_H
#define CARENTERTAINMENTSYSTEM_LEFTVIEW_H
#include <QGridLayout>
#include <qwidget.h>
#include <QLabel>
#include <QPushButton>

#include "SourceView.h"

class LeftView : public QWidget {
private:
    Facade &facade;
    SourceView *sourceView;
    QPixmap source, navigation, fan;
    QPushButton *sourceButton = nullptr;
    QLabel *navigationIcon = nullptr, *fanIcon = nullptr;
    QGridLayout *layout = nullptr;
    void createViews();
    void update();
    void registerHandlers();
    void handleSourceButtonClicked();
public:
    LeftView(Facade &facade, QWidget *parent = nullptr);
    ~LeftView() = default;
    void loadImages();
};



#endif //CARENTERTAINMENTSYSTEM_LEFTVIEW_H
