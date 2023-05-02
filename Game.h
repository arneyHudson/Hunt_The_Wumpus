//
// Created by arneyh on 4/19/2023.
//

#ifndef HUNT_THE_WUMPUS_GAME_H
#define HUNT_THE_WUMPUS_GAME_H

class Player;
class Animatronics;
class ArcadeMap;

class Game {
public:
    Game();
    void play();

private:
    bool gameOver = false;
    ArcadeMap *map;
    Player *player;
    Animatronics *freddy;
    Animatronics *bonnie;

    static void displayCurrentState();
    void getUserAction();
    void handleUserAction(char action);
    //void updateGameState();

    static void gameBackground();
    static void help();
};

#endif //HUNT_THE_WUMPUS_GAME_H
