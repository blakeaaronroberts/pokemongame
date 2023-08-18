/*********************************************************************
 ** Program Filename: Program 3 - charmander.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for child Charmander class
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef CHARMANDER_CLASS_H
#define CHARMANDER_CLASS_H

/* CUSTOM LIBRARIES */

#include "pokemon.h"


class Charmander : public Pokemon {

    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Bulbasaur object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Bulbasaur object created.
     *********************************************************************/

    Charmander(
        const std::string &name = "Charmander", 
        const eType &type = fire, 
        const int &health_points = 39,
        const int &max_hp = 39, 
        const int &attack = 52,
        const int &defense = 43,
        const int &speed = 65,
        const std::string &ascii = "charmander.txt");


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor (override)
     ** Description: Destroys Charmander object.
     ** Parameters: none.
     ** Pre-Conditions: Charmander object exists.
     ** Post-Conditions: Charmander object created.
     *********************************************************************/

    virtual ~Charmander() override;


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Print (override)
     ** Description: Prints Charmander stats.
     ** Parameters: none.
     ** Pre-Conditions: Charmander exists.
     ** Post-Conditions: Charmander stats printed.
     *********************************************************************/

    void print() override;


};

#endif