/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the MainDeck class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "MainDeck.hpp"

/************************************************************************************************

    Constructor 
    
 ************************************************************************************************/
MainDeck::MainDeck() : Space()
{   
    setName("Main Deck of the pirate vessel");                          // Call function to set space name                
    setDescription("The Captain's Quarters are to your left, "          // Call function to set space description
                     "and there is a hatch to the Gun\n" 
                     "Deck below. Or, you may go back up to the " 
                     "Surface to end your expedition.");
    setSolved(true);                                                    // Call function to set space solved status to true
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
MainDeck::~MainDeck()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function prompts the
    user to pick up items, read documents, and lift and open objects.
    
 ************************************************************************************************/
string MainDeck::explore()
{
    string strAction;                                       // Variable to old user choice
    strAction = menu(6);                                    // Call menu function
    if(strAction == "none"){                                // If function returns "none"
        cout << "There is nothing here of note. "               // Print message
            << "Head inside the ship." << endl << endl;
    }
    return strAction;                                       // Return user choice
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
 ************************************************************************************************/
void MainDeck::spoilers()
{
    cout << "- Conserve your air, find better tools, and mind your health. Finding the treasure is not enough to win." << endl;
    cout << "- Moving between spaces, solving puzzles, battling enemies, even bandaging a wound will use up air." << endl;
    cout << "- You don't need it here, but keep your flashlight with you ALWAYS." << endl;
}