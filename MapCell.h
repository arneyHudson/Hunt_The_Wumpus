//
// Created by arneyh on 4/30/2023.
//

#ifndef HUNT_THE_WUMPUS_MAPCELL_H
#define HUNT_THE_WUMPUS_MAPCELL_H

#include "Tunnel.h"

class MapCell {
    int xLocation, yLocation;
    char token;
    bool hasPlayer;
    bool hasFreddy;
    bool hasBonnie;
    char type;

public:
    Tunnel* tunnel = nullptr;
    MapCell(int x, int y, char type);
    // true if pit at this location
    bool hasTrippingRoom();
    // true if thief at this location
    bool hasCollapsingRoom();
    // true if gold at this location
    bool hasBatteries();
    bool hasMagnets();
    void removeItem();
    // is this location occupied by something that the robot
    //   cannot move over?
    bool occupied();
    // return the character to display for this location
    char display();
    // robot enters location
    void enter();
    // robot leaves location
    void vacate();

    int hasAnimatronic();

    void setFreddy(bool value) {
        this->hasFreddy = value;
    }

    void setBonnie(bool value) {
        this->hasBonnie = value;
    }

    void setTunnel(bool value) {
        this->hasTunnel = value;
    }

    void setTunnel(Tunnel* tun){
        this->tunnel = tun;
    }


    bool hasTunnel;
};


#endif //HUNT_THE_WUMPUS_MAPCELL_H
