/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Diver class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Diver.hpp"

/************************************************************************************************

    Constructor 
    
 ************************************************************************************************/
Diver::Diver(string n, int s, int a) : Character(n, s, a)
{   
    setName(n);             // Set name to user input
    setAir(3000);           // Set air to 3000 psi
    setStrength(s);         // Set strength to s
    setArmor(a);            // Set armor to a
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Diver::~Diver()
{
    // empty
}

/************************************************************************************************

    getSize() returns the number of elements in the character's items vector
    
 ************************************************************************************************/
int Diver::getSize()
{
    return items.size();
}

/************************************************************************************************

    getItem() returns the specific item designated by the user's integer input
    
 ************************************************************************************************/
Item* Diver::getItem(int i)
{
    return items.at(i - 1);
}

/************************************************************************************************

    addItem() takes an Item object pointer and appends it to the back of the items vector.
    
 ************************************************************************************************/
int Diver::addItem(Item *i)
{   
    items.push_back(i);
    return 0;
}

/************************************************************************************************
    
    removeItem() checks to see if the vector is empty, and if it isn't the function
    searches for and removes the pointer matching the one passed into the function.
    
************************************************************************************************/
void Diver::removeItem(Item* i)
{         
    if(items.empty()){                                                          // If vector is empty
        printItems();                                                               // Print message
    }
    else{                                                                       // Else
        items.erase(std::remove(items.begin(), items.end(), i), items.end());       // Search for and remove pointer from vector
    }
}

/************************************************************************************************
    
    hasItem() searches for an item pointer specified by the user. If the item is found
    in the item vector, the function returns true, and if not the function returns false.
    
************************************************************************************************/
bool Diver::hasItem(Item* i)
{
    if(find(items.begin(), items.end(), i) != items.end()){     // If item point is found in the vector
        return true;                                                // Return true
    }
    else{                                                       // Else
        return false;                                               // Return false
    }
}


/************************************************************************************************

    printStats() prints a list of the character's vital statistics
    
 ************************************************************************************************/
int Diver::printStats()
{
    cout << "Air: " << getAir() << " psi" << endl;                      // Print the character's air supply
    cout << "Health: " << getStrength() << endl;                        // Print hte character's strength points

    if(items.empty()){                                                  // If the character's items vector is empty
        cout << "You have no items in your bag." << endl << endl;           // Print message
        return 0;                                                           // Return 0
    }
    else{                                                               // Else
        cout << "Items in your bag: " << endl;                          
        printItems();                                                       // Call function to print the vector items
        cout << endl;
    }
    
    bool valid = false;                                                 // Set valid to false
    string str; 
    do{                                                                 // Loop until valid input is given
        cout << "Remove item?" << endl;                                     // Prompt user to remove and item from their list
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        getline(cin, str);                                                  // Get user input as a string
        cout << endl;
        if(str == "1"){                                                     // If the user answers 1
            valid = true;                                                       // Valid input
            return 1;                                                           // Return 1
        }
        else if(str == "2"){                                                // If user answers 2
            valid = true;                                                       // Valid input
            return 2;                                                           // Return 2
        }
        else{                                                                   // Else
            cout << endl <<  "ERROR: Invalid input" << endl << endl;                // Print error mesage
            valid = false;                                                          // Invalid input
        }
    }while(!valid);                                                     // Loop until input is valid
}

/************************************************************************************************

    printItems() prints a list o fthe items in the character's items vector
    
 ************************************************************************************************/
void Diver::printItems()
{
    if(items.empty()){                                                      // If the vector is empty
        cout << "There is nothing available to remove." << endl;                // Print message
    }
    else{
        for(int i = 0; i < items.size(); i++){                                  // For each item in the vector
            cout << i + 1 << ") " << items.at(i)->getName() << endl;            // Print the item in order
        }
    }
}