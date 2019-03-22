/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the CargoHold class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "CargoHold.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
CargoHold::CargoHold() : Space()
{   
    setName("Cargo Hold");                                                          // Call function to set space name
    setDescription("There is an iron door to your left that seals the Brig,\n"      // Call function to set space description
                  "and a hatch that leads back up to the Gun Deck.");
    setSolved(false);                                                               // Set space status to unsolved
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
CargoHold::~CargoHold()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function prompts the
    user to pick up items, read documents, and lift and open objects.
    
 ************************************************************************************************/
string CargoHold::explore()
{
    string strAction;                                                           // Variable to hold user's choice
    strAction = menu(11);                                                       // Call menu function
    if(strAction == "clue"){                                                    // If function returns "clue"
        setSolved(true);                                                            // Set space status to solved
        cout << "The ship's manifest lists cargo, crew,"                            // Print message
             << " food and munition stores, and\n"
             << "a prisoner named \'Esmeralda\'. "
             << "Perhaps she was taken for ransom?" << endl << endl;
    }
    else if(strAction == "eel3"){                                               // If function returns "eel3"
        cout << "By moving the tarp you disturbed a sleeping eel, "                 // Print message
             << "who lashes out. Defend yourself!" << endl;
    }
    else if(strAction == "chest"){                                              // If function returns "chest"
        cout << "Looks like this was a wealthy woman's wardrobe trunk. "            // Print message
             << "Nothing of value remains." << endl << endl;
    }
    return strAction;                                                           // Return user's menu choice
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
 ************************************************************************************************/
void CargoHold::spoilers()
{
    cout << "- Don't lift the tarp." << endl;
    cout << "- If the eel bites you, you'll find your flashlight in the Brig." << endl;
    cout << "- The clothes are useless." << endl;
    cout << "- There is a clue here you must read in order to find the emerald." << endl;
    cout << "- Esmeralda is not a person, though she is in prison." << endl;
}
