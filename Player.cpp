//
// Created by arneyh on 4/19/2023.
//

#include <iostream>
#include "Player.h"
#include "ArcadeMap.h"
#include "MapCell.h"
#include "Game.h"


using namespace std;

/**
 * Constructor to initialize robot's initial position and the arcadeMap it belongs to
 */
Player::Player(ArcadeMap *arcadeMap, int initialX, int initialY) : arcadeMap(arcadeMap) {
    currentCell = arcadeMap->getCell(initialX, initialY);
    if (currentCell->hasBatteries()) {
        batteries++;
        currentCell->removeItem();
    }
    if (currentCell->hasMagnets()) {
        magnets++;
        currentCell->removeItem();
    }
    if (currentCell->hasCollapsingRoom()) {
        isAlive = false;
    }
    xLocation = initialX;
    yLocation = initialY;
    currentCell->enter();
}

/**
 * Displays the Location and gold count of the robot. If the robot has negative gold it will print out another message
 */
void Player::displayStatus() const {
    cout << "Player at (" << xLocation << ", " << yLocation << ") with " << batteries << " batteries and " <<
          magnets << " magnets.";
}

/**
 * Moves the robot in the set of given directions, will stop at each new direction to test if it is valid
 * @param direction the direction the robot should move (north, south, east, or west)
 * @return if the spot to move to is possible
 */
bool Player::move(char direction) {
    direction = static_cast<char>(tolower(direction)); // convert direction to lowercase
    int newX = xLocation;
    int newY = yLocation;

    // calculate new coordinates based on direction
    if (direction == 'e') {
        newX++;
    } else if (direction == 'w') {
        newX--;
    } else if (direction == 's') {
        newY++;
    } else if (direction == 'n') {
        newY--;
    } else {
        return false; // invalid direction
    }

    // Check if the new location is a valid one
    MapCell *newCell = arcadeMap->getCell(newX, newY);
    if (newCell == nullptr || newCell->occupied()) {
        return false; // Cannot move to this location
    }
    // Move the robot to the new location
    currentCell->vacate();
    currentCell = newCell;
    currentCell->enter();
    xLocation = newX;
    yLocation = newY;
    // Check if there is any batteries at the new location
    if (currentCell->hasBatteries()) {
        batteries++;
        currentCell->removeItem();
    }
    // Check if there is a tripping room at the new location
    if(currentCell->hasTrippingRoom()) {
        cout << "The player fell over some debris in the current room they were exploring." << endl;
        if(batteries >= 1) {
            batteries--;
            cout << "They unfortunately lost a battery during their stumble. "
                    "The Player now has " << batteries << " batteries." << endl;
        }
        if(magnets >= 1) {
            magnets--;
            cout << "Man you're clumsy. Say goodbye to a magnet "
                    "The Player now has " << magnets << " magnets." << endl;
        }
    }
    if (currentCell->hasCollapsingRoom()) {
        isAlive = false;
        cout << "The ceiling collapsed in on the player...\nR.I.P." << endl;
    }
    if(currentCell->hasAnimatronic()) {
        isAlive = false;
        cout << "You got a bit too close to one of the robots...\nR.I.P." << endl;
    }

    // The move is valid if it reaches here
    return true;
}

void Player::displayInventory() const {
    cout << "The Player currently has: " << batteries << " batteries, and " << magnets << " magnets." << endl;
}

bool Player::getIsAlive() {
    return isAlive;
}

bool Player::nearAnimatronic(ArcadeMap* map) {
    int x = xLocation;
    int y = yLocation;

    // Check neighboring cells for robots
    if (map->getCell(x - 1, y) && map->getCell(x - 1, y)->hasAnimatronic()) {
        return true;  // Robot is in the cell above the player
    }
    if (map->getCell(x + 1, y) && map->getCell(x + 1, y)->hasAnimatronic()) {
        return true;  // Robot is in the cell below the player
    }
    if (map->getCell(x, y - 1) && map->getCell(x, y - 1)->hasAnimatronic()) {
        return true;  // Robot is in the cell to the left of the player
    }
    if (map->getCell(x, y + 1) && map->getCell(x, y + 1)->hasAnimatronic()) {
        return true;  // Robot is in the cell to the right of the player
    }

    return false; // No robots nearby
}

int Player::minusBattery() {
    if(batteries >= 1) {
        return batteries--;
    } else {
        return batteries;
    }
}

int Player::minusMagnet() {
    if(magnets >= 1) {
        return magnets--;
    } else {
        return magnets;
    }
}


