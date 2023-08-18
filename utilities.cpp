/*********************************************************************
 ** Program Filename: Program 3 - utilities.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Implementation file for gloabal utility functions
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "utilities.h"

void print_int(const int &intgr) {
    /* print int */
    std::cout << intgr;
}

void print_chr(const char &chr) {
    /* print char */
    std::cout << chr;
}

void print_str(const std::string &string) {
    /* print string */
    std::cout << string;
}

void input_to_str(std::string &input) {
    /* input to a string */
    std::cin >> input;
}

void sleep(const int &milliseconds) {
    /* flush buffer, then sleep for specified milliseconds */
    std::cout << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void typewriter(const std::string &string) {
    /* loop through string, printing chars with randomized delay */
    for(const char i : string) {
        print_chr(i);
        sleep(25 + rand() % 76);
    }
}

bool valid_int(
    const std::string &input, 
    const int &lower_bound, 
    const int &upper_bound){
    /* verify input is a number */
    for(unsigned int i = 0; i < input.length(); i++){
        if(!isdigit(input[i])){
            return false;
        }
    }
    /* verify number is in range */
    if(stoi(input) < lower_bound || stoi(input) > upper_bound){
        return false;
    }
    return true;
}

void int_check(
    std::string &input, 
    const int &lower_bound, 
    const int &upper_bound) {
    while(!valid_int(input, lower_bound, upper_bound)) {
        /* prompt user until input is valid */
        print_str("Enter a number between "); 
        print_int(lower_bound);
        print_str(" and ");
        print_int(upper_bound);
        print_str(": ");
        input_to_str(input);
    }
}

bool valid_str(const std::string &input, const unsigned int &length) {
    /* make sure string is of specified length or less */
    if(input.length() > length || input.length() < 1) {
        return false; // if string is too long
    }
    return true; // otherwise
}

void str_check(std::string &input, const unsigned int &length) {
    /* continually prompt user til input is valid */
    while(!valid_str(input, length)){
        print_str("Must be between 1 and ");
        print_int(length);
        print_str("characters long.\nTry again: ");
        std::cin >> input;
    }
}


void print_ascii_art(const std::string &filename) {
    /* clear screen */
    system("clear");
    /* open filestream */
    std::ifstream file;
    file.open(filename);
    std::string temp_string;
    /* print each line of file */ 
    if(!file.eof()) {
        while(file.good()) {
            sleep(50);
            getline(file, temp_string);
            print_str(temp_string + "\n");
        }
    } else {
        print_str("POKEMON\n");
    }
    /* close filestream */
    file.close();
}