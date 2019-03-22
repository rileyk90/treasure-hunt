/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Infirmary class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Infirmary.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
Infirmary::Infirmary() : Space()
{   
    setName("Infirmary");                                               // Call function to set space name
    setDescription("The only way out of this room is to go right, \n"   // Call function to set space description
                  "back to the Crew Quarters.");
    setSolved(false);                                                   // Call function to set space solved status to false
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Infirmary::~Infirmary()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function prompts the
    user to pick up items, and use objects.
    
 ************************************************************************************************/
string Infirmary::explore()
{   
    string strAction;                                                           // Variable to holde user choice
    strAction = menu(5);                                                        // Call menu function
    if(strAction == "bandages"){                                                // If function returns "bandages"
        cout << "There's not much to help heal your wounds on a sunken\n"           // Print message
         << "pirate ship. However, you do find some leather turnicates\n"
         << "that might work well as makeshift bandages." << endl << endl;
    }
    return strAction;                                                           // Return user choice
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player)
    
 ************************************************************************************************/
void Infirmary::spoilers()
{
    cout << "- The supply of bandages is infinite, but you cannot carry them with you." << endl;
    cout << "- Using bandages will recover 10 health points, but it will cost you 5 psi of air." << endl;
}
