// Board.cpp - Board class function implementation
#include "Board.h"


//******************* Board Constructor **********************//
Board::Board()
{
    
}

//******************* PrintBoard Function **********************//

/// Trying to think about a subtle way in order to build a second board for a 2-players game
// Prints the output board to console showing user their hits, misses, unguessed spaces
void Board::PrintBoard() const
{
  // Print column numbers
  cout << " \t   ";
  for( int number = 1; number < BOARD_LENGTH + 1; number++)
    cout << " " << number;
  cout << endl;
  
  // Print board itself
  // i = row number, j = column number
  for( int i = 0; i < BOARD_LENGTH; i++)
    {
      
      cout << endl;
      // Print row number
      cout << "\t" << i+1;
      if( i != BOARD_LENGTH-1 )
	cout << "  ";
      else
	cout << " ";
      
      // Print columns
      for( int j = 0; j < BOARD_WIDTH; j++)
        {
	  // Print the game board borders to console
	  cout << "|";
          
	  // If the curent space on board has not yet been guessed
	  if( pBoard[i][j] == NOT_GUESSED )
	    // Print the character for water
	    cout << WATER;
	  // If the curent space on board has been guessed and is a hit
	  if( pBoard[i][j] == GUESS_HIT )
	    // Print the character for a hit
	    cout << HIT;
	  // If the curent space on board has been guessed and was not a hit
	  if( pBoard[i][j] == GUESS_MISS )
	    // Print the characer for a miss
	    cout << MISS;
	  
        } // end of the inner for-loop
      
      
      // Print the game board borders to console
      cout << "|";
      cout << endl;
    } 
  // Output the board key to console so user can interpret their board
  cout << "\n'~' = NOT GUESSED \t'O' = MISS \t'X' = HIT\n";
  cout << endl;
  
}


//******************* ResetBoard Function **********************//


// Resets the outputBoard to 0
void Board::ResetBoard()
{
  // Go through each row of outputBoard
  for( int i = 0; i < BOARD_WIDTH; i++)
    {
      // Go through each column of output board
      for(int j=0; j < BOARD_LENGTH; j++)
	pBoard[i][j] = NOT_GUESSED;
    } 
}


//******************* MarkBoard Function **********************//

// Marks the outputBoard with a certain character depending on
// whether the user guess was a hit or miss
void Board::MarkBoard(bool hit, Point guessCoordinate)
{
  // Decrement coordinates for indexing
  guessCoordinate.X--;
  guessCoordinate.Y--;
    
  // If the coodinate the player guessed was a hit..
  if( hit == true )
    {
      // Mark the outputBoard with the corresponding character
      pBoard[guessCoordinate.X][guessCoordinate.Y] = 1;
    }
  
  // If the coordinate he player guessed was a miss
  else
    {
      // Mark the outputBoard with the corresponding character
      pBoard[guessCoordinate.X][guessCoordinate.Y] = 2;
    }
}



//******************* CheckGuess Function **********************//

// Determines whether the player's guess is valid or not, returns true if the guess is INVALID
// A guess is NOT valid if
//		1- The point that has been guessed is not contained on the board ( i.e. (123,43) )
//		2. The player has already guessed the same point

bool Board::CheckGuess(Point guessCoordinate) const
{
  // Decrement coordinate or indexing
  guessCoordinate.X--;
  guessCoordinate.Y--;
  
  // If the given point has already been guessed..
  if( pBoard[guessCoordinate.X][guessCoordinate.Y] != 0 )
    return true;
  
  // If the given point is greater than the size of the board
  else if( guessCoordinate.X >= BOARD_LENGTH || guessCoordinate.Y >=BOARD_WIDTH )
    return true;
  
  // If the given point is less than the minimum size of the board
  else if( guessCoordinate.X < 0 || guessCoordinate.Y < 0 )
    return true;

  // If the preceding criteria has been met, the guess is valid
  else return false;
}


///Well done 
