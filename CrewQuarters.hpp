/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the CrewQuarters class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef CREWQUARTERS_HPP
#define CREWQUARTERS_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class CrewQuarters : public Space
{
    private: 

    public:  
        CrewQuarters();         // Default constructor
        ~CrewQuarters();        // Deconstructor

        string explore();       // Explore the space
        void spoilers();        // Print hints
};
#endif
