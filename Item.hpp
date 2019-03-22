/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Item class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#include<iostream>
#include<string>

#ifndef Item_HPP
#define Item_HPP

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Item
{
    private:
        string name;        // Name of the item
    
    public:                 
        Item(string);       // Constructor
        ~Item();            // De-constructor
    
        void setName(string);   // Set item's name
        string getName();       // Get item's name
};
#endif