/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the CaptainsQuarters class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "CaptainsQuarters.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
CaptainsQuarters::CaptainsQuarters() : Space()
{   
    setName("Captain's Quarters");                                              // Call function to set space name
    setDescription("There is a hatch to the Crew Quarters down below,\n"        // Call functio nto set space description
                  "and a door to your right to go back to the Main Deck.");
    setSolved(false);                                                           // Call function to set space status to unsolved
    setOpen(false);                                                             // Call function to set space status to closed
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
CaptainsQuarters::~CaptainsQuarters()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function allows the 
    user to print the list of items in the space, examine a puzzle box, and search a desk.
    
 ************************************************************************************************/
string CaptainsQuarters::explore()
{
    string strAction;                                                                       // Variable to hold user choices
    strAction = menu(2);                                                                    // Call menu function
    if(strAction == "items"){                                                               // If function returns "items"
        return strAction;                                                                       // Return "items"
    }
    else if(strAction == "box"){                                                            // If function returns "box"
        if(!getOpen()){                                                                         // And the box is closed
            cout << "You notice a small box sitting on an ornate cabinet. It's\n"                   // Print riddle
            "beautifully carved with a nautical compass on top. It\n"
            "appears to be locked, but you discover four buttons at the\n"
            "four cardinal points of the compass. On the bottom of the\n"
            "box is an etching of the Spanish Royal Seal and an inscription:\n"
            "\'The empire on which the sun rises but never sets.\'" << endl;
            
            int num = action();                                                                     // Call action function
            if(num == 1){                                                                               // If function returns 1
                return "pin";                                                                               // Make item available
            }
            else{                                                                                       // Else
                return "none";                                                                              // Return none
            }
        }   
        else{                                                                                   // And box is open
            cout << "You have already solved the puzzle box." << endl << endl;                      // Print message       
            return "none";                                                                          // Return "none"
        }
    }
    else if(strAction == "desk"){                                                           // If function returns "desk"
        cout << "You find a writing desk where you hope the captain stored clues to\n"          // Print message
             << "the whereabouts of the emerald. Though, all you find are sketches for\n"
             << "a pully and locking mechanism." << endl << endl;
        setSolved(true);                                                                        // Set space status to solved
        return "clue";                                                                          // Return "clue"
    }
}

/************************************************************************************************

    action() is a specified item interaction in the space. 
    This function prompts a riddle for the user to answer.
    
 ************************************************************************************************/
int CaptainsQuarters::action()
{
    string strAction;                                           // Variable to hold user's choices
    
    strAction = menu(3);                                        // Call menu function
    if(strAction == "east"){                                        // If user chose East
        setOpen(true);                                                  // Set space status to "open"
        cout << "The sun rises but doesn't set in the East."            // Print message
             << " The box unlocks!" << endl; 
        cout << "You find a curious looking iron pin inside."
             << " For all the trouble,\n"
             << "it must be important." << endl << endl;
        return 1;                                                       // Return 1
    }
    else{                                                           // Else
        cout << "The box remains locked." << endl << endl;              // Print message
        return 0;                                                       // Return 0
    }
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
 ************************************************************************************************/
void CaptainsQuarters::spoilers()
{
    cout << "- The answer to the puzzle box is: East" << endl;
    cout << "- The pin is a key that you will eventually need" << endl;
    cout << "- There is a clue here you must read in order to find the emerald." << endl;
}