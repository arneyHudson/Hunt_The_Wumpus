//
// Created by arneyh on 4/19/2023.
//

#include <iostream>
#include "Player.h"
#include "ArcadeMap.h"
#include "MapCell.h"


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
        if(batteries >= 1) {
            batteries--;
            cout << "The player fell over some debris in the room they tried exploring. They unfortunately lost a "
                    "battery during their stumble. The Player now has " << batteries << " batteries.";
        } else {
            cout << "The player fell over some debris in the current room they were exploring." << endl;
        }
    }

    // The move is valid if it reaches here
    return true;
}

int Player::getBatteries() const {
    return batteries;
}

int Player::getMagnets() const {
    return magnets;
}

void Player::setBattery(int battery) {
    this->batteries = battery;
}
void Player::setMagnet(int magnet) {
    this->magnets = magnet;
}

void Player::displayInventory() const {
    cout << "The Player currently has: " << batteries << " batteries, and " << magnets << " magnets." << endl;
}


