cmake_minimum_required(VERSION 3.16)

project(PokemonGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(PokemonGame
    PokemonGame1.cpp
    QT_PokemonGame/mainwindow.cpp
    QT_PokemonGame/mainwindow.h
    QT_PokemonGame/mainwindow.ui
    Pokemon.cpp
    Pokedex.cpp
    Encounter.cpp
    Region.cpp
)

target_include_directories(PokemonGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/QT_PokemonGame
)

target_link_libraries(PokemonGame PRIVATE Qt6::Widgets)
