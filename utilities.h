/*********************************************************************
 ** Program Filename: Program 3 - utlities.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for global utility functions
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#include <string>

#ifndef UTILITIES_H
#define UTILITIES_H

/*********************************************************************
 ** Function: Print Int
 ** Description: Prints an integer.
 ** Parameters: intgr
 ** Pre-Conditions: none.
 ** Post-Conditions: Prints integer.
 *********************************************************************/

void print_int(const int &);


/*********************************************************************
 ** Function: Print Char
 ** Description: Prints a character.
 ** Parameters: chr
 ** Pre-Conditions: none.
 ** Post-Conditions: Prints char.
 *********************************************************************/

void print_chr(const char &);


/*********************************************************************
 ** Function: Print String
 ** Description: Prints string.
 ** Parameters: string
 ** Pre-Conditions: none.
 ** Post-Conditions: Prints string.
 *********************************************************************/

void print_str(const std::string &);


/*********************************************************************
 ** Function: Input to String
 ** Description: Takes input to a string.
 ** Parameters: input
 ** Pre-Conditions: none.
 ** Post-Conditions: input set to Input.
 *********************************************************************/

void input_to_str(std::string &);


/*********************************************************************
 ** Function: Sleep
 ** Description: Pauses program execution for specified milliseconds.
 ** Parameters: milliseconds
 ** Pre-Conditions: none.
 ** Post-Conditions: Program paused.
 *********************************************************************/

void sleep(const int &);


/*********************************************************************
 ** Function: Typewriter
 ** Description: Loop string, printing chars with randomized delay.
 ** Parameters: string
 ** Pre-Conditions: none.
 ** Post-Conditions: string printed.
 *********************************************************************/

void typewriter(const std::string &);


/*********************************************************************
 ** Function: Valid Int
 ** Description: Checks if string is integer in bounds
 ** Parameters: input, lower_bound, upper_bound
 ** Pre-Conditions: none.
 ** Post-Conditions: Return true if valid, false otherwise.
 *********************************************************************/

bool valid_int(const std::string &, const int &, const int &);


/*********************************************************************
 ** Function: Int Check
 ** Description: Keeps prompting user until input is valid.
 ** Parameters: input, lower_bound, upper_bound
 ** Pre-Conditions: input string populated.
 ** Post-Conditions: input defined.
 *********************************************************************/

void int_check(std::string &, const int &, const int &);


/*********************************************************************
 ** Function: Valid String
 ** Description: Checks if input string is under speficied length.
 ** Parameters: input, length
 ** Pre-Conditions: string populated.
 ** Post-Conditions: returns true if valid length, false otherwise.
 *********************************************************************/

bool valid_str(const std::string &, const unsigned int &);


/*********************************************************************
 ** Function: String Check
 ** Description: Prompts user until input string is valid length.
 ** Parameters: input, length
 ** Pre-Conditions: input string populated.
 ** Post-Conditions: 
 *********************************************************************/

void str_check(std::string &, const unsigned int &);


/*********************************************************************
 ** Function: Print ASCII Art
 ** Description: Prints ascii art from file.
 ** Parameters: filename
 ** Pre-Conditions: File exists in working directory.
 ** Post-Conditions: File is printed to console. 
 *********************************************************************/

void print_ascii_art(const std::string &);


#endif