//
// Created by arneyh on 4/19/2023.
//

#include "Game.h"
#include "Player.h"

#include <iostream>

using namespace std;

void Game::play() {
    // Game loop
    while (!gameOver) {
        displayCurrentState();
        getUserAction();
        updateGameState();
    }
}

void Game::displayCurrentState() {
    // Display current state of the game
    cout << "Action: (N)orth, (S)outh, (E)ast, (W)est, shine (F)lashlight, (H)elp, (Q)uit: ";
}

void Game::getUserAction() {
    // Get user's action
    char action;
    cin >> action;
    handleUserAction(action);
}

void Game::handleUserAction(char action) {
    // Handle user's action
    switch (action) {
        case 'N':
        case 'n':
            // Move north
            cout << "You move to the north." << endl;
            break;
        case 'S':
        case 's':
            // Move south
            cout << "You move to the south." << endl;
            break;
        case 'E':
        case 'e':
            // Move east
            cout << "You move to the east." << endl;
            break;
        case 'W':
        case 'w':
            // Move west
            cout << "You move to the west." << endl;
            break;
        case 'F':
        case 'f':
            // Shoot arrow
            cout << "You shine your flashlight out into the distance." << endl;
            break;
        case 'H':
        case 'h':
            // Display help
            // ...
            break;
        case 'Q':
        case 'q':
            // Quit game
            gameOver = true;
            break;
        default:
            cout << "Invalid action. Please try again." << endl;
            break;
    }
}

void Game::updateGameState() {
}

void gameBackground() {
    cout << "You are a security guard working the night shift at a local arcade" << endl;
    cout << "This arcade isn't in the best of shape so watch out for rooms with collapsing ceilings" << endl;
    cout << "This arcade also contains old animatronic robots that are EVIL, " << endl;
    cout << "they will kill you if given the chance" << endl;
    cout << "The only equipment you have is a flashlight which takes batteries" << endl;
    cout << "For some reason this flashlight isn't very efficient so it dies after every " << endl;
    cout << "use and you'll constantly be needing to find more batteries" << endl;
    cout << "Finally, there may happen to be some old magnets lying around, " << endl;
    cout << "Could these be used to disable the robots? Only one way to find out!" << endl;
}

int main() {
    gameBackground();
    Game game;  // Create an instance of the Game class
    game.play();  // Call the play method on the instance
    return 0;
}