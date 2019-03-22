/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Surface class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Surface.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
Surface::Surface() : Space()
{   
    setName("Surface");             //Call function to set space name
    setDescription("GAME OVER.");   // Call functio nto set space description
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Surface::~Surface()
{
    // empty
}