//
// Created by arneyh on 4/19/2023.
//

#include "ArcadeMap.h"
#include "MapCell.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

ArcadeMap::ArcadeMap() = default;

/**
 * Reads in the input file and tracks every item in the cell arcadeMap to a character
 */
void ArcadeMap::load() {
    int rowIndex = 0;
    string line;

    // Parse the input string
    while (rowIndex < HEIGHT) {
        for(int i = 1; i <= WIDTH; i++) {
            char cellChar = getRandomToken();
            auto* cell = new MapCell(i, rowIndex, cellChar);
            cells[i - 1][rowIndex] = cell;
        }
        rowIndex++;
    }
}

char ArcadeMap::getRandomToken() {
    const char tokens[] = {'+', 'M', '#', 'T'};
    const int numTokens = sizeof(tokens) / sizeof(tokens[0]);

    // Generate a random number between 0 and 1
    double randNum = static_cast<double>(rand()) / RAND_MAX;

    // Return an empty space token if the random number is less than 0.5
    if (randNum < 0.5) {
        return '.';
    }
    else {
        // Get a random index within the range of the tokens array
        int randomIndex = rand() % numTokens;
        return tokens[randomIndex];
    }
}

/**
 * Writes the cell arcadeMap display
 */
void ArcadeMap::write() {

    // print the top border of the box
    writeBorders();

    for(int i = 0; i < HEIGHT; i++) {
        cout << "|";
        for(auto & cell : cells) {
            if(cell[i]) {
                cout << cell[i]->display();
            } else {
                cout << ' ';
            }
        }
        cout << "|" << endl;
    }

    // print the bottom border of the box
    writeBorders();
}

/**
 * Writes the borders of the cell with plus and dashes
 */
void ArcadeMap::writeBorders() {
    // print the bottom border of the box
    cout << "+";
    for (int i = 0; i < WIDTH; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}

/**
 * Gets the cell at a given location
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @return if the cell is within the bounds, it returns the cell
 */
MapCell* ArcadeMap::getCell(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return nullptr;
    }
    return cells[x][y];
}
