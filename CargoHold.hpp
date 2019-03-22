/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the CargoHold class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef CARGOHOLD_HPP
#define CARGOHOLD_HPP

#include "menu.hpp"
#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class CargoHold : public Space
{
    private: 
    
    public:  
        CargoHold();            // Default constructor
        ~CargoHold();           // Deconstructor
        
        string explore();       // Explore the space
        void spoilers();        // Print hints
};
#endif
