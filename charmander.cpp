/*********************************************************************
 ** Program Filename: Program 3 - charmander.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Implementation for child Charmander class
 ** Input: None.
 ** Output: Charmander objects, and console output. 
 *********************************************************************/

/* STANDARD LIBRARIES */

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>


/* CUSTOM LIBRARIES */

#include "pokemon.h"
#include "charmander.h"


/* CONSTRUCTORS */

Charmander::Charmander(
    /* default constructor */
    /* default values defined in .h */
    const std::string &name, 
    const Pokemon::eType &type,
    const int &health_points,
    const int &max_hp, 
    const int &attack, 
    const int &defense, 
    const int &speed,
    const std::string &ascii)
    : Pokemon(
        name, 
        type, 
        health_points,
        max_hp, 
        attack, 
        defense, 
        speed, 
        ascii) {
        //print_str("Charmander Constructed\n");
    }


/* DESTRUCTORS */

Charmander::~Charmander() {
    /* default constructor */
    //print_str("Charmander Destructed\n");
}


/* OTHER METHODS */

void Charmander::print() {
    /* print charmander stats */
    std::cout 
    << std::setw(7) << std::right << "Name: " 
    << std::setw(9) << std::left << this->get_name() << "\n"
    << std::setw(7) << std::right << "Type: " << "\033[0;31m" 
    << std::setw(9) << std::left << this->translate_type() 
    << "\033[0;m\n" << std::setw(7) << std::right << "Stats:\n"
    << std::setw(7) << std::right << "HP: " 
    << std::setw(3) << std::left << this->get_health_points()
    << std::setw(7) << std::right << "ATT: " 
    << std::setw(3) << std::left << this->get_attack() << "\n"
    << std::setw(7) << std::right << "DEF: " 
    << std::setw(3) << std::left << this->get_defense()
    << std::setw(7) << std::right << "SPD: " 
    << std::setw(3) << std::left << this->get_speed() << "\n";
}

