/************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the header file for the Game class. Here, you 
                can find the declarations of the class member variables 
                and the prototypes for the class member functions.
**************************************************************************/ 
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "Space.hpp"
#include "Surface.hpp"
#include "MainDeck.hpp"
#include "CaptainsQuarters.hpp"
#include "GunDeck.hpp"
#include "CrewQuarters.hpp"
#include "Infirmary.hpp"
#include "CargoHold.hpp"
#include "Brig.hpp"
#include "Character.hpp"
#include "Diver.hpp"
#include "Item.hpp"
#include "inputValInt.hpp"
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Game
{
    private: 
        bool gameOver;                  // Tracks game status
        Space *surface;                 // Surface object pointer
        Space *mainDeck;                // Main Deck object pointer
        Space *captainsQuarters;        // Captain's Quarters object pointer
        Space *gunDeck;                 // Gun Deck object pointer
        Space *crewQuarters;            // Crew Quarters object pointer
        Space *infirmary;               // Infirmary object pointer
        Space *cargoHold;               // Cargo Hold object pointer
        Space *brig;                    // Brig object pointer
        Space *currentLocation;         // Current Location object pointer
        Character *diver;               // Diver character object poiner
        Character *eel;                 // Eel character object pointer
        Character *rival;               // Rival character object pointer
        Item *knife;                    // Knife object pointer
        Item *flashlight;               // Flashlight object pointer
        Item *pin;                      // Pin object pointer
        Item *crowbar;                  // Crowbar object pointer
        Item *dagger;                   // Dagger object pointer
        Item *rope;                     // Rope object pointer
        Item *emerald;                  // Emerald object pointer
        Item *rum;                      // Rum object pointer
        Item *clothes;                  // Clothes object pointer
        int dice;                       // Dice count
        int sides;                      // Sides count

    public: 
        Game(string);                   // Constructor
        ~Game();                        // Deconstructor
    
        void setEnvironment();                  // Set the game enviroment
        void runGame();                         // Run the game
        void useAir(int);                       // Diver uses air
        void recovery(int);                     // Diver recovers from wounds
        void battle(Character*, Character*);    // Initiate battle between characters 
        void round(Character*, Character*);     // Current round of the battle
        void pickupItems();                     // Pick up items in the space
        void viewStats();                       // Print diver's current game statistics
        void getTreasure();                     // Diver escapes from trap with treasure
        void solveClues();                      // Evaluates status of clues found
};
#endif