/****************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the menu() function.
                This function is a main switch in which its cases each 
                ask for user input, after which another nested case returns 
                a value based on the users choice. The design is made to be 
                versatile, i.e. easily customizable to future programs.
******************************************************************************/ 
#include "menu.hpp"

string menu(int num){

    string choiceNum;                               // User input menu choice
    int valNum;                                     // Holds resulting value of a user's input
    string action;                                  // Holds menu action
    string errorMsg = "Error: INVALID INPUT";       // Common error message for invalid input
    bool valid = false;
    
    do{                                                     // Loop until input is valid
        switch (num){                          
            cout << "What do you do?" << endl;
/*********************************************************************************************************
    
        Main Menu
    
*********************************************************************************************************/
            case 1:
                cout << endl;
                cout << "1. Go up" << endl;
                cout << "2. Go left" << endl;
                cout << "3. Go right" << endl;
                cout << "4. Go down" << endl;
                cout << "5. Explore" << endl;
                cout << "6. View your stats" << endl;
                cout << "7. **Spoilers" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "7", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "top";                                 // User chose go up
                        break;
                    case 2:
                        cout << endl;
                        action = "left";                                // User chose to go left
                        break;
                    case 3:
                        cout << endl;
                        action = "right";                               // User chose to go right
                        break;
                    case 4:
                        cout << endl;
                        action = "bottom";                              // USer chose to go down
                        break;
                    case 5:
                        cout << endl;
                        action = "explore";                             // User chose to explore the area
                        break;
                    case 6:
                        cout << endl;
                        action = "stats";                               // User chose to print their stats
                        break;
                    case 7:
                        cout << endl;
                        action = "spoilers";                            // User chose to print hints
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Captain's Quarters
    
*********************************************************************************************************/
            case 2:
                cout << endl;
                cout << "What do you want to do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Examine box" << endl;
                cout << "3. Open desk" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "3", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "box";                                 // User chose to examine the box
                        break;
                    case 3:
                        cout << endl;
                        action = "desk";                                // USer chose to open the desk
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Captain's Quarters - box
    
*********************************************************************************************************/
            case 3:
                cout << endl;
                cout << "Which button do you choose?" << endl;
                cout << "1. North" << endl;
                cout << "2. South" << endl;
                cout << "3. East" << endl;
                cout << "4. West" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "4", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "north";                               // User chose North
                        break;
                    case 2:
                        cout << endl;
                        action = "south";                               // User chose South
                        break;
                    case 3:
                        cout << endl;
                        action = "east";                                // USer chose East
                        break;
                    case 4:
                        cout << endl;
                        action = "west";                                // User chose West
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Crew Quarters 
    
*********************************************************************************************************/
            case 4:
                cout << "What do you want to do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Open barrels" << endl;
                cout << "3. Look under bunks" << endl;
                cout << "4. Read journal" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "4", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "barrels";                             // User chose to open the barrels
                        break;
                    case 3:
                        cout << endl;
                        action = "eel1";                                // User chose to look under the bunks
                        break;
                    case 4:
                        cout << endl;
                        action = "clue";                                // User chose to read the journal
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Infirmary
    
*********************************************************************************************************/
            case 5:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Dress wounds" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "2", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "bandages";                            // User chose to use bandages
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Main Deck
    
*********************************************************************************************************/
            case 6:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Move along" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "2", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "none";                                // User chose to move along
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Gun Deck
    
*********************************************************************************************************/
            case 7:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Look in the crates" << endl;
                cout << "3. Reach inside the canon" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "3", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "crates";                              // User chose to look in the crates
                        break;
                    case 3:
                        cout << endl;
                        action = "canon";                               // User chose to reach into the canon
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        The Brig - open, not solved
    
*********************************************************************************************************/
            case 8:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Look around" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "2", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "look";                                // USer chose to look around
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        The Brig - open, solved
    
*********************************************************************************************************/
            case 9:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Pry open the floor boards" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "2", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "pry";                                 // User chose to pry up the floor boards
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        The Brig - closed, solved
    
*********************************************************************************************************/
            case 10:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. FREAK OUT" << endl;
                cout << "2. Search your bag for something to open the door" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "2", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "freak";                               // User chose to freak out
                        break;
                    case 2:
                        cout << endl;
                        action = "search";                              // User chose to search for a tool
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Cargo Hold
    
*********************************************************************************************************/
            case 11:
                cout << endl;
                cout << "What do you do?" << endl;
                cout << "1. Pick up items" << endl;
                cout << "2. Read manifest" << endl;
                cout << "3. Lift tarp" << endl;
                cout << "4. Open chest" << endl;
                getline(cin, choiceNum);                                // Get user input as a string in order to test validity
                valNum = inputValidation("1", "4", choiceNum);          // Test input validity
                switch (valNum){
                    case 1:
                        cout << endl;
                        action = "items";                               // User chose to view items
                        break;
                    case 2:
                        cout << endl;
                        action = "clue";                                // User chose to read the manifest
                        break;
                    case 3:
                        cout << endl;
                        action = "eel3";                                // User chose to lift the tarp
                        break;
                    case 4:
                        cout << endl;
                        action = "chest";                               // User chose to open the chest
                        break;
                    default:
                        cout << endl;
                        cout << errorMsg << endl;
                        action = "error";                               // User made invalid menu choice
                        break;
                }
                break;
/*********************************************************************************************************
    
        Default case executes for invalid input. Prints error message.
    
*********************************************************************************************************/
            default:
                cout << "Error: INVALID INPUT." << endl;            // User made invalid menu choice
        };
    }while(action == "error");                                  // Loop until input is valid
    return action;                                              // Return the menu action
}

    
