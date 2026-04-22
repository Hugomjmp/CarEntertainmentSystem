#[[cmake_minimum_required(VERSION 4.0)]]
cmake_minimum_required(VERSION 3.16) #[[para o raspberry pi]]
project(CarEntertainmentSystem)

set(CMAKE_CXX_STANDARD 20)



#[[include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)]]

add_executable(CarEntertainmentSystem main.cpp
        models/data/local_music/Song.cpp
        models/data/local_music/Song.h
        models/data/playlist/Playlist.cpp
        models/data/playlist/Playlist.h
        ui/ConsoleUI.cpp
        ui/ConsoleUI.h
        models/MakeFolder.cpp
        models/MakeFolder.h
        Settings/Settings.h
        Settings/Folders.h
        models/data/local_music/Library.cpp
        models/data/local_music/Library.h
        models/MusicPlayer.cpp
        models/MusicPlayer.h
        models/data/sensor/DHT11.cpp
        models/data/sensor/DHT11.h
        MainWindow.cpp
        MainWindow.h
        ui/Views/TopView.cpp
        ui/Views/TopView.h
        ui/Views/BottomView.cpp
        ui/Views/BottomView.h
        ui/Views/CenterView.cpp
        ui/Views/CenterView.h
        ui/Views/LeftView.cpp
        ui/Views/LeftView.h
        ui/Views/RightView.cpp
        ui/Views/RightView.h
        models/Facade.cpp
        models/Facade.h
        models/data/local_music/MetaData.cpp
        models/data/local_music/MetaData.h
        models/data/local_music/Media.cpp
        models/data/local_music/Media.h
        models/data/sensor/GPS.cpp
        models/data/sensor/GPS.h
        models/data/interfaces/ISensor.cpp
        models/data/interfaces/ISensor.h
        models/data/sensor/GPIO.cpp
        models/data/sensor/GPIO.h
        models/data/connections/BluetoothMedia.cpp
        models/data/connections/BluetoothMedia.h
        models/data/radio/OnlineRadioLibrary.cpp
        models/data/radio/OnlineRadioLibrary.h
        models/data/radio/Station.cpp
        models/data/radio/Station.h
        ui/Views/SourceView.cpp
        ui/Views/SourceView.h
        models/data/radio/InternetRadio.cpp
        models/data/radio/InternetRadio.h
        models/data/enums/SourceType.h
        ui/Views/sidePanel/MusicListView.cpp
        ui/Views/sidePanel/MusicListView.h
        ui/Views/sidePanel/MediaPlayerView.cpp
        ui/Views/sidePanel/MediaPlayerView.h
        models/data/SessionState.cpp
        models/data/SessionState.h
        models/data/connections/WIFI.cpp
        models/data/connections/WIFI.h
        models/data/connections/K_Line.cpp
        models/data/connections/K_Line.h
        models/data/sensor/FMRadio.cpp
        models/data/sensor/FMRadio.h
)

#[[find_package(TagLib 2.0.0 REQUIRED)]]
find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia #[[Bluetooth]] Network)

set_target_properties(CarEntertainmentSystem PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
)

target_link_libraries(CarEntertainmentSystem
        #[[SFML::Audio]]
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::Network
        Qt6::Core
        #[[pigpio]]
        pthread
)

if (WIN32)
    add_custom_command(TARGET CarEntertainmentSystem POST_BUILD
            COMMAND "C:/Qt/6.11.0/mingw_64/bin/windeployqt.exe"
            $<TARGET_FILE:CarEntertainmentSystem>
    )
endif ()
