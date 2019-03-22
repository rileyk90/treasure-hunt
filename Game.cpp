/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the implementation file for the Game class. 
                Here, you can find the initialization of class member 
                variables and definitions of class member functions.
*****************************************************************************/ 
#include "Game.hpp"

/************************************************************************************************

    Constructor creates all the object for the game
    
 ************************************************************************************************/
Game::Game(string name)
{   
    surface = new Surface();                            // Create surface space
    mainDeck = new MainDeck();                          // Create main deck space
    captainsQuarters = new CaptainsQuarters();          // Create captain's quarters space
    crewQuarters = new CrewQuarters();                  // Create crew quarters space
    infirmary = new Infirmary();                        // Create infirmary space
    gunDeck = new GunDeck();                            // Create gun deck space
    cargoHold = new CargoHold();                        // Create cargo hold space
    brig = new Brig();                                  // Create brig space
    
    knife = new Item("knife");                          // Create knife item
    flashlight = new Item("flashlight");                // Create flashlight item
    pin = new Item("pin");                              // Create pin item
    crowbar = new Item("crowbar");                      // Create crowbar item
    rope = new Item("rope");                            // Create rope item
    dagger = new Item("dagger");                        // Create dagger item
    emerald = new Item("emerald");                      // Create emerald item
    rum = new Item("rum");                              // Create rum item
    clothes = new Item("clothes");                      // Create clothes item
    
    diver = new Diver(name, 100, 4);                    // Create diver character
    eel = new Character("eel", 40, 3);                  // Create eel character
    rival = new Character("rival", 100, 5);             // Create rival treasure hunter character
    
    currentLocation = mainDeck;                         // Set current location the main deck
    gameOver = false;                                   // Set gameOver status to false
}

/************************************************************************************************

    Deconstructor frees all the object pointers created in the Game class
    
 ************************************************************************************************/
Game::~Game()
{
    delete surface;
    delete mainDeck;
    delete captainsQuarters;
    delete crewQuarters;
    delete infirmary;
    delete gunDeck;
    delete cargoHold;
    delete brig;
    delete diver;
    delete eel;
    delete rival;
    delete knife;
    delete flashlight;
    delete pin;
    delete crowbar;
    delete rope;
    delete dagger;
    delete emerald;
    delete rum;
    delete clothes;
}

/************************************************************************************************

    setEnvironment() creates the specified links between the spaces of the game to create
    a connected environment
    
 ************************************************************************************************/
void Game::setEnvironment()
{   
    //Surface
    diver->addItem(knife);                                  // Add the knife to the diver's container
    diver->addItem(flashlight);                             // Add the flashlight to the diver's container
    
    // Main Deck
    mainDeck->setTopSpace(surface);                         // Set main deck's top link to the surface
    mainDeck->setLeftSpace(captainsQuarters);               // Set main deck's left linke to the captain's quarters
    mainDeck->setBottomSpace(gunDeck);                      // Set main deck's bottom link to the gun deck
    
    // Captain's Quarters
    captainsQuarters->setRightSpace(mainDeck);              // Set captain's quarters right link to the main deck
    captainsQuarters->setBottomSpace(crewQuarters);         // Set captain's quarters bottom link to the crew quarters
    
    // Crew Quarters
    crewQuarters->setTopSpace(captainsQuarters);            // Set the crew quarters top link to the captain's quarters
    crewQuarters->setLeftSpace(infirmary);                  // Set the crew quarters left link to the infirmary
    crewQuarters->setRightSpace(gunDeck);                   // Set the crew quarters right link to the gun deck
    
    // Infirmary
    infirmary->setRightSpace(crewQuarters);                 // Set the infirmary right link to the crew quarters
    
    // Gun Deck
    gunDeck->setTopSpace(mainDeck);                         // Set the gun deck top link to the main deck
    gunDeck->setLeftSpace(crewQuarters);                    // Set the gun deck left link to the crew quarters
    gunDeck->setBottomSpace(cargoHold);                     // Set the gun deck bottom link to the cargo hold
    gunDeck->addItem(rope);                                 // Add the rope to the gun deck container
    
    // Cargo Hold
    cargoHold->setTopSpace(gunDeck);                        // Set the cargo hold top link to the gun deck
    cargoHold->setLeftSpace(brig);                          // Set the cargo hold left link to the brig
    
    // The Brig
    brig->setRightSpace(cargoHold);                         // Set the brig right space to the cargo hold
}

/************************************************************************************************

    runGame() allows the user to continually move through the game environment and 
    interact with objects until the game is won or the diver is dead.
    
 ************************************************************************************************/
void Game::runGame()
{
    string action;
    string uhoh = "There's nothing in that direction. Choose again.";
    
    do{                                                                                         // Loop
        cout << "You are at the " << currentLocation->getName() << "." << endl;                     // Print current location name
        cout << currentLocation->getDescription() << endl;                                          // Print current location description
        action = menu(1);                                                                           // Print the main menu
    
        if(action == "top"){                                                                        // If the user chooses to go up
            if(currentLocation->getTopSpace() != NULL){                                                 // If top link exists
                useAir(50);                                                                                 // Use 50 psi of air
                currentLocation = currentLocation->getTopSpace();                                           // Change current location
            }
            else{                                                                                       // Else
                cout << uhoh << endl << endl;                                                               // Print error message
            }
        }
        else if(action == "left"){                                                                  // If user chooses to go left
            if(currentLocation->getLeftSpace() != NULL){                                                // If left link exists
                useAir(50);                                                                                 // Use 50 psi of air
                currentLocation = currentLocation->getLeftSpace();                                          // Change current location
            }
            else{                                                                                       // Else
                cout << uhoh << endl << endl;                                                               // Print error message
            }
        }
        else if(action == "right"){                                                                 // If user chooses to go right
            if(currentLocation->getRightSpace() != NULL){                                               // If right link exists
                useAir(50);                                                                                 // Use 50 psi of air
                currentLocation = currentLocation->getRightSpace();                                         // Change current location
            }
            else{                                                                                       // Else
                cout << uhoh << endl << endl;                                                               // Print error message
            }
        }
        else if(action == "bottom"){                                                                // If user chooses to go down
            if(currentLocation->getBottomSpace() != NULL){                                              // If down link exists
                useAir(50);                                                                                 // Use 50 psi of air
                currentLocation = currentLocation->getBottomSpace();                                        // Change current location
            }
            else{                                                                                       // Else
                cout << uhoh << endl << endl;                                                               // Print error message
            }
        }
        else if(action == "explore"){                                                           // If user chooses to explore the space
            action = currentLocation->explore();                                                    // Call current location's explore function
            if(action == "items"){                                                                  // If function returns "items"
                pickupItems();                                                                          // Call function to pick up items in the space
            }
            else if(action == "pin"){                                                               // If function returns "pin"
                currentLocation->addItem(pin);                                                          // Make pin item available in the space
                useAir(20);                                                                             // Use 20 psi of air
                cout << "Explore the space again to collect items." << endl << endl;                    
            }
            else if(action == "bandages"){                                                          // If function returns "bandages"
                recovery(10);                                                                           // Call function to recovery health points
                useAir(10);                                                                              // Use 10 psi of air
            }
            else if(action == "rum"){                                                               // If function returns "rum"
                currentLocation->addItem(rum);                                                          // Make rum item available in the space
                useAir(10);                                                                             // Use 10 psi of air
                cout << "Explore the space again to collect items." << endl << endl;
            }
            else if(action == "eel1"){                                                              // If function returns "eel1"
                battle(diver, eel);                                                                     // Diver battles Eel
                useAir(100);                                                                            // Use 100 psi of air
                if(diver->hasItem(flashlight)){                                                         // If diver has the flashlight
                    cout << "But, not before it knocked the flashlight off your gear rig."                  // Print message
                        << endl << endl;
                    gunDeck->addItem(flashlight);                                                           // Move flashlight to adjacent space
                    diver->removeItem(flashlight);                                                          // Remove flashlight from user container
                }
            }
            else if(action == "eel2"){                                                              // If function returns "eel2"
                battle(diver, eel);                                                                     // Diver battles Eel
                useAir(100);                                                                            // Use 100 psi of air
                if(diver->hasItem(flashlight)){                                                         // If diver has the flashlight
                    cout << "But, not before it knocked the flashlight off your gear rig."                  // Print message
                        << endl << endl;
                    cargoHold->addItem(flashlight);                                                         // Move flashlight to adjacent space
                    diver->removeItem(flashlight);                                                          // Remove flashlight from user container
                }
            }
            else if(action == "eel3"){                                                              // If function returns "eel3"
                battle(diver, eel);                                                                     // Diver battles Eel
                useAir(100);                                                                            // Diver uses 100 psi of air
                if(diver->hasItem(flashlight)){                                                         // If diver has the flashlight
                    cout << "But, not before it knocked the flashlight off your gear rig."                  // Print message
                        << endl << endl;
                    brig->addItem(flashlight);                                                              // Move flashlight to adjacent space
                    diver->removeItem(flashlight);                                                          // Remove flashlight from user container
                }
            }
            else if(action == "dagger"){                                                            // If function returns "dagger"
                currentLocation->addItem(dagger);                                                       // Make the dagger available in the space
                useAir(10);                                                                             // Use 10 psi of air
                cout << "Explore the space again to collect items." << endl << endl;
            }   
            else if(action == "crowbar"){                                                           // If function returns "crowbar"
                currentLocation->addItem(crowbar);                                                      // Make the crowbar available in the space
                useAir(30);                                                                             // Use 30 psi of air
                cout << "Explore the space again to collect items." << endl << endl;
            }
            else if(action == "pry"){                                                               // If function returns "pry"
                getTreasure();                                                                          // Call getTreasure() function
            }
            else if(action == "chest"){                                                             // If function returns "chest"
                currentLocation->addItem(clothes);                                                      // Make the clothes available in the space
                useAir(10);                                                                             // Use 10 psi of air
                cout << "Explore the space again to collect items." << endl << endl;
            }
            else if(action == "clue"){                                                              // If function returns "clue"
                useAir(5);                                                                              // Use 5 psi of air
                solveClues();                                                                           // Call solve clues function
            }
        }
        else if(action == "stats"){                                                             // If function returns "stats"
            viewStats();                                                                            // Call function to view items in the space
        }
        else if(action == "spoilers"){                                                          // If function returns "spoilers"
            currentLocation->spoilers();                                                            // Call function to print current locations hints
            cout << endl;
        }
        
        if(currentLocation == mainDeck && diver->hasItem(emerald)                                  // If diver is on the main deck and has the emeral
           && rival->getStrength() > 0){                                                            // and the rival character is still alive
            cout << "You've made it out of the ship and start heading toward to surface when\n"         // Print message
                 << "a spear shoots right passed you. It seems a rival treasure hunter has\n"
                 << "anchored on the shipwreck in search of the same treasure. Defend your booty!" 
                << endl;
            useAir(300);
            battle(diver, rival);                                                                       // Diver and Rival battle
        }
        
        if(currentLocation == surface){                                                             // If the current location is the surface
            if(diver->hasItem(emerald)){                                                                // And the diver has the emerald
                cout << "Congratulations! Let's hope you don't have the same misfortunes "                  // Print message
                    << "as the previous owners ..." << endl;
            }
            else{                                                                                       // Else
                if(diver->getStrength() > 0){                                                               // If diver is still alive
                    cout << "You've returned without your prize and rival treasure\n"                           // Print message
                     << "hunters are swarming the area. Time to leave ..." << endl;
                }
            }
            cout << currentLocation->getDescription() << " ";
            gameOver = true;                                                                            // Sest gameOve status to true
        }
        else{
            if(diver->getStrength() <= 0){                                                              // If diver has no more health points
                cout << "You've taken too much damage and can't make it back to "                           // Print message
                << "the surface ... GAME OVER" << endl;
                gameOver = true;                                                                            // Set gameOver status to true
            }
            else if(diver->getAir() <= 0 && currentLocation != surface){                                     // If diver ran out of air and s/he is not on the surface
                cout << "You ran out of air ... GAME OVER" << endl;                                         // Print message
                gameOver = true;                                                                            // Set gameOver status to true
            }
            else{                                                                                       // Else
                //do nothing                                                                                // Do nothing
            }
        }
    }while(!gameOver);                                                                          // Loop until game over
    
}

/************************************************************************************************

    viewStats() prints the current items in the user's container and prompts the user
    to remove an item from their container and drop it into the current space's container.
    
 ************************************************************************************************/
void Game::viewStats()
{
    int num = diver->printStats();                                                  // Print the items in the diver's container
    if(num == 0){                                                                       // If the user does enter a valid number  
        cout << endl;                                                                       // Do nothing
    }
    else{                                                                               // Else
        if(num == 1){                                                                       // If diver wants to remove an item
            cout << endl << "Choose an item to remove from your bag:" << endl;                  // Prompt user
            diver->printItems();                                                                // Print list of items
            string strNum;          
            getline(cin, strNum);                                                               // Get user input
            num = inputValInt(strNum);                                                          // Validate
            if(num == -1 || num > diver->getSize()){                                            // If number is invalid
                cout << endl << "ERROR: Invalid input" << endl << endl;                             // Print error message
            }
            else{                                                                               // Else
                Item* currentItem;                              
                currentItem = diver->getItem(num);                                                  // Get the pointer for hte specified item
                currentLocation->addItem(currentItem);                                              // Add the pointer to the current space container
                diver->removeItem(currentItem);                                                     // Remove the pointer from the diver's container
                cout << endl;
            }
        }
        else if(num == 2){                                                                  // If diver does not want to remove an item
            cout << endl;                                                                       // Do nothing
        }
    }
}

/************************************************************************************************

    pickupItems() sets the stage for the diver to pick up items in the current space
    and add them to his/her item container
    
 ************************************************************************************************/
void Game::pickupItems()
{
    int num = currentLocation->printStats();                                                // Print the current list of items in the space
    if(num == 0){                                                                           // If function returns 0
        cout << endl;                                                                           // Do nothing
    }
    else{                                                                                   // Else
        if(diver->getSize() < 5){                                                              // If the diver has less than 5 items in his/her container
            if(num == 1){                                                                           // And the diver chooses to add an item
                cout << endl << "Choose an item to add to your bag:" << endl;                           // Prompt user to choose an item
                currentLocation->printItems();                                                              // Print the list of available items
                string strNum;
                getline(cin, strNum);                                                                       // Get user input
                num = inputValInt(strNum);                                                                  // Validate
                if(num == -1 || num > currentLocation->getSize()){                                          // If input is not valid
                    cout << endl << "ERROR: Invalid input" << endl << endl;                                     // Print error
                }
                else{                                                                                       // Else
                    Item* currentItem;                                                  
                    currentItem = currentLocation->getItem(num);                                                // Get the pointer for hte specified item
                    if(diver->getSize() == 5){                                                                  // If the diver has too many items already
                        cout << endl << "You are carrying the maximum number of items."                             // Print message
                            << endl << endl;
                    }
                    else{                                                                                       // Else
                        diver->addItem(currentItem);                                                                // Add pointer to the diver's container
                        currentLocation->removeItem(currentItem);                                                   // Remove pointer from the space container
                        cout << endl;
                    }
                }
            }
            else if(num == 2){                                                                      // Else
                cout << endl;                                                                           // Do nothing
            }
        }   
        else{                                                                                   // Else
            cout << endl << "You are carrying the maximum number of items." 
                << endl << endl;                                                                    // Print message
        }
    }
}

/************************************************************************************************

    useAir() determines and calulates how much air the diver has consumed in the current conditions
    
 ************************************************************************************************/
void Game::useAir(int n)
{
    if(currentLocation == gunDeck || currentLocation == crewQuarters                // If the diver is in an interior space
    || currentLocation == infirmary || currentLocation == cargoHold
    || currentLocation == brig){
        if(!diver->hasItem(flashlight)){                                                // And the diver does not have the flashlight
            cout << "It's pitch black and you do not have your flashlight.\n"               // Print message
                << "You're using twice as much air finding your way in the dark." 
                << endl << endl;
            diver->setAir(diver->getAir() - (2*n));                                         // Multiple specified air consumption by three and subtract
        }
        else{                                                                           // Else
            diver->setAir(diver->getAir() - n);                                             // Simply subtract the specified air consumption
        }
    }
    else{                                                                           // Else
        diver->setAir(diver->getAir() - n);                                             // Simply subtract the specified air consumption
    }
}

/************************************************************************************************

    recovery() calls the diver to gain back strength points from using bandages
    
 ************************************************************************************************/
void Game::recovery(int d)
{
    diver->setStrength(diver->getStrength() + d);       // Set diver's strength to current strength plus integer passed into function
    if(diver->getStrength() > 100){                     // If new strength is greater than 100
        diver->setStrength(100);                            // Set strength to 100
    }
}

/************************************************************************************************

    battle() calls characters to take turns attacking and defending until one 
    of the characters dies. Then, the function declares the winner of the overall battle.
    
 ************************************************************************************************/
void Game::battle(Character *d, Character *e)
{ 
    do{                                                                                 // Loop
        round(d, e);                                                                        // Call diver to attack enemy
        if(e->getStrength() > 0){                                                           // If the enemy is still alive
            round(e, d);                                                                        // Call enemy to attack the diver
        }
    }while(d->getStrength() > 0 && e->getStrength() > 0);                               // Loop until one of the characters dies
    
    if(d->getStrength() > 0){                                                           // If diver is still alive
        cout << endl;
        if(e == eel){                                                                       // And the enemy is an eel
            cout << "You fought off the eel, who retreated back into the shadows."              // Print message
                 << endl << endl; 
            eel->setStrength(40);                                                               // Reset eel's strength for future encounters
        }
        else if(e == rival){                                                                // Or the enemy is a rival treasure hunter
            cout << "You fought off your rival and escaped with the emerald!"                   // Print message
                 << endl << endl;
            currentLocation = surface;                                                          // Set current location to the surface
        }
    }
    else{                                                                               // Else, if diver is dead
        cout << endl;       
        if(e == eel){                                                                       // And enemy is an eel
            cout << "The eel had the element of surprise and bit a vital artery."               // Print message
                << endl << endl;
        }
        else if(e == rival){                                                                // Or enemy is a rival treasure hunter
            cout << "You were overpowered by your rival, who stole the emerald."                // Print message
                << endl << endl;
            diver->removeItem(emerald);                                                         // Remove the emerald from diver's container
            currentLocation = surface;                                                          // Set current location to the surface
        }
    }
}

/************************************************************************************************

    round() gets the types of the attacker and defender (passed into the function), calls the 
    attack function for the attacker to calculate attack points inflicted on the defender. The 
    defender then takes the attack points and passes them into its defense function to calculate 
    damage and loss of strength points. The function then declares the new strength of the defender.
    
 ************************************************************************************************/
void Game::round(Character *a, Character *d)
{   
    if(a == diver){                                     // If attacker is the diver
        dice = 1;                                           // Use 1 die
        sides = 6;                                          // With 6 sides
        if(diver->hasItem(knife)){                          // If diver has the knife
            dice = 2;                                           // USesr 2 dice
            sides = 6;                                          // With 6 sides each
        }
        if(diver->hasItem(dagger)){                         // If diver has the dagger
            dice = 2;                                           // Use 2 dice
            sides = 9;                                          // With 9 sides each
        }
        if(diver->hasItem(crowbar)){                        // If diver has the crowbar
            dice = 2;                                           // Use 2 dice
            sides = 11;                                         // With 11 sides each
        }
    }
    else if(a == eel){                                  // If attacker is an eel
        dice = 2;                                           // Use 2 dice
        sides = 6;                                          // With 6 sides each
    }
    else if(a == rival){                                // If attacker is a rival treasure hunter
        dice = 2;                                           // Use 2 dice
        sides = 10;                                         // With 10 sides each
    }
    
    int attackPts = a->attack(dice, sides);             // Call attacker to attack
    d->defend(attackPts);                               // Call defender to defend
}

/************************************************************************************************

    getTreasure() evaluates conditions for the diver's available
    actions after to Brig trap has sprung.
    
 ************************************************************************************************/
void Game::getTreasure()
{
    string action;
    
    if(!diver->hasItem(crowbar)){                                                                           // If diver does not have  the crowbar
        cout << "You don't have a tool that can pry up these floor boards.\n"                                   // Print message
             << "Look around the ship again for something that can help you." << endl << endl;
    }
    else{                                                                                                   // Else
        cout << "You pry up the floor boards with your crowbar and discover the emerald!!!\n"                   // Print message
             << "But, your excitement is short lived, as a mechanism seems to have engaged,\n"
             << "closing and locking the Brig door behind you." << endl << endl;
        currentLocation->addItem(emerald);                                                                      // Make emerald available           
        useAir(100);                                                                                            // Diver uses 100 psi of air
        currentLocation->setOpen(false);                                                                        // Shut the Brig door
        do{                                                                                                     // Loop until diver gets out
            action = currentLocation->explore();                                                                    // Call function to get users next move
            if(action == "freak"){                                                                                  // If function return "freak"
                cout << endl << "You're claustrophobic and have a panic attack. You're eventually able to\n"            // Print message
                         << "calm yourself, but not before consuming a considerable amount of air." << endl << endl;
                useAir(300);                                                                                            // Diver uses 300 psi of air
            }
            else if (action == "search"){                                                                           // If function returns "search"
                if(diver->hasItem(pin)){                                                                                // If user has the pin
                    cout << endl << "You scour the Brig door looking for weaknesses and notice a deliberate\n"              // Print message
                     << "pinhole near the lock. A perfect fit for the pin from the Captain's \n"
                     << "Quarters. You insert the pin and the door unlocks." << endl;
                    cout << "Don't forget to pick up the emerald before you head back to the surface!" << endl << endl;
                    currentLocation->setOpen(true);                                                                         // Set Brig open status to true
                    currentLocation->setSolved(true);                                                                       // Set Brig solved status to true
                    currentLocation->setDone(true);                                                                         // Set Brig done status to true
                }
                else if(diver->hasItem(crowbar)){                                                                       // If user has the crowbar
                    cout << endl << "Although it's a solid door, it's been corroded over time. With a little\n"             // Print message
                     << "effort you are able to jimmy the door open with the crowbar." << endl;
                    cout << "Don't forget to pick up the emerald before you head back to the surface!" << endl << endl;
                    useAir(100);                                                                                            // Diver uses 100 psi of air
                    currentLocation->setOpen(true);                                                                         // Set Brig open status to true
                    currentLocation->setSolved(true);                                                                       // Set Brig solved status to true
                    currentLocation->setDone(true);                                                                         // Set Brig done status to true
                }
                else if(diver->hasItem(dagger)){                                                                        // If user has the dagger
                    cout << endl << "Although it's a solid door, it's been corroded over time. With a good\n"               // Print message
                     << "bit of effort you are able to jimmy the door open with the crowbar." << endl;
                    cout << "Don't forget to pick up the emerald before you head back to the surface!" << endl << endl;
                    useAir(200);                                                                                            // Diver uses 200 psi of air
                    currentLocation->setOpen(true);                                                                         // Set Brig open status to true 
                    currentLocation->setSolved(true);                                                                       // Set Brig solved status to true
                    currentLocation->setDone(true);                                                                         // Set Brig done status to true
                }
                else if(diver->hasItem(knife)){                                                                         // If user hsa the knife
                    cout << endl << "Although it's a solid door, it's been corroded over time. With a considerable\n"       // Print message
                     << "amount effort you are able to jimmy the door open with the crowbar." << endl;
                    cout << "Don't forget to pick up the emerald before you head back to the surface!" << endl << endl;
                    useAir(300);                                                                                            // Diver uses 300 psi of air
                    currentLocation->setOpen(true);                                                                         // Set Brig open status to true
                    currentLocation->setSolved(true);                                                                       // Set Brig soled status to true
                    currentLocation->setDone(true);                                                                         // Set Brig done statu to true
                }
                else{                                                                                                   // Else
                    cout << endl << "You do not have any tools that can help you escape from the pirates' trap.\n"          // Print message
                    << "You are wealthy with treasure but, like with all its previous owners, the emerald\n"
                    << "has led you to your demise." << endl << endl;
                    useAir(diver->getAir());                                                                                // Diver uses remaining air
                }
            }
        }while(!currentLocation->getOpen());                                                                    // Loop untl the Brig is open
    }
}

/************************************************************************************************

    solveClues() tracks the clues found in the game to unlock access to the emerald
    
 ************************************************************************************************/
void Game::solveClues()
{
    if(captainsQuarters->getSolved() && crewQuarters->getSolved() && cargoHold->getSolved()){       // If all clues have been found
        cout << "You have collected all the clues to lead you to the emerald!\n"                        // Print message
             << "Think ... where did the Captain and Quarter Master stash it?" << endl << endl; 
        brig->setSolved(true);                                                                          // Set Brig solved status to true
    }
    else{                                                                                           // Else
        brig->setSolved(false);                                                                         // Set Brig solved status to false
    }
}