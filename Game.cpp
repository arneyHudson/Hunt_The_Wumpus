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
    cout << "\nAction: (N)orth, (S)outh, (E)ast, (W)est, shine (F)lashlight, (D)ebug/Look at Map, (H)elp, (Q)uit: ";
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
            // Shine flashlight
            cout << "You shine your flashlight out into the distance." << endl;
            break;
        case 'H':
        case 'h':
            // Display help
            help();
            break;
        case 'Q':
        case 'q':
            // Quit game
            cout << "\nThanks for playing!" << endl;
            gameOver = true;
            break;
        case 'D':
        case 'd':
            // Look at map

            break;
        default:
            cout << "\nInvalid action. Please try again." << endl;
            break;
    }
}

void Game::help() {
    cout << "\nYou are trying to make it through 5 nights here at the arcade." << endl;
    cout << "The only way you make it out alive is if you disable"
            " the two animatronics within the arcade." << endl;
    cout << "You can do this by applying your magnet to them when you get close." << endl;
    cout << "Additionally, you can use your flashlight to see where the animatronics are." << endl;
    cout << "Stay clear of rooms with tripping hazards as they will cause you to lose the items you're"
            "holding onto." << endl;
    cout << "The worst of them all are the collapsing rooms where the ceiling caves in and "
            "causes your demise, make sure to avoid these at all costs." << endl;
    cout << "Good luck out there, it shouldn't be to difficult to SURVIVE!" << endl;
}

void Game::updateGameState() {
}

void printMap() {

}

void gameBackground() {
    cout << "Basic Game Background: " << endl;
    cout << "   You are a security guard working the night shift at a local arcade" << endl;
    cout << "   This arcade isn't in the best of shape so watch out for rooms with collapsing ceilings" << endl;
    cout << "   This arcade also contains old animatronic robots that are EVIL, " << endl;
    cout << "   they will kill you if given the chance" << endl;
    cout << "   The only equipment you have is a flashlight which takes batteries" << endl;
    cout << "   For some reason this flashlight isn't very efficient so it dies after every " << endl;
    cout << "   use and you'll constantly be needing to find more batteries" << endl;
    cout << "   Finally, there may happen to be some old magnets lying around, " << endl;
    cout << "   Could these be used to disable the robots? Only one way to find out!" << endl;
}

int main() {
    gameBackground();
    Game game;  // Create an instance of the Game class
    game.play();  // Call the play method on the instance
    return 0;
}