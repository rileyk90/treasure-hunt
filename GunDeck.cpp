/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the GunDeck class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "GunDeck.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
GunDeck::GunDeck() : Space()
{   
    setName("Gun Deck");                                                            // Call function to set space name
    setDescription("The Crew Quarters is through the door to your left, there\n"    // Call function to set space description
                  "is a hatch that leads back up to the Main Deck, and a\n"
                  "hatch that leads down to the Cargo Hold.");
    solved2 = false;                                                                // Set additional solved status feature to false
    setSolved(false);                                                               // Set space solved status to false
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
GunDeck::~GunDeck()
{
    // empty
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions. This function prompts the
    user to pick up items, read documents, and lift and open objects.
    
 ************************************************************************************************/
string GunDeck::explore()
{
    string strAction;                                                               // Variable to hold user choice
    strAction = menu(7);                                                            // Call menu function
    if(strAction == "items"){                                                       // If function returns "items"
        return strAction;                                                               // Return user choice
    }
    else if(strAction == "crates"){                                                 // If function returns "crates"
        if(solved2 == false){                                                           // And if solved2 is false
        cout << "There is a crate full of brittle cutlasses. "                              // Print message
             << "Though you do catch a\n"
             << "glimpse of reflection beneath the rust. "
             << "It's a steel dagger with an\n"
             << "ivory hilt that appears to have stood the "
             << "test of time, and corrosion." << endl << endl;
            solved2 = true;                                                                 // Set solved2 to true
            return "dagger";                                                                // Return "dagger"
        }
        else{                                                                           // Else, if solved2 is true
            cout << "There is nothing left in the "                                         // Print message
                 << "crates to discover." << endl << endl;
            return "none";                                                                  // Return "none"
        }
    }
    else if(strAction == "canon"){                                                  // If function returns "canon"
        if(!getSolved()){                                                               // And is solved status is false
        cout << "You've mustered your courage and reached into the unknown\n"               // Print message
             << "... and came out with a crowbar ..." << endl << endl;
            setSolved(true);                                                                // Set solved status to true
            return "crowbar";                                                               // Return "crowbar"
        }
        else{                                                                           // Else, if solved status is true
            cout << "You took one chance too many ... An eel was sitting at the\n"          // Print mesage
                 << "back of the canon barrel and lashes out. Defend yourself!" << endl;
            return "eel2";                                                                  // Return "eel2"
        }
    }
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
 ************************************************************************************************/
void GunDeck::spoilers()
{
    cout << "- Find the crowbar, it is the most useful tool in the game." << endl;
    cout << "- The rope is useless." << endl;
    cout << "- Don't search the canon a second time." << endl;
    cout << "- If the eel bites you, you'll find your flashlight in the cargo hold." << endl;
}