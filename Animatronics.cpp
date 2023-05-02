//
// Created by arneyh on 4/19/2023.
//

#include "Animatronics.h"
#include "MapCell.h"
#include "ArcadeMap.h"

Animatronics::Animatronics(ArcadeMap *arcadeMap, int initialX, int initialY) : arcadeMap(arcadeMap) {
    robotCell = arcadeMap->getCell(initialX, initialY);
    xLocation = initialX;
    yLocation = initialY;
}
