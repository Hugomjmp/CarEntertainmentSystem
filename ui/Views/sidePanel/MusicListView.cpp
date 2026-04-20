//
// Created by Hugo on 19/04/2026.
//

#include "MusicListView.h"

#include <iostream>
#include <QLabel>

MusicListView::MusicListView(Facade &facade, QWidget *parent) : facade(facade) {
    createViews();
    registerHandlers();
    update();

    connect(&facade, &Facade::sourceTypeChanged, this, &MusicListView::sourceTypeChanged);
}

void MusicListView::createViews() {
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    listWidget = new QListWidget();
    listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget->setLayoutMode(QListView::SinglePass);
    listWidget->setResizeMode(QListView::Adjust);

    mainLayout->addWidget(listWidget);
    switch (facade.getSourceType()) {
        case LOCAL_MUSIC:
            createLocalMusicListView();
            break;
        case INTERNET_RADIO:
            createInternetRadioListView();
            break;
    }
}

void MusicListView::createLocalMusicListView() {
    int index = 0;
    listWidget->clear();
    for (const Song & song: facade.getSongs()) {
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);

        QLabel* image = new QLabel();
        image->setFixedSize(50,50);

        if (song.getImage().empty()) {
            image->setPixmap(
                QPixmap("resources/img/defaultMusic.png").scaled(
                    image->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );
        } else {
            img.loadFromData(song.getImage().data(), song.getImage().size());
            image->setPixmap(
                QPixmap::fromImage(img).scaled(
                    image->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );
        }
        QLabel* label = new QLabel(
            QString::fromStdString(song.getTitle() + " - " + song.getArtist())
        );

        layout->addWidget(image);
        layout->addWidget(label);

        QListWidgetItem* item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());

        item->setData(Qt::UserRole, index);

        listWidget->addItem(item);
        listWidget->setItemWidget(item, widget);
        index++;
    }
    listWidget->setStyleSheet(R"(
        QScrollBar:vertical {
            width: 6px;
            margin: 0px;
            border-radius: 4px;
        }
        QScrollBar::handle:vertical {
            background: white;
            border-radius: 3px;
        }
        QScrollBar::sub-line:vertical {
            height: 0px;
        }
        QScrollBar::add-line:vertical {
            height: 0px;
        }
        QScrollBar::up-arrow:vertical,
        QScrollBar::down-arrow:vertical {
            height: 0px;
        }
        QScrollBar::add-page:vertical,
        QScrollBar::sub-page:vertical {
            background: #333;
            border-radius: 3px;
        }
        QListWidget{
            border: none;
        }
    )");
}

void MusicListView::createInternetRadioListView() {
    int index = 0;
    listWidget->clear();
    for (const Station & station: facade.getStations()) {
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);

        QLabel* image = new QLabel();
        image->setFixedSize(50,50);

        /*if (station.getImage().empty()) {*/
            image->setPixmap(
                QPixmap("resources/img/defaultMusic.png").scaled(
                    image->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );
        /*} else {
            img.loadFromData(station.getImage());
            image->setPixmap(
                QPixmap::fromImage(img).scaled(
                    image->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                )
            );
        }*/
        QLabel* label = new QLabel(
            QString::fromStdString(station.getName())
        );

        layout->addWidget(image);
        layout->addWidget(label);

        QListWidgetItem* item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());

        item->setData(Qt::UserRole, index);

        listWidget->addItem(item);
        listWidget->setItemWidget(item, widget);
        index++;
    }
    listWidget->setStyleSheet(R"(
        QScrollBar:vertical {
            width: 6px;
            margin: 0px;
            border-radius: 4px;
        }
        QScrollBar::handle:vertical {
            background: white;
            border-radius: 3px;
        }
        QScrollBar::sub-line:vertical {
            height: 0px;
        }
        QScrollBar::add-line:vertical {
            height: 0px;
        }
        QScrollBar::up-arrow:vertical,
        QScrollBar::down-arrow:vertical {
            height: 0px;
        }
        QScrollBar::add-page:vertical,
        QScrollBar::sub-page:vertical {
            background: #333;
            border-radius: 3px;
        }
        QListWidget{
            border: none;
        }
    )");
}

void MusicListView::update() {
    switch (facade.getSourceType()) {
        case LOCAL_MUSIC:
            createLocalMusicListView();
            break;
        case INTERNET_RADIO:
            createInternetRadioListView();
            break;
    }
}

void MusicListView::registerHandlers() {
    connect(listWidget, &QListWidget::itemClicked, this, &MusicListView::handleItemClicked);
}

void MusicListView::handleItemClicked(QListWidgetItem *item) {
    switch (facade.getSourceType()) {
        case LOCAL_MUSIC: {
            int index = item->data(Qt::UserRole).toInt();

            facade.setTrack(index);
            facade.play();
        }
            break;
        case INTERNET_RADIO: {
            int index = item->data(Qt::UserRole).toInt();

            facade.setStation(index);
            facade.play();
        }
            break;
    }

}

void MusicListView::sourceTypeChanged() {
    update();
}
