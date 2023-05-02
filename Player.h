//
// Created by arneyh on 4/19/2023.
//

#ifndef HUNT_THE_WUMPUS_PLAYER_H
#define HUNT_THE_WUMPUS_PLAYER_H
class MapCell;
class ArcadeMap;
class Game;

// A robot which lives on a arcadeMap at a particular x and y coordinate.
class Player {
public:
    Player(ArcadeMap *arcadeMap, int initialX, int initialY);
    // display robot status in the form of "Player at (6, 7) with 3 batteries and 1 magnet" to cout
    void displayStatus() const;
    // move robot in specified direction (e/w/s/n), returning true
    //   if was able to move in that direction
    // Warning: this method can get long - be sure to write private messages
    //   to break it up
    bool move(char direction);
    bool getIsAlive();
    void displayInventory() const;        // method to display player's inventory
    bool nearAnimatronic(ArcadeMap* map);
    int minusBattery();
    int minusMagnet();

private:
    ArcadeMap *arcadeMap;
    MapCell *currentCell;
    int xLocation, yLocation;
    int batteries = 2;    // number of batteries for flashlight
    int magnets = 2;       // number of masks for hiding from monsters
    bool isAlive = true;

};

#endif //HUNT_THE_WUMPUS_PLAYER_H
