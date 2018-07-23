// Ship.h - Ship class declaration


#pragma once

#include <string>
#include "Point.h"
#include "Board.h"
using namespace std;

#define SHIP_TYPES 5
#define MAX_LENGTH 5


//Enumeration declaration:

enum DIRECTION {HORIZONTAL,VERTICAL};


class Ship
{
public:
    // Constructor
    Ship();
    
    // Function to initially set all ship to the correct values
   static void LoadShips( Ship ship[SHIP_TYPES] );
    
    // Function which gives ships their location points and placement orientation
    void FillShipData( const DIRECTION& direction, Point coordinate );
    
    // Returns true if the ship has been hit by opponent's strike
   static bool isHit( const Point& guess, Ship ship[SHIP_TYPES] );
    
    // Returns true if the ship has been sunk
   bool isSunk() const;
    
    // Returns true if the player is allowed to place their ship on the requested coordinate
   static bool CheckPlacement( const Point& placePoint, const DIRECTION& direction, const Ship ship[],const int& shipNumber);
    
   // Prints the ratio of how many times the ship has been hit relative to its size
   void PrintDamage() const;
   
   
   // Getter function for the name of the ship
   string GetName() const
   { return Name; }
   
   // Getter function for the length of the ship
   int GetLength() const
   { return Length; }

   //Getter function for the number of times the ship has been hit
   int GetHits() const
   { return Hits; }

   // Getter function for the points ocupied by the ship
   const Point* GetSpaceOccupied() const
   { return spaceOccupied; }
   
   
 private:
    // Ship name
    string Name;
    // How many spaces the ship occupies
    int Length;
    
    // How many hits the ship has suffered
     int Hits;
    
    // Determines whether a ship lies vertically or horizontally on the board
    DIRECTION Direction;
    // Holds the coordinates that the ship occupies
    Point spaceOccupied[MAX_LENGTH];
    
};
