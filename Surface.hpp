/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Surface class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Surface : public Space
{
    private: 

    public:  
        Surface();      // Default constructor
        ~Surface();     // Deconstructor
};
#endif
