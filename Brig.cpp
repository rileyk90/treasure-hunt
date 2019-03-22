/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Brig class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Brig.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
Brig::Brig() : Space()
{   
    setName("Brig");                                                    // Call function to set space name
    setDescription("The only way out of this room is to go right,\n"    // Call function to set space description
                  "back to the Cargo Hold.");
    setSolved(false);                                                   // Call function to set space status to unsolved
    setOpen(true);                                                      // Call function to set space status to open
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Brig::~Brig()
{
    // empty
}

/************************************************************************************************

    explore() manages the action options in the Brig space depending on what the status of
    the space is: if the door of the Brig is open the diver can move in and out freely, if 
    the door is closed the diver is trapped, if the space is unsolved the diver has not yet 
    found the emerald, if the space is solved the diver can collect the emerald and proceed 
    with the game.
    
 ************************************************************************************************/
string Brig::explore()
{
    string strAction;                                                       // Variable to hold action identifier
    if(getOpen()){                                                          // If space is open
        if(!getSolved()){                                                       // And not solved
            strAction = menu(8);                                                    // Call menu function
            if(strAction == "items"){                                               // If function returns "items"
                return strAction;                                                       // Return "items"
            }
            else if(strAction == "look"){                                           // If functon returns "look"
                cout << endl << "There doesn't appear to be "                            // Print message
                << "anything of importance in here." << endl << endl;
                return "none";                                                          // Return "none
            }
        }
        else if(getSolved()){                                                   // And solved
            if(!getDone()){                                                         // And not done
                strAction = menu(9);                                                    // Call menu function
                return strAction;                                                       // Return choice
            }
            else{                                                                   // And not done
                strAction = menu(8);                                                    // Call menu function
                if(strAction == "items"){                                               // If function returns "items"
                    return strAction;                                                       // Return "items"
                }
                else if(strAction == "look"){                                           // If functon returns "look"
                    cout << endl << "There doesn't appear to be "                            // Print message
                    << "anything of importance in here." << endl << endl;
                    return "none";                                                          // Return "none
            }
            }
        }
    }
    else if(!getOpen()){                                                    // If space is closed
        strAction = menu(10);                                                   // Call menu function
        return strAction;                                                       // Return choice
    }
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
************************************************************************************************/
void Brig::spoilers()
{
    cout << "- Don't do anything in here without having some kind of metal tool." << endl;
    cout << "- Don't forget the emerald on your way out!" << endl;
}