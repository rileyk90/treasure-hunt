/************************************************************************************ 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the main file for the Treasure Hunter game. 
************************************************************************************/ 
#include "Game.hpp"
#include "inputValidation.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{   
    string name;                // User input as string
    srand(time(NULL));          // Seed for random number generators
    
    cout << endl << "Welcome to the Treasure Hunter game!" << endl << endl;
    cout << "What's your name, explorer?: ";
    getline(cin, name);                                                                                         // Get user's name as string
    
    cout << endl << name << ", you are a world renowned treasure hunter seeking a famed lost emerald\n"         // Print game description
                 << "stolen by pirates from the New World. This emerald is said to be cursed as every\n"
                 << "possessor has met with an untimely death. After having stolen the emerald, the \n"
                 << "pirate captain and his crew were lost at sea, never to be seen again. Years of \n"
                 << "research has lead you to a previously unknown shipwreck in the Caribbean that\n"
                 << "you have authenticated as the pirates' vessel. You've donned your SCUBA gear and \n"
                 << "are ready to explore the ship and find the emerald. But beware, this is a dangerous\n"
                 << "mission as you are not the only treasure hunter on the sea today, and let's not \n"
                 << "forget the creatures of the deep. You have 3000 psi of air, a flashlight, a knife,\n"
                 << "a collection bag, and your wits. Go forth and find your fortune and glory!\n"
                 << "... before you run out of air ..." << endl << endl;
    
    Game game1(name);                                                                                           // Create Game class object
    game1.setEnvironment();                                                                                     // Set the gaming environment
    game1.runGame();                                                                                            // Start and run the game
    cout << "Thanks for playing!" << endl << endl;                                                              // Print terminating message
    return 0;                                                                                                   // End program
}