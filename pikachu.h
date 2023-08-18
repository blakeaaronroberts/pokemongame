/*********************************************************************
 ** Program Filename: Program 3 - pikachu.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for child Pikachu class
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef PIKACHU_CLASS_H
#define PIKACHU_CLASS_H

/* CUSTOM LIBRARIES */

#include "pokemon.h"


class Pikachu : public Pokemon {

    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Pikachu object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Pikachu object created.
     *********************************************************************/

    Pikachu(
        const std::string &name = "Pikachu", 
        const eType &type = electric, 
        const int &health_points = 35,
        const int &max_hp = 35, 
        const int &attack = 55,
        const int &defense = 50,
        const int &speed = 90,
        const std::string &ascii = "pikachu.txt");


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor (override)
     ** Description: Destroys Pikachu object.
     ** Parameters: none.
     ** Pre-Conditions: Pikachu object exists.
     ** Post-Conditions: Pikachu object created.
     *********************************************************************/

    virtual ~Pikachu() override;


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Print (override)
     ** Description: Prints Pikachu stats.
     ** Parameters: none.
     ** Pre-Conditions: Pikachu exists.
     ** Post-Conditions: Pikachu stats printed.
     *********************************************************************/

    void print() override;


};

#endif