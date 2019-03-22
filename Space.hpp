/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Space class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef SPACE_HPP
#define SPACE_HPP

#include "menu.hpp"
#include "Diver.hpp"
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Space
{   
    protected: 
        Space *top;             // Pointer to top linked space
        Space *right;           // Pointer to right linked space
        Space *left;            // Pointer to left linked space
        Space *bottom;          // Pointer to bottom linked space
        vector<Item*>items;     // Container for Space items

        string name;            // Name of the space
        string description;     // Description of space
        bool clue;              // Clue found
        bool solved;            // Room un/solved
        bool open;              // Room open/closed
        bool done;              // Room done?
        

    public:
        Space();                    // Default constructor
        virtual ~Space();           // Deconstructor
    
        void setName(string);           // Set the room name
        string getName();               // Get the room name
        void setDescription(string);    // Set the room description
        string getDescription();        // Get the room description
        void setTopSpace(Space*);       // Set top linked space
        Space* getTopSpace();           // Get top linked space
        void setRightSpace(Space*);     // Set right linked space
        Space* getRightSpace();         // Get right linked space
        void setLeftSpace(Space*);      // Set left linked space
        Space* getLeftSpace();          // Get left linked space
        void setBottomSpace(Space*);    // Set bottom linked space
        Space* getBottomSpace();        // Get bottom linked space
        int getSize();                  // Get the size of the room's item vector
        Item* getItem(int);             // Get an item in the vector
        int addItem(Item*);             // Add an item to the room vector
        void removeItem(Item*);         // Remove and item from the room vector
        int printStats();               // Print the statistics of the room
        void printItems();              // Print the items in the room
        void setDone(bool);             // Set the room done status
        bool getDone();                 // Get the room done status
        void setOpen(bool);             // Set the room open status
        bool getOpen();                 // Get the room open status
        void setSolved(bool);           // Set the room sovled status
        bool getSolved();               // Get the room solved status
    
        virtual string explore();       // Explore the space
        virtual int action();           // Item specific interaction
        virtual void spoilers();        // Print hints
};
#endif
