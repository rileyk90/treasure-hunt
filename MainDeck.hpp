/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the MainDeck class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef MAINDECK_HPP
#define MAINDECK_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class MainDeck : public Space
{
    private: 

    public:  
        MainDeck();         // Default constructor
        ~MainDeck();        // Deconstructor
        
        string explore();   // Explore the space
        void spoilers();    // Print hints
};
#endif
