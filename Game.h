//
// Created by arneyh on 4/19/2023.
//

#ifndef HUNT_THE_WUMPUS_GAME_H
#define HUNT_THE_WUMPUS_GAME_H

class Game {
public:
    void play();

private:
    bool gameOver = false;

    static void displayCurrentState();
    void getUserAction();
    void handleUserAction(char action);
    void updateGameState();

    static void help() ;
};

#endif //HUNT_THE_WUMPUS_GAME_H
