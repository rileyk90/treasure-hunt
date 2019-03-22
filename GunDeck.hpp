/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the GunDeck class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef GUNDECK_HPP
#define GUNDECK_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class GunDeck : public Space
{
    private: 
        bool solved2;       // Additional solved status feature

    public:  
        GunDeck();          // Default constructor
        ~GunDeck();         // Deconstructor
        
        string explore();   // Explore the space
        void spoilers();    // Print hints
};
#endif
