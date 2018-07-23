
#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "Fleet.h"
#include "functions.h"
#include <stdlib.h> 

//For using cin.get() at the end , in order to avoid automatic window
//exiting and to avoid the use of system("pause") which is not portable
#define USE_PAUSES
#ifndef _DEBUG
#undef USE_PAUSES
#endif

#define EVEN 2

using namespace std;


int main()
{  
  // true if the user wants to continue playing
  bool continuePlaying;
  // Maximum number of guesses
  int Max;
  // true if the placement of the ship is not valid 
  bool invalidPlacement = false;
  // char that holds 'y' or 'n' that the user answers with when asked if they'd like to play again
  char userDecision;
  // Number of guesses the player has remaining
  int guesses;
    // true if the game has ended
    bool end[2]={false,false};
  // Containers holding the different types of ships for the 2 players
  Ship playerShips[2][SHIP_TYPES];
  // Players' game boards
  Board playerBoard[2];
  Board shipsBoard[2];
  // Point on the board the player wishes to place their ship
  Point shipPlacement;
  // Direction the player chooses to lay their ship (vertical/horizontal)
  DIRECTION directionChoice;
  // The result of the game
  int win=0;
  
  // Begin by initalizing the ships with the proper values (names, sizes, etc.)
  for(int i=0;i<2;i++)
    Ship::LoadShips(playerShips[i]);

    
  // Greet user to game
  cout << "\t\t\t     Welcome to BATTLESHIP" << endl << endl;
  cout << "Each player begins the game with 5 ships, you must sink your opponent's ships!" << endl;
  cout << "Guess your opponent's ships' location by inputing a row number and column number\n";
  cout << "Choose the maximum number of guesses for the game." << endl;
  cin >> Max;
  const int MAX_GUESSES = Max;  
  cout << "\nBEGIN WAR" << endl << endl;
  
  // While user wishes to continue playing
  do
    {
      // Reset guesses to the max number of guesses for each new game
      guesses = MAX_GUESSES;
	
      // Reset players' boards for each new game
      for(int i=0;i<2;i++){
	playerBoard[i].ResetBoard();
	shipsBoard[i].ResetBoard();
      }
	
      // Ships Placement

      for(int i=0;i<2;i++){
	cout << "Player "<< i+1 << " turn"<<endl;
	PlacementPhase(shipsBoard[i],playerShips[i]);
      }
      // Declaration and initialization of each player's fleet of ships using their respective 'Ships' arrays
      Fleet playerFleet[2];
      for(int i=0;i<2;i++)
          playerFleet[i].FillFleet(playerShips[i]);
          //Fleet playerFleet[0](playerShips[0]);
          // Fleet playerFleet[1](playerShips[1]);
        
        
        
        
	  
      // Success is determined by whether they hit an opponent ship or not
      bool userSuccess[2]; 

      
      // While the match is not ended...
      while( guesses > 0 && end[0]==false && end[1]==false)
	{
	  // for each player...
	  for(int i=0;i<2;i++){
	    userSuccess[i]=true;
	    // user's turn continues if they successfully land a hit
	    while(userSuccess[i] && end[0]==false && end[1]==false)
	      {
		cout<<"\nPlayer "<<i+1<<" turn"<<endl;
		Turn(userSuccess[i],guesses,playerBoard[i],playerShips[Oi(i)],end[i]);
	      }
	  }
	  // After each turn, decrease the user's amount of guesses by one
	  guesses--;
	}
	  
      cout << "\nGAME OVER.\n";

      // Win establish the result of the match
      for(int i=0;i<2;i++){
	if( end[i]==true)
	  win=(i+1);
      }

      // If the gameplay loop has been exited from, this must mean either
      // 0.) Players ran out of guesses
      // 1.) The Player2's fleet has been sunk by the Player1
      // 2.) The Player1's fleet has been sunk by the Player2
      // Therefore the appropriate message must be chosen once the game ends
	  
      if(win==0) cout << "\nYou ran out of guesses! Tie game.\n";
	  
      else if(win==1 || win==2) cout<<"\nPlayer "<<Oi(win-1)+1<<"'s battleships are sunk! Player "<<win<<" win!\n";

      // Ask user if they would like to play again
      cout << "\nPlay again? Enter 'y' for yes, 'n' for no: ";
      // Prompt user for an eligible response if they have yet to give one
      do{
	cin>>userDecision;
	if(userDecision != 'y' && userDecision != 'n')
	  cout << "You did not enter 'y' or 'n'. Please do so: ";
      }while ( userDecision != 'y' && userDecision != 'n' );
      // If the user wishes to play again..
      if( userDecision == 'y' )
	// Set the continuePlaying flag to true to reenter the gameplay loop
	continuePlaying = true;
      // If the user wishes to not play again..
      else if ( userDecision == 'n' )
	// Set the continuePlaying flag to  false to exit the gameplay loop
	continuePlaying = false;
	  
      cout << endl;
    }while(continuePlaying);
  
  // Thank user for playing and terminate the game
  cout << "Thank you for playing BATTLESHIP" << endl;
  cout << "Goodbye." << endl;
  
  
  // system("pause"); /// Finding a breakpoint alternative --> too hard to debug , instead I found cin.get()
    
#ifdef USE_PAUSES
  cin.get();
#endif
    
  return 0;
}
