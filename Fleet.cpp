//
//  Fleet.cpp - Fleet class function implementation


#include "Fleet.h"

// Fleet constructor
Fleet::Fleet()
{
    
}

// Fleet initconstructor which fills its private data fields with appropriate ship data
void Fleet::FillFleet(const Ship ships[])
{
    Cruiser = ships[ CRUISER ];
    Frigate = ships[ FRIGATE ];
    Submarine = ships[ SUBMARINE ];
    Escort = ships[ ESCORT ];
    Battleship = ships[ BATTLESHIP ];
   }


// Prints the coordinates of each of the user's ships to the console
void Fleet::ShowUserFleet()
{
  
  
  // Print coordinate locations for Cruiser
  cout << Cruiser.GetName() << " location points: ";
  for( int i = 0; i < Cruiser.GetLength(); i++ )
    cout << Cruiser.GetSpaceOccupied()[i] << " ";
  cout << endl;
  
  // Print coordinate locations for Frigate
  cout << Frigate.GetName() << " location points: ";
  for( int i = 0; i < Frigate.GetLength(); i++ )
    cout << Frigate.GetSpaceOccupied()[i] << " ";
  cout << endl;
  
  // Print coordinate location for Submarine
  cout << Submarine.GetName() << " location points: ";
  for( int i = 0; i < Submarine.GetLength(); i++ )
    cout << Submarine.GetSpaceOccupied()[i] << " ";
  cout << endl;
  
  // Print coordinate locations for Escort
  cout << Escort.GetName() << " location points: ";
  for( int i = 0; i < Escort.GetLength(); i++ )
    cout << Escort.GetSpaceOccupied()[i] << " ";
  cout << endl;
  
  // Print coordinate locations for Battleship
  cout << Battleship.GetName() << " location points: ";
  for( int i = 0; i < Battleship.GetLength(); i++ )
    cout << Battleship.GetSpaceOccupied()[i] << " ";
  cout << endl;
}
