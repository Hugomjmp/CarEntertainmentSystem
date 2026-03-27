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
        UI/ConsoleUI.cpp
        UI/ConsoleUI.h
        models/MakeFolder.cpp
        models/MakeFolder.h
        Settings/Settings.h
        Settings/Folders.h
        models/data/Library.cpp
        models/data/Library.h
        models/MusicPlayer.cpp
        models/MusicPlayer.h
        Settings/Settings.cpp
        models/data/DHT11.cpp
        models/data/DHT11.h)

#[[find_package(TagLib 2.0.0 REQUIRED)]]

target_link_libraries(CarEntertainmentSystem
        SFML::Audio
#[[        TagLib::tag
        pigpio]]
        pthread
)