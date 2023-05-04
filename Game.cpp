//
// Created by arneyh on 4/19/2023.
//

#include "Game.h"
#include "Player.h"
#include "ArcadeMap.h"
#include "Animatronics.h"
#include "MapCell.h"
#include "Tunnel.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void Game::play() {
    // Game loop
    while (!gameOver) {
        displayCurrentState();
        getUserAction();
        if(!player->getIsAlive()) {
            gameOver = true;
        } else if(animatronicsDisabled == 2) {
            cout << "Congrats, you have disabled all the animatronics and survived!" << endl;
            gameOver = true;
        } else {
            player->displayInventory();
        }
    }
}

void Game::displayCurrentState() {
    // Display current state of the game
    cout << "\nAction: (N)orth, (S)outh, (E)ast, (W)est, shine (F)lashlight, use (M)agnet, (C)heck status "
            "(D)ebug/Look at Map, (H)elp, (B)ackground, (Q)uit: ";
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
            cout << "\nYou move to the north." << endl;
            player->move('n');
            break;
        case 'S':
        case 's':
            // Move south
            cout << "\nYou move to the south." << endl;
            player->move('s');
            break;
        case 'E':
        case 'e':
            // Move east
            cout << "\nYou move to the east." << endl;
            player->move('e');
            break;
        case 'W':
        case 'w':
            // Move west
            cout << "\nYou move to the west." << endl;
            player->move('w');
            break;
        case 'C':
        case 'c':
            player->displayStatus();
            break;
        case 'F':
        case 'f':
            // Shine flashlight
            player->minusBattery();
            cout << "\nYou shine your flashlight out into the distance." << endl;
            if(player->nearAnimatronic(map)) {
                cout << "\nYou are near an animatronic, stay wary and try and use a magnet!" << endl;
            } else {
                cout << "\nThere are no animatronics nearby, stay safe" << endl;
            }
            break;
        case 'M':
        case 'm':
            player->minusMagnet();
            cout << "\nYou attempt to disable a robot with your magnet." << endl;
            if(player->nearAnimatronic(map) != 0) {
                cout << "\nYou disabled one of the robots. Great work!" << endl;
                animatronicsDisabled += 1;
                if(player->nearAnimatronic(map) == 1) {
                    map->getCell(player->xLocation - 1, player->yLocation)->setFreddy(false);
                } else if(player->nearAnimatronic(map) == 2) {
                    map->getCell(player->xLocation + 1, player->yLocation)->setFreddy(false);
                } else if(player->nearAnimatronic(map) == 3) {
                    map->getCell(player->xLocation, player->yLocation - 1)->setFreddy(false);
                } else if(player->nearAnimatronic(map) == 4) {
                    map->getCell(player->xLocation, player->yLocation + 1)->setFreddy(false);
                } else if(player->nearAnimatronic(map) == 5) {
                    map->getCell(player->xLocation - 1, player->yLocation)->setBonnie(false);
                } else if(player->nearAnimatronic(map) == 6) {
                    map->getCell(player->xLocation + 1, player->yLocation)->setBonnie(false);
                } else if(player->nearAnimatronic(map) == 7) {
                    map->getCell(player->xLocation, player->yLocation - 1)->setBonnie(false);
                } else if(player->nearAnimatronic(map) == 8) {
                    map->getCell(player->xLocation, player->yLocation + 1)->setBonnie(false);
                }
            } else {
                cout << "\nYou missed your shot..." << endl;
            }
            break;
        case 'H':
        case 'h':
            // Display help
            help();
            break;
        case 'B':
        case 'b':
            // Display background info about game
            gameBackground();
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
            cout << "\nThis is sort of cheating but here you go I guess..." << endl;
            map->write();
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

Game::Game() {
    map = new ArcadeMap();
    animatronicsDisabled = 0;

    // Create an array of all possible coordinates on the map
    vector<pair<int, int>> coordinates;
    for (int x = 0; x < ArcadeMap::HEIGHT; ++x) {
        for (int y = 0; y < ArcadeMap::WIDTH; ++y) {
            coordinates.emplace_back(x, y);
        }
    }

    // Shuffle the coordinates randomly
    random_device rd;
    mt19937 gen(rd());
    shuffle(coordinates.begin(), coordinates.end(), gen);

    // Extract the first three coordinates for player, freddy, and bonnie objects
    pair<int, int> playerCoords = coordinates[0];
    pair<int, int> freddyCoords = coordinates[1];
    pair<int, int> bonnieCoords = coordinates[2];
    pair<int, int> tunnel1coords = coordinates[3];
    pair<int, int> tunnel2coords = coordinates[4];

    map->load();

    // Set the hasFreddy flag for Freddy's initial location
    map->getCell(freddyCoords.first, freddyCoords.second)->setFreddy(true);

    // Set the hasBonnie flag for Bonnie's initial location
    map->getCell(bonnieCoords.first, bonnieCoords.second)->setBonnie(true);

    map->getCell(tunnel1coords.first, tunnel1coords.second)->setTunnel(true);
    map->getCell(tunnel2coords.first, tunnel2coords.second)->setTunnel(true);


    tunnel1 = new Tunnel(map, tunnel1coords.first, tunnel1coords.second);
    tunnel2 = new Tunnel(map, tunnel1coords.first, tunnel1coords.second, tunnel1);
    tunnel1->setExit(tunnel2);
    map->getCell(tunnel1coords.first, tunnel1coords.second)->setTunnel(tunnel1);
    map->getCell(tunnel2coords.first, tunnel2coords.second)->setTunnel(tunnel2);

    player = new Player(map, playerCoords.first, playerCoords.second);
    freddy = new Animatronics(map, freddyCoords.first, freddyCoords.second);
    bonnie = new Animatronics(map, bonnieCoords.first, bonnieCoords.second);
}


void Game::gameBackground() {
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

ArcadeMap* Game::getMap() {
    return map;
}

int main() {
    Game game;  // Create an instance of the Game class
    game.play();  // Call the play method on the instance
    cout << "GAME OVER!!!" << endl;
    return 0;
}