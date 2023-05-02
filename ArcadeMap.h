//
// Created by arneyh on 4/19/2023.
//

#ifndef HUNT_THE_WUMPUS_ARCADEMAP_H
#define HUNT_THE_WUMPUS_ARCADEMAP_H
class MapCell;

class ArcadeMap {
public:
    static const int WIDTH = 5;
    static const int HEIGHT = 5;
    // initialize empty arcadeMap
    ArcadeMap();
    MapCell* getCell(int x, int y);
    void load();
    void write();
    static void writeBorders();


private:
    MapCell* cells[WIDTH][HEIGHT]{};

    static char getRandomToken();
};

#endif //HUNT_THE_WUMPUS_ARCADEMAP_H
