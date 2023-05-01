cmake_minimum_required(VERSION 3.24)
project(hunt_the_wumpus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hunt_the_wumpus
        ArcadeMap.cpp
        ArcadeMap.h
        Game.cpp
        Game.h
        Player.cpp
        Player.h
        Room.cpp
        Room.h
        Animatronics.cpp
        Animatronics.h MapCell.cpp MapCell.h)
