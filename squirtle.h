/*********************************************************************
 ** Program Filename: Program 3 - squirtle.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for child Squirtle class
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef SQUIRTLE_CLASS_H
#define SQUIRTLE_CLASS_H

/* CUSTOM LIBRARIES */

#include "pokemon.h"


class Squirtle : public Pokemon {

    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Squirtle object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Squirtle object created.
     *********************************************************************/

    Squirtle(
        const std::string &name = "Squirtle",
        const eType &type = water,
        const int &health_points = 44,
        const int &max_hp = 44,
        const int &attack = 48,
        const int &defense = 65,
        const int &speed = 43,
        const std::string &ascii = "squirtle.txt");


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Squirtle object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Squirtle object created.
     *********************************************************************/

    virtual ~Squirtle() override;


    /* OPERATORS */


    /* ACCESSORS */


    /* MUTATORS */


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Print (override)
     ** Description: Prints Squirtle stats.
     ** Parameters: none.
     ** Pre-Conditions: Squirtle exists.
     ** Post-Conditions: Squirtle stats printed.
     *********************************************************************/

    void print() override;


};

#endif