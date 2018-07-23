//  Point.h - Point class declaration


// #pragma once is better than #ifndef etc.. Since the compiler itself is responsible for handling #pragma once, the programmer cannot make errors which cause name clashes."
// ref:  https://en.wikipedia.org/wiki/Pragma_once
#pragma once

#include <iostream>
using namespace std;

#define BOARD_LENGTH 10
#define BOARD_WIDTH 10

// Structure definition for Point struct
// Here is why We decided to use it : https://msdn.microsoft.com/en-us/library/ms229017(v=vs.110).aspx
// In this situation is actually better than a class, or at least Microsoft thinks it. --joke--
// Corresponds to a row number and column number
struct Point
{
  // A location on the grid defined
  // by X(horizontal) Y(vertical) coordinates
  int X;
  int Y;
    
  // Equivalence operator defined for Point types
  bool operator == (const Point& compareTo) const
  {
    return ( (X == compareTo.X) && (Y == compareTo.Y) );
  }
    
};
    
    

// Outputs point in traditional format (row#, column#)
// The inline qualifier "advises" the compiler to generate a copy of the -- not at all,
//function's code in place to avoid a function call
// We also used ostream operator overloading :  Output operator is defined for Point types

// looking for template instead of inline ostream& operator...

inline ostream& operator <<(ostream& out, Point myPoint)
{
  // Increment X and Y coordinate to account for indexing 
  // myPoint.X++; myPoint.Y++;
        
  // Prints the coordinate to the console in traditional form (X,Y)
  out << "(" << myPoint.X << "," << myPoint.Y << ")";
  return out;
}
