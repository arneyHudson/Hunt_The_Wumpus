//
// Created by ruppea on 5/3/2023.
//
class MapCell;
class ArcadeMap;

#include "Tunnel.h"
#include "MapCell.h"
#include "ArcadeMap.h"

Tunnel::Tunnel(ArcadeMap *arcadeMap, int x, int y){
    arcade = arcadeMap;
    tunnelCell = arcade->getCell(x, y);
    xLoc = x;
    yLoc = y;
    exit = nullptr;
}

Tunnel::Tunnel(ArcadeMap *arcadeMap, int x, int y, Tunnel* exitTunnel){
    arcade = arcadeMap;
    tunnelCell = arcade->getCell(x, y);
    xLoc = x;
    yLoc = y;
    exit = exitTunnel;
}