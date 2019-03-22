/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the CrewQuarters class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "CrewQuarters.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
CrewQuarters::CrewQuarters() : Space()
{   
    setName("Crew Quarters");                                                   // Call function to set space name
    setDescription("The Infirmary is through the door to your left, there\n"    // Call function the set space description
                  "is a hatch that leads up to the Captain's Quarters,\n"
                  "and a door to your right which opens to the Gun Deck.");
    setSolved(false);                                                           // Call function to set space status to unsolved
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
CrewQuarters::~CrewQuarters()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function prompts the
    user to pick up items, read documents, and lift and open objects.
    
 ************************************************************************************************/
string CrewQuarters::explore()
{
    string strAction;                                                                               // Variable to hold user choice
    strAction = menu(4);                                                                            // Call menu function
    if(strAction == "barrels"){                                                                     // If function returns "barrels"
        if(!getSolved()){                                                                               // If space status is solved
            cout << "You've found the crew's stash of rum!" << endl << endl;                                // Print message
            setSolved(true);                                                                                // Set space status to solved
            return "rum";                                                                                   // Return "rum"
        }
        else{                                                                                           // Else
            cout << "You've already opened all the barrels." << endl << endl;                               // Print message
            return "none";                                                                                  // Return "none"
        }
    }
    else if(strAction == "eel1"){                                                                   // If function returns "eel1"
        cout << "An eel lashes out from under the bunks! Defend yourself!" << endl;                     // Print message
        return strAction;                                                                               // Return "eel1"
    }
    else if(strAction == "items"){                                                                  // If function returns "items"
        return strAction;                                                                               // Return "items"
    }
    else if(strAction == "clue"){                                                                   // If function returns "clue"
        cout << "This appears to be a personal log from one of the crew members.\n"                     // Print clue
             << "You try to read it but the pages are extremely delicate and worn. \n"
             << "You're only able to make out a fragment of a passage: \'Qu.rt.r \n"
             << "M.st.r m.k.s tr.ps to the b.w.ls of the sh.p .v.ryd.y, ch.ck.ng the \n"
             << "fl..r b..rds. Is he w.rr..d ab..t the sh.p t.k.ng on w.t.r?\'" << endl << endl;
        setSolved(true);                                                                                // Set space status to solved
        return strAction;                                                                               // Return "clue"
    }
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
 ************************************************************************************************/
void CrewQuarters::spoilers()
{
    cout << "- The rum is useless." << endl;
    cout << "- Don't look under the bunks." << endl;
    cout << "- If the eel bites you, you'll find your flashlight on the Gun Deck." << endl;
    cout << "- There is a clue here you must read in order to find the emerald." << endl;
    cout << "- The passage is meant to read as: \'Quarter Master makes trips \n"
         << "  to the bowels of the ship everyday, checking the floor boards. \n"
         << "  Is he worried about the ship taking on water?\'" << endl << endl;
}