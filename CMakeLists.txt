#[[cmake_minimum_required(VERSION 4.0)]]
cmake_minimum_required(VERSION 3.16) #[[para o raspberry pi]]
project(CarEntertainmentSystem)

set(CMAKE_CXX_STANDARD 20)



include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(CarEntertainmentSystem main.cpp
        models/data/Song.cpp
        models/data/Song.h
        models/data/Playlist.cpp
        models/data/Playlist.h
        ui/ConsoleUI.cpp
        ui/ConsoleUI.h
        models/MakeFolder.cpp
        models/MakeFolder.h
        Settings/Settings.h
        Settings/Folders.h
        models/data/Library.cpp
        models/data/Library.h
        models/MusicPlayer.cpp
        models/MusicPlayer.h
        models/data/DHT11.cpp
        models/data/DHT11.h
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
        models/data/MetaData.cpp
        models/data/MetaData.h
        models/data/Media.cpp
        models/data/Media.h
)

#[[find_package(TagLib 2.0.0 REQUIRED)]]
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set_target_properties(CarEntertainmentSystem PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
)
target_link_libraries(CarEntertainmentSystem
        SFML::Audio
        Qt6::Widgets
#[[        TagLib::tag]]
        pigpio
        pthread
)
if (WIN32)
    add_custom_command(TARGET CarEntertainmentSystem POST_BUILD
            COMMAND "C:/Qt/6.11.0/mingw_64/bin/windeployqt.exe"
            $<TARGET_FILE:CarEntertainmentSystem>
    )
endif ()
