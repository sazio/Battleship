//
//  Fleet.h - Fleet class declaration

#include "Ship.h"
#include "Board.h"

#define CRUISER 0
#define FRIGATE 1
#define SUBMARINE 2
#define ESCORT 3
#define BATTLESHIP 4

class Fleet
{
    
public:
    // Constructor
    Fleet();
    
    // Init-constructor
    void FillFleet(const Ship ships[] );
    
    // Prints coordinates each ship in the fleet occupies
    void ShowUserFleet();
    
private:
    Ship Cruiser;
    Ship Frigate;
    Ship Submarine;
    Ship Escort;
    Ship Battleship;
};
