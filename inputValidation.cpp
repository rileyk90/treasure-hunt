/***************************************************************************** 
** Author: Kraft, Riley
** Date: 12/05/2017
** Description: This is the definition file for the inputValidation() 
                function. inputValidation() takes strings as its parameters 
                and validates the user input string against the minimum 
                and maximum values possible for that particular input.
****************************************************************************/ 
#include "inputValidation.hpp"

int inputValidation(string strMin, string strMax, string strInput)
{
    bool validNum = false;      // Holds number validity
    bool validInput = false;    // Holds input validity
     
    if(strInput.length() <= strMax.length()){               // If input is less than or equal to the max length
        for(int i = 0; i < (int)strInput.length(); i++){             // Loop through each character in the input string
            if(std::isdigit(strInput[i])){                          // If each character is a digit
                validNum = true;                                        // Valid input
            }
            else{                                                   // Else
                validNum = false;                                       // Invalid input
                return 0;                                               // Return 0 as error
            }
        }
    }
    else{                                                   // Else
        return 0;                                               // Return 0 as error
    }
    
    int intMin = stoi(strMin);                              // Convert minimum possible value from string to integer
    int intMax = stoi(strMax);                              // Convert maximum possible value from string to integer
    int intInput = stoi(strInput);                          // Convert user input from string to int
    
    if(intInput >= intMin && intInput <= intMax){           // If that digit is between the min and max
        validInput = true;                                      // If all tests are true, then the input is valid
        return intInput;                                        // Return user's input value as an integer
    }                                                           
    else{                                                   // Else
        return 0;                                               // Return 0 as error
    }
    
}
