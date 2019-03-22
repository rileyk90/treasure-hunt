/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Character class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Character.hpp"

/************************************************************************************************

    Default constructor 
    
 ************************************************************************************************/
Character::Character(string n, int s, int a)
{   
    setName(n);         // Call function to set character name
    setStrength(s);     // Call function to set character strength
    setArmor(a);        // Call function to set chracter armor
}

/************************************************************************************************

    Deconstructor
    
 ************************************************************************************************/
Character::~Character()
{
    // empty
}

/************************************************************************************************

    setName() assigns the character's name to the string passed into the function.
    
 ************************************************************************************************/
void Character::setName(string n)
{
    name = n;
}

/************************************************************************************************

    getName() returns the character's name as a string.
    
 ************************************************************************************************/
string Character::getName()
{
    if (name.length() <= 0) {           // If string has no characters
        return "unknown";                   // Return default string
    }
    return name;
}

/************************************************************************************************

    setAir() assigns the character's air supply to the integer passed into the function.
    
 ************************************************************************************************/
void Character::setAir(int a)
{
    air = a;
}

/************************************************************************************************

    getAir() returns the value of the character's air supply
    
 ************************************************************************************************/
int Character::getAir()
{
    return air;
}

/************************************************************************************************

    setStrength() assigns the character's health to the integer passed into the function.
    
 ************************************************************************************************/
void Character::setStrength(int s)
{
    strength = s;
}

/************************************************************************************************

    getStrength() returns the value of the character's health
    
 ************************************************************************************************/
int Character::getStrength()
{
    return strength;
}

/************************************************************************************************

    setArmor() assigns the character's armor points to the integer passed into the function.
    
 ************************************************************************************************/
void Character::setArmor(int a)
{
    armor = a;
}

/************************************************************************************************

    getArmor() returns the armor points of the character.
    
 ************************************************************************************************/
int Character::getArmor()
{
    return armor;
}

/************************************************************************************************

    attack() calls the character to roll dice for their attack points, 
    using the integers passed into the function.
    
 ************************************************************************************************/
int Character::attack(int d, int s)
{
    roll = new Dice(d, s);                  // Create new Dice object with d dice with s sides each
    
    attackPts = roll->getRoll();            // Get the total count of the dice roll
    
    delete roll;                            // Delete the Dice object
    
    return attackPts;                       // Return the total count of the roll as the character's attack points
}

/************************************************************************************************

    defend() calls the character to roll dice for the defense points, 
    then calculates the damage and resulting new strength.
    
 ************************************************************************************************/
void Character::defend(int a)
{
    roll = new Dice(2, 6);                      // Create new Dice object with number of defense dice with 6 sides each
    
    defensePts = roll->getRoll();               // Get the total count of the dice roll
    
    delete roll;                                // Delete the Dice object
    
    damage = a - defensePts - armor;       // Calculate damage inflicted
    if(damage < 0){                             // If damage is less than 0
        damage = 0;                                 // Set damage to 0
    }

    strength -= damage;                         // Subtract damage from character's strength points
}

/************************************************************************************************

    getSize() returns the number of elements in the character's items vector
    
 ************************************************************************************************/
int Character::getSize()
{
    // pure virtual
}

/************************************************************************************************

    getItem() returns the specific item designated by the user's integer input
    
 ************************************************************************************************/
Item* Character:: getItem(int i)
{
    // pure virtual
}

/************************************************************************************************

    addItem() takes an Item object pointer and appends it to the back of the items vector.
    
 ************************************************************************************************/
int Character::addItem(Item *i)
{   
    // pure virtual
}

/************************************************************************************************
    
    removeItem() checks to see if the vector is empty, and if it isn't the function
    searches for and removes the pointer matching the one passed into the function.
    
************************************************************************************************/
void Character::removeItem(Item* i)
{         
    // pure virtual
}

/************************************************************************************************
    
    hasItem() searches for an item pointer specified by the user. If the item is found
    in the item vector, the function returns true, and if not the function returns false.
    
************************************************************************************************/
bool Character::hasItem(Item* i)
{
    // pure virtual
}

/************************************************************************************************
    
    printStats() prints a list of the character's vital statistics
    
************************************************************************************************/
int Character::printStats()
{
    // pure virtual
}

/************************************************************************************************
    
    printItems() prints a list o fthe items in the character's items vector
    
************************************************************************************************/
void Character::printItems()
{
    // pure virtual
}
