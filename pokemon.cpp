/*********************************************************************
 ** Program Filename: Program 3 - pokemon.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Implementation for for abstract Pokemon class.
 ** Input: None.
 ** Output: Pokemon objects, member variables, and console output.
 *********************************************************************/

/* STANDARD LIBRARIES */

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <cmath>


/* CUSTOM LIBRARIES */

#include "utilities.h"
#include "pokemon.h"


/* CONSTRUCTORS */

Pokemon::Pokemon(
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
        : name{name}, 
        type{type}, 
        health_points{health_points},
        max_hp{max_hp}, 
        attack{attack}, 
        defense{defense}, 
        speed{speed},
        ascii{ascii} {
    //print_str("Pokemon Constructed\n");
}

/* DESTRUCTORS */

Pokemon::~Pokemon() {
    /* default constructor */
    //print_str("Pokemon Destructed\n");
}

/* ACCESSORS */
/* return member variable values */

std::string Pokemon::get_name() const {
    return this->name;
}


Pokemon::eType Pokemon::get_type() const {
    return this->type;
}


int Pokemon::get_health_points() const {
    return this->health_points;
}

int Pokemon::get_max_hp() const {
    return this->max_hp;
}

int Pokemon::get_attack() const {
    return this->attack;
}


int Pokemon::get_defense() const {
    return this->defense;
}


int Pokemon::get_speed() const {
    return this->speed;
}


std::string Pokemon::get_ascii() const {
    return this->ascii;
}

/* MUTATORS */
/* set member variable values */

void Pokemon::set_name(const std::string &name) {
    this->name = name;
}


void Pokemon::set_nickname(const int &i) {
    /* prompt user */
    std::string input;
    typewriter("Do you want to give "); 
    typewriter(this->get_name()); 
    typewriter(" a nickname?");
    print_str("\n1. Yes\n2. No\n");
    input_to_str(input);
    int_check(input, 1, 2);
    if(stoi(input) == 1) {
        /* set name */
        std::string nickname;
        print_str("Enter a nickname: ");
        input_to_str(nickname);
        str_check(nickname, 10);
        typewriter(this->get_name()); 
        typewriter("'s name was changed to ");
        this->set_name(nickname);
        typewriter(this->get_name());
        print_str(".\n");
    }
}


void Pokemon::set_type(const eType &type) {
    this->type = type;
}


void Pokemon::set_health_points(const int &health_points) {
    this->health_points = health_points;
}


void Pokemon::set_attack(const int &attack) {
    this->attack = attack;
}


void Pokemon::set_defense(const int &defense) {
    this->defense = defense;
}


void Pokemon::set_speed(const int &speed) {
    this->speed = speed;
}


void Pokemon::set_ascii(const std::string &ascii) {
    this->ascii = ascii;
}


/* OTHER METHODS */

int Pokemon::damage(Pokemon* opp_poke) {
    /* calulate damage */
    double rando = ((rand() % (115 + 1 - 85) + 85) / 100.0);
    return ceil(15 * this->get_attack() / opp_poke->get_defense() 
        * this->type_effectiveness(opp_poke) * rando);
}

double Pokemon::type_effectiveness(Pokemon* opp_poke) {
    /* compare types for effectiveness */
    if((this->type == grass && opp_poke->type == water)
        || (this->type == water && opp_poke->type == fire)
        || (this->type == fire && opp_poke->type == grass)
        || (this->type == electric && opp_poke->type == water)) {
        return 2.0;
    } else if ((this->type == grass 
        && (opp_poke->type == fire || opp_poke->type == grass))
        || (this->type == water 
        && (opp_poke->type == grass || opp_poke->type == water))
        || (this->type == fire 
        && (opp_poke->type == water || opp_poke->type == fire))
        || (this->type == electric 
        && (opp_poke->type == grass || opp_poke->type == electric))) {
        return 0.5;
    } else {
        return 1.0;
    }
}

std::string Pokemon::translate_type() {
    /* return string with type name */
    switch(this->type) {
        case none:
            return "None";
        case fire:
            return "Fire";
        case grass:
            return "Grass";
        case water:
            return "Water";
        case electric:
            return "Electric";
        default:
            break;
    }
    return "ERROR";
}


void Pokemon::print() {
    /* template for virtual prints, not actually used */
    std::cout 
    << std::setw(10) << std::right << "Name: " 
    << std::setw(10) << std::left << this->get_name() << "\n"
    << std::setw(10) << std::right << "Type: " 
    << std::setw(8) << std::left << this->translate_type() 
    << "\n" << std::setw(10) << std::right << "Stats:\n"
    << std::setw(10) << std::right << "HP: " 
    << std::setw(3) << std::left << this->get_health_points()
    << std::setw(10) << std::right << "ATT: " 
    << std::setw(3) << std::left << this->get_attack() << "\n"
    << std::setw(10) << std::right << "DEF: " 
    << std::setw(3) << std::left << this->get_defense()
    << std::setw(10) << std::right << "SPD: " 
    << std::setw(3) << std::left << this->get_speed() << "\n";
}