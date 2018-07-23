// Ship.cpp - Ship class function implementation


#include "Ship.h"

//******************* Ship Constructor **********************//

Ship::Ship()
{
  
}


//******************* LoadShips Function **********************//

void Ship::LoadShips(Ship ship[SHIP_TYPES])
{  
  //Sets the default data for the ships we plan to include in the game
  //IMPORTANT!! > MUST MATCH SHIP_TYPES -Default=5 (0-4)
  ship[0].Name = "Cruiser"; ship[0].Length = 2;
  ship[1].Name = "Frigate"; ship[1].Length = 3;
  ship[2].Name = "Submarine"; ship[2].Length = 3;
  ship[3].Name = "Escort"; ship[3].Length = 4;
  ship[4].Name = "Battleship"; ship[4].Length = 5;
}



//******************* FillShipData Function **********************//

void Ship::FillShipData( const DIRECTION& direction, Point coordinate )
{
  // Fill the ship's private data field 'Direction' with the direction parameter
  Direction = direction;
  
  // If the ship will be laid horizontally, give it the initial point plus the y-coordinates to its right
  if( Direction == HORIZONTAL )
    {
      // For each point occupied...
      for( int i = 0; i < Length; i++ )
        {
	  spaceOccupied[i].X = coordinate.X;
	  spaceOccupied[i].Y = coordinate.Y + i;
	}
    }
  
  // If the ship will be laid vertically, give it the initial point plus the spaces below it
  else
    {
      // For each point occupied...
      for( int i = 0; i < Length; i++ )
        {
	  spaceOccupied[i].X = coordinate.X + i;
	  spaceOccupied[i].Y = coordinate.Y;
        }
    }
  
  // Set the ship's 'Hits' private data field to zero
  Hits = 0;
}



//******************* isHit Function **********************//

// Determines if the opposing player has landed a hit on a ship
bool Ship::isHit( const Point& guess, Ship ship[SHIP_TYPES] )
{
  // For loop to go through each ship
  for( int i = 0; i < SHIP_TYPES; i++ )
    {
      // For loop to go through each point the ship occupies
      for( int j = 0; j < ship[i].Length; j++ )
        {
	  // If the player's guess matches a point the ship is located on, it has been hit
	  if( ship[i].spaceOccupied[j] == guess )
            {
	      // Inform player they landed a hit and which one suffered the damage
	      cout << "The enemy's ship has been hit!\n"<<endl;
	      // Increment the number of times this ship has been hit
	      ship[i].Hits++;

	      return true;
            }
        }
    }
  
  // If the player has missed all ships, inform them
  cout << "Missed.\n";
  
  return false;
}



//******************* isSunk Function **********************//
//bool Ship::isSunk() const
bool Ship::isSunk() const
{
  
  // If the number of hits is equal to the length of the ship, return true
  if(Hits == Length) return true;
  else return false;
  }



//******************* CheckPlacement Function **********************//

bool Ship::CheckPlacement(const Point& placePoint, const DIRECTION& direction, const Ship ship[], const int& shipNumber)
{
  
  if( direction == HORIZONTAL )
    {
      // Check if the desired placement is contained on the board
      if( placePoint.Y+ship[shipNumber].GetLength() > BOARD_WIDTH+1 || placePoint.X < 1 || placePoint.Y < 1 || placePoint.X > BOARD_LENGTH )
	return true;
    }
  
  else
    {
      // Check if the desired placement is contained on the board
      if( placePoint.X+ship[shipNumber].GetLength() > BOARD_LENGTH+1 || placePoint.X < 1 || placePoint.Y < 1 || placePoint.Y > BOARD_WIDTH)
	return true;
    }

  Point checkPoint;
  // For-loop to examine each ship
  for( int i = 0; i < shipNumber; i++)
    {
      // For-loop to examine the spaces each ship occupies
      for( int j = 0; j < ship[i].Length; j++ )
        {
	  //for-loop to examine the spaces the current ship occupies
	  for( int k = 0; k < ship[shipNumber].Length; k++ )
            {
	      checkPoint = placePoint;
	      if( direction == HORIZONTAL )
                {		  
		  checkPoint.Y = placePoint.Y + k;
		  // If an already placed ship occupies the given space, return true
		  if( ship[i].spaceOccupied[j] == checkPoint) return true;
		}
	      
	      else
                {
		  checkPoint.X = placePoint.X + k;
		  // If an already placed ship occupies the given space, return true
		  if( ship[i].spaceOccupied[j] == checkPoint) return true;
                }
            }
        }
    }
  return false;
}


//******************* PrintDamage Function **********************//

// Prints the ships status displaying how many times it has been hit
void Ship::PrintDamage() const
{
  cout << endl;
  cout << Name<< " DAMAGE: " << Hits << "/" << Length;
  cout << endl;
}
