#pragma once

#include <iostream>
#include <stdlib.h>
#include "Point.h"
#include "Board.h"
#include "Ship.h"

using namespace std;

// Returns 1 if 0 is passed and 0 if 1 is passed (usefull to pass different players' objects to functions)
int Oi(int i);

// Function that manages the placement of a player's ships
void PlacementPhase(Board& shipsBoard, Ship playerShips[]);

// Function that manages the player's turn
void Turn(bool& userSuccess, int guesses, Board& playerBoard, Ship player2Ships[], bool& end);
