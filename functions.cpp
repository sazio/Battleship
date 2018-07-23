#include "functions.h"

#define TOTLENGTH 17

//***************************//

int Oi(int i){
  if(i==0) return 1;
  else return 0;
}


//***********PlacementPhase Function***************//

void PlacementPhase(Board& shipsBoard, Ship playerShips[]){

  // Variable to set ship's orientation
  int choice;
  // Orientation of the ship
  DIRECTION directionChoice;
  // Point where the front of the ship lies
  Point shipPlacement;
  // True if the placement datas passed by the player are not valid 
  bool invalidPlacement;
  // Variable to confirm the ships placement
  int conf;

  // While the player has not confirmed the ships placement...
  do{
    // Reset the board where ships lie
    shipsBoard.ResetBoard();

    cout << "Time to place your ships. \nFor each ship, you will choose one point which is where the front of the ships will lie. \n";
    cout << "You will then choose a direction for your ship to lie (vertical or horizontal)\n\n";
    cout << "Here is a sample board. Row #'s on left and column #'s on top..\n\n";
    // For each ship...
    for( int i = 0; i < SHIP_TYPES; i++ )
      {
	//Print the board with the placed ships
	shipsBoard.PrintBoard();

	// While the placement datas are not valid...
	do{
	  // Ask user for the point where the front of the ship lies
	  cout << "Enter row and column number for front coordinate of " << playerShips[i].GetName() << " (size: " << playerShips[i].GetLength() << ") (ex: x y) : ";
	  cin >> shipPlacement.X >> shipPlacement.Y;
	  
	  // Ask user for direction in which the ship lies
	  cout << "Lay it vertically or hortizontally? ( 1 for vert, 2 for horiz ) : ";
	  // While "choice" value is valid...
	  do{
	    cin >> choice;
	    if(choice != 1 && choice != 2)
	      cout << "You did not enter 1 or 2. Please enter 1 for vert, 2 for horiz: ";
	  }while( choice != 1 && choice != 2 );

	  // Set ship's orientation
	  if( choice == 1 )
	    directionChoice = VERTICAL;
	  else
	    directionChoice = HORIZONTAL;
	  
	  // Check if the given point and direction are valid
	  invalidPlacement = Ship::CheckPlacement(shipPlacement, directionChoice, playerShips, i);
	  
	  if( invalidPlacement)
	    cout << "\nINVALID PLACEMENT!\nYou either already have a ship at this location or your ship will not be entirely placed on the board at this location.\n";
	
	}while( invalidPlacement );

	// Mark board's points occupied by the ship
	Point tmpPlacement = shipPlacement;
      
	for( int j=1 ; j <= playerShips[i].GetLength() ; j++)
	  {
	    shipsBoard.MarkBoard(0,tmpPlacement);
	    if(choice==1)
	      tmpPlacement.X++;
	    else
	      tmpPlacement.Y++;
	  }
      
	//Give the current ship its user assigned data (spaces occupied, direction)
	playerShips[i].FillShipData(directionChoice, shipPlacement);
	cout << endl;
            
      }
    
    shipsBoard.PrintBoard();

    // Ask user if he wants to repeat the placement
    cout<<"Confirm your choice(1) or replace your ships(2)?"<<endl;

    // As "conf" is not valid...
    do{
      cin >> conf;
      if(conf != 1 && conf != 2)
	cout << "You did not enter 1 or 2. Confirm your choice(1) or replace your ships(2)? ";
    }while( conf != 1 && conf != 2 );
    
  }while(conf != 1);

  // Print some empty lines to hide the board to the next player
  for(int cln = 0;cln < 20;cln++)
    cout << endl;
  
  return;
}


//*************Turn Function*************//

void Turn(bool& userSuccess, int guesses, Board& playerBoard, Ship player2Ships[], bool& end)
{
  // Point fired by the player
  Point fireSpot;
    
  int damage=0;
      
  // Show user their guesses remaining and their board
  cout << "\nYou have " << guesses << " guesses remaining.\n";
  cout << "Here is your board showing your previous guesses..\n\n";
  playerBoard.PrintBoard();
      
  // Ask user for next guess location
  cout << "Enter row and column of your guess separated by a space: ";
  //while "fireSpot" is not valid...
  do{
    cin >> fireSpot.X >> fireSpot.Y;
	
    if(playerBoard.CheckGuess(fireSpot)){
      cout << "\nINVALID GUESS!\n";
      cout << "This point is either not contained on the board or you have previously guessed it!\n";
      cout << "Please enter a new point to guess..\n";
      cout << "Enter row then column separated by a space: ";
    }
  }while( playerBoard.CheckGuess(fireSpot) );
      
  // Determine if the user's guess landed a hit
  // If so, their turn continues so userSuccess is set to true
  userSuccess = Ship::isHit(fireSpot, player2Ships );
  
  // Mark the user's board with the correct character depending on if a hit was landed
  playerBoard.MarkBoard(userSuccess, fireSpot);
      
  // Show user which of the players' ships they have sunk
  cout << "Ships you have sunk:\n";
  for( int i = 0; i < SHIP_TYPES; i++ )
    {
      // If one of the player2's ships has been sunk..
      if( player2Ships[i].isSunk() )
	{
	  // Print the name of the ship and its size to the console
	  cout << "   - " << player2Ships[i].GetName() << " (of length ";
	  cout << player2Ships[i].GetLength() << ") has been sunk.\n";
        damage=damage+player2Ships[i].GetLength();
         if(damage== TOTLENGTH)
             end=true;
	}
    }
      
}
