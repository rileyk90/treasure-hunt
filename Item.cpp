/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Item class. Here, you 
                can find the initialization of the class member variables and 
                definition of the class member function.
*****************************************************************************/ 
#include "Item.hpp"

/************************************************************************************************

    The constructor initializes the quantity of dice and their number of sides.
    
 ************************************************************************************************/
Item::Item(string n)
{   
    setName(n);     // Call function to set item's name
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Item::~Item()
{   
    // empty
}

/************************************************************************************************

   setName() assigns name to string passed into function
    
 ************************************************************************************************/
void Item::setName(string n)
{
    name = n;
}

/************************************************************************************************

    getName() returns the items name
    
 ************************************************************************************************/
string Item::getName()
{
    return name;
}