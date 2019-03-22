/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Diver class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef DIVER_HPP
#define DIVER_HPP

#include "Character.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Diver : public Character
{
    private: 

    public:  
        Diver(string, int, int);            // Default Constructor
        ~Diver();           // Deconstructor

        int getSize();                  // Get the size of the item vector
        Item* getItem(int);             // Get the position of a specific item in the vector
        int addItem(Item*);             // Add an item object to the vector
        void removeItem(Item*);         // Remove an item object from the vector
        bool hasItem(Item*);            // Check if character has a certain item
        int printStats();               // Print character's list of stats
        void printItems();              // Print character's list of items
};
#endif
