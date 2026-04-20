//
// Created by Hugo on 19/04/2026.
//

#ifndef CARENTERTAINMENTSYSTEM_MUSICLISTVIEW_H
#define CARENTERTAINMENTSYSTEM_MUSICLISTVIEW_H
#include <qboxlayout.h>
#include <qwidget.h>
#include <qlistwidget.h>
#include <../../../models/Facade.h>

class MusicListView : public QWidget {
private:
    Facade& facade;
    QVBoxLayout* mainLayout;
    QListWidget* listWidget;
    QImage img;
    void createViews();
    void update();
    void registerHandlers();
    void handleItemClicked(QListWidgetItem *item);
    void createLocalMusicListView();
    void createInternetRadioListView();
    void sourceTypeChanged();
public:
    MusicListView(Facade &facade, QWidget *parent = nullptr);
    ~MusicListView() = default;


};



#endif //CARENTERTAINMENTSYSTEM_MUSICLISTVIEW_H
