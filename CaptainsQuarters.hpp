/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the CaptainsQuarters class. 
                Here, you can find the declarations of the class member 
                variables and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef CAPTAINSQUARTERS_HPP
#define CAPTAINSQUARTERS_HPP

#include "menu.hpp"
#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class CaptainsQuarters : public Space
{
    private: 

    public:  
        CaptainsQuarters();     // Default constructor
        ~CaptainsQuarters();    // Deconstructor
        
        string explore();       // Explore the space
        int action();           // Item specific interaction
        void spoilers();        // Print hints
};
#endif
