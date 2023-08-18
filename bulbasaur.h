/*********************************************************************
 ** Program Filename: Program 3 - bulbasaur.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for child Bulbasaur class
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef BULBASAUR_CLASS_H
#define BULBASAUR_CLASS_H

/* CUSTOM LIBRARIES */

#include <string>


/* CUSTOM LIBRARIES */

#include "pokemon.h"


class Bulbasaur : public Pokemon {

    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Bulbasaur object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Bulbasaur object created.
     *********************************************************************/

    Bulbasaur(
        const std::string &name = "Bulbasaur", 
        const eType &type = grass, 
        const int &health_points = 45, 
        const int &max_hp = 45,
        const int &attack = 49,
        const int &defense = 49,
        const int &speed = 45,
        const std::string &ascii = "bulbasaur.txt");


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor (override)
     ** Description: Destroys Bulbasaur object.
     ** Parameters: none.
     ** Pre-Conditions: Bulbasaur object exists.
     ** Post-Conditions: Bulbasaur object created.
     *********************************************************************/

    virtual ~Bulbasaur() override;


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Print (override)
     ** Description: Prints Bulbasaur stats.
     ** Parameters: none.
     ** Pre-Conditions: Bulbasaur exists.
     ** Post-Conditions: Bulbasaur stats printed.
     *********************************************************************/

    void print() override;


};

#endif