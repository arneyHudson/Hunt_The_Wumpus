//
// Created by arneyh on 4/30/2023.
//

#include "MapCell.h"

MapCell::MapCell(int x, int y, char type) : xLocation(x), yLocation(y), token(type),
hasPlayer(false), hasFreddy(false), hasBonnie(false), type(type) {
}

/**
 * If the character is a pound sign, there is a pit
 * @return if there is a pit
 */
bool MapCell::hasCollapsingRoom() {
    return token == '#';
}

bool MapCell::hasAnimatronic() {
    return hasFreddy || hasBonnie || token == 'F' || token == 'B';
}

/**
 * If the character is a T, there is a pit
 * @return if there is a thief
 */
bool MapCell::hasTrippingRoom() {
    return token == ',';
}

/**
 * If the character is an asterisk, there is gold at that location
 * @return if there is gold at that location
 */
bool MapCell::hasBatteries() {
    return token == '+';
}

/**
 * If gold has already been collected by the robot remove it by making it an empty space.
 */
void MapCell::removeItem() {
    token = ' ';
}

/**
 * If the robots new location has a
 */
bool MapCell::occupied() {
    return hasPlayer;
}

/**
 * Prints the char unless the location is where the robot is (prints an 'P' in that case)
 * @return
 */
char MapCell::display() {
    if (hasPlayer) {
        return 'P';
    } else if(hasFreddy) {
        return 'F';
    } else if(hasBonnie) {
        return 'B';
    } else {
        return token;
    }
}

/**
 * If the robot may enter a location
 */
void MapCell::enter() {
    hasPlayer = true;
}

/**
 * If the robot cannot enter a location
 */
void MapCell::vacate() {
    hasPlayer = false;
}

bool MapCell::hasMagnets() {
    return token == '*';
}
