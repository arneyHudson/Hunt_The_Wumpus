//
// Created by arneyh on 4/19/2023.
//

#ifndef HUNT_THE_WUMPUS_ANIMATRONICS_H
#define HUNT_THE_WUMPUS_ANIMATRONICS_H

class MapCell;
class ArcadeMap;

// A robot which lives on a arcadeMap at a particular x and y coordinate.
class Animatronics {

    Animatronics(ArcadeMap *arcadeMap, int initialX, int initialY);

private:
    ArcadeMap *arcadeMap;
    MapCell *robotCell;
    int xLocation, yLocation;
};

#endif //HUNT_THE_WUMPUS_ANIMATRONICS_H
