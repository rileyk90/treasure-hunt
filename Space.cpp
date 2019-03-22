/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Space class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Space.hpp"

/************************************************************************************************

    Default constructor 
    
************************************************************************************************/
Space::Space()
{   
	setTopSpace(NULL);          // Set linked top space to null
    setRightSpace(NULL);        // Set linked right space to null
    setLeftSpace(NULL);         // Set linked left space to null
    setBottomSpace(NULL);       // Set linked bottom space to null
    clue = false;               // Set clue to false
    setDone(false);             // Set room done status to false
}

/************************************************************************************************

    Deconstructor
    
************************************************************************************************/
Space::~Space()
{
	// empty
}

/************************************************************************************************

    setName() assigns the room's name to the string passed into the parameter
    
************************************************************************************************/
void Space::setName(string n)
{
    name = n;
}

/************************************************************************************************

    getName() returns the name of the room
    
************************************************************************************************/
string Space::getName()
{
    return name;
}

/************************************************************************************************

    setDescription() assigns the room's description to the string passed into the parameter
    
************************************************************************************************/
void Space::setDescription(string d)
{
    description = d;
}

/************************************************************************************************

    getDescription() returns the description of the room
    
************************************************************************************************/
string Space::getDescription()
{
    return description;
}

/************************************************************************************************

    setTopSpace() sets the top linked space of the room to the pointer passed into the function
    
************************************************************************************************/
void Space::setTopSpace(Space* t)
{
    top = t;
}

/************************************************************************************************

    getTopSpace() returns the pointer to the top linked space object
    
************************************************************************************************/
Space* Space::getTopSpace()
{
    return top;
}

/************************************************************************************************

    setRightSpace() sets the right linked space of the room to the pointer passed into the function
    
************************************************************************************************/
void Space::setRightSpace(Space* r)
{
    right = r;
}

/************************************************************************************************

    getRightSpace() returns the pointer to the right linked space object
    
************************************************************************************************/
Space* Space::getRightSpace() 
{
    return right;
}

/************************************************************************************************

    setLeftSpace() sets the left linked space of the room to the pointer
    passed into the function
    
************************************************************************************************/
void Space::setLeftSpace(Space* l)
{
    left = l;
}      

/************************************************************************************************

    getLeftSpace() returns the pointer to the left linked space object
    
************************************************************************************************/
Space* Space::getLeftSpace()
{
    return left;
}

/************************************************************************************************

    setBottomSpace() sets the bottom linked space of the room to the pointer
    passed into the function
    
************************************************************************************************/
void Space::setBottomSpace(Space* b)  
{
    bottom = b;
}

/************************************************************************************************

    getBottomSpace() returns the pointer to the bottom linked space object
    
************************************************************************************************/
Space* Space::getBottomSpace() 
{
    return bottom;   
}

/************************************************************************************************

    getItem() returns the specific item designated by the user's integer input
    
************************************************************************************************/
Item* Space:: getItem(int i)
{
    return items.at(i - 1);
}

/************************************************************************************************

    addItem() takes an Item object pointer and appends it to the back of the items vector.
    
************************************************************************************************/
int Space::addItem(Item *i)
{   
    items.push_back(i);
    return 0;  
}

/************************************************************************************************
    
    removeItem() checks to see if the vector is empty, and if it isn't the function
    searches for and removes the pointer matching the one passed into the function.
    
************************************************************************************************/
void Space::removeItem(Item *i)
{        
    if(items.empty()){                                                          // If vector is empty
        printItems();                                                               // Print message
    }
    else{                                                                       // Else
        items.erase(std::remove(items.begin(), items.end(), i), items.end());       // Search for and remove pointer from vector
    }             
}

/************************************************************************************************

    getSize() returns the number of elements in the character's items vector
    
************************************************************************************************/
int Space::getSize()
{
    return items.size();
}

/************************************************************************************************
    
    printStats() prints a list of the space's vital statistics 
    
************************************************************************************************/
int Space::printStats()
{
    if(items.empty()){                                                      // If the item vector is empty
        cout << "There is nothing available to collect." << endl;               // Print message
        return 0;                                                               // Return 0
    }
    else{                                                                   // Else
        cout << "Items in the space: " << endl;                                 
        printItems();                                                           // Call function to print items
        cout << endl;
    }
    
    bool valid = false;                                                     // Set valid to false
    string str;
    do{                                                                     // Loop until valid
        cout << "Pick up an item?" << endl;                                     // Prompt user to pick up and item
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        getline(cin, str);                                                      // Get user input as a string
        if(str == "1"){                                                         // If user entered 1
            valid = true;                                                           // Valid input
            return 1;                                                               // Return 1
        }
        else if(str == "2"){                                                    // If user entered 2
            valid = true;                                                           // Valid input
            return 2;                                                               // Return 2
        }
        else{                                                                   // Else
            cout << endl <<  "ERROR: Invalid input" << endl << endl;                // Print error mesage
            valid = false;                                                          // Invalid input
        }
    }while(!valid);                                                         // Loop until valid
}

/************************************************************************************************

    printItems() prints a list o fthe items in the character's items vector
    
************************************************************************************************/
void Space::printItems()
{
    if(items.empty()){                                                      // If the vector is empty
        cout << "There is nothing available to collect." << endl;               // Print message
    }
    else{
        for(int i = 0; i < items.size(); i++){                                  // For each item in the vector
            cout << i + 1 << ") " << items.at(i)->getName() << endl;            // Print the item in order
        }
    }
}

/************************************************************************************************

    setDone() sets space done status to bool passed into function
    
************************************************************************************************/
void Space::setDone(bool d)
{
    done = d;
}

/************************************************************************************************

    getDone() returns the done status of the space
    
************************************************************************************************/
bool Space::getDone()
{
    return done;
}

/************************************************************************************************

    setOpen() sets space open status to bool passed into function
    
************************************************************************************************/
void Space::setOpen(bool o)
{
    open = o;
}

/************************************************************************************************

    getOpen() returns the open status of the space
    
************************************************************************************************/
bool Space::getOpen()
{
    return open;
}

/************************************************************************************************

    setSolved() sets space solved status to bool passed into function
    
 ************************************************************************************************/
void Space::setSolved(bool s)
{
    solved = s;
}

/************************************************************************************************

    getSolved() returns the solved status of the space
    
************************************************************************************************/
bool Space::getSolved()
{
    return solved;
}

/************************************************************************************************

    explore() prompts the user for space-specific interactions
    
************************************************************************************************/
string Space::explore()
{
    //pure virtual
    return "none";
}

/************************************************************************************************

    action() is a specified item interaction in the space. 
    
************************************************************************************************/
int Space::action()
{
    //pure virtual
    return 0;
}

/************************************************************************************************

    spoilers() prints list of space-specific hints, answers and tips for the player
    
************************************************************************************************/
void Space::spoilers()
{
    //pure virtual
}