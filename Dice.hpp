/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Dice class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#include<iostream>

#ifndef DICE_HPP
#define DICE_HPP

using std::cout;
using std::cin;
using std::endl;

class Dice
{
    private:
        int qty;           // Number of dice
        int sides;         // Number of sides
        int roll;          // Total points from roll
    
    public:                 
        Dice(int, int);         // Constructor
        ~Dice();                // De-constructor
        
        int getRoll();          // Get dice roll
};
#endif