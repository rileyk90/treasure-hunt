/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Infirmary class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef INFIRMARY_HPP
#define INFIRMARY_HPP

#include "Space.hpp"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Infirmary : public Space
{
    private: 

    public:  
        Infirmary();        // Default constructor
        ~Infirmary();       // Deconstructor
        
        string explore();       // Explore the space
        void spoilers();        // Print hints
};
#endif
