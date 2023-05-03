//
// Created by ruppea on 5/3/2023.
//

#ifndef HUNT_THE_WUMPUS_TUNNEL_H
#define HUNT_THE_WUMPUS_TUNNEL_H

class MapCell;
class ArcadeMap;

class Tunnel {
public:
    Tunnel(ArcadeMap *arcade, int xLoc, int yLoc);
    Tunnel(ArcadeMap *arcade, int xLoc, int yLoc, Tunnel* exit);
    Tunnel* getExit() {return exit; };
    int getX() { return xLoc; };
    int getY() { return yLoc; };
    void setExit(Tunnel* tunnel) { exit = tunnel; };
private:
    ArcadeMap *arcade;
    int xLoc;
    int yLoc;
    MapCell* tunnelCell;
    Tunnel *exit;
};
#endif
