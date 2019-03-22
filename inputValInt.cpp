/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the definition file for the inputValInt() 
                function. inputValidation() takes strings as its parameters 
                and validates the user input string against the minimum 
                and maximum values possible for that particular input.
****************************************************************************/ 
#include "inputValInt.hpp"

int inputValInt(string strInput)
{   
    bool validNum = false;      // Holds number validity
    bool validInput = false;    // Holds input validity
     
    for(int i = 0; i < strInput.length(); i++){             // Loop through each character in the input string
        if(std::isdigit(strInput[i])){                          // If each character is a digit
            validNum = true;                                        // Valid input
        }
        else{                                                   // Else
            validNum = false;                                       // Invalid input
            return -1;                                               // Return 0 as error
        }
    }
    int intInput = stoi(strInput);                          // Convert user input from string to int
    
    return intInput;
    

    
}