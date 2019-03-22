/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Dice class. Here, you 
                can find the initialization of the class member variables and 
                definition of the class member function.
*****************************************************************************/ 
#include "Dice.hpp"

/************************************************************************************************

    The constructor initializes the quantity of dice and their number of sides.
    
 ************************************************************************************************/
Dice::Dice(int q, int s)
{   
    qty = q;        // Initialize quantity of dice to integer passed into constructor
    sides = s;      // Initialize number of sides for each die to integer passed into constructor
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Dice::~Dice()
{   
    // empty
}

/************************************************************************************************
    
    getRoll() generates a random number between 1 and the die's number of sides, 
    returning the random number as the die roll result.
    
 ************************************************************************************************/
int Dice::getRoll()
{
    roll = 0;                               // Total roll initialized to 0
    
    for(int i = 0; i < qty; i++){           // For each die
        roll += (rand() % sides + 1);           // Sum the rolls of random generated numbers between 1 and the number of sides
    }
    
    return roll;                            // Return the total roll count
}