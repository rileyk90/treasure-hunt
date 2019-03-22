/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Brig class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef BRIG_HPP
#define BRIG_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Brig : public Space
{
    private: 
        
    public:  
        Brig();              // Default constructor
        ~Brig();             // Deconstructor
        
        string explore();    // Explore the space
        void spoilers();     // Print hints
};
#endif
