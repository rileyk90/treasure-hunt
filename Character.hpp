/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Character class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Dice.hpp"
#include "Item.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::find;

class Character
{
    protected: 
        string name;                // Character's name
        int air;                    // Character's air level
        int strength;               // Character's strength points
        int armor;                  // Character's armor points
        Dice *roll;                 // Dice object pointer
        int attackPts;              // Resulting attack points
        int defensePts;             // Resulting defense points
        int damage;                 // Damage inflicted to defender
        int recoverPts;             // Resulting recovery points
        vector<Item*>items;         // Character's item container

    public:
        Character(string, int, int);    // Constructor
        virtual ~Character();           // Deconstructor
    
        void setName(string);           // Set the character's name
        string getName();               // Get the character's name
        void setAir(int);               // Set the character's air level
        int getAir();                   // Get the character's air level
        void setStrength(int);          // Set the character's strength
        int getStrength();              // Get the character's strength
        void setArmor(int);             // Set the character's armor
        int getArmor();                 // Get the character's armor
        int attack(int, int);           // Call character to attack
        void defend(int);               // Call character to defend
    
        virtual int getSize();                  // Get the size of the item vector
        virtual Item* getItem(int);             // Get the position of a specific item in the vector
        virtual int addItem(Item*);             // Add an item object to the vector
        virtual void removeItem(Item*);         // Remove an item object from the vector
        virtual bool hasItem(Item*);            // Check if character has a certain item
        virtual int printStats();               // Print character's list of stats
        virtual void printItems();              // Print character's list of items
};
#endif
