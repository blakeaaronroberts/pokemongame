/*********************************************************************
 ** Program Filename: Program 3 - trainer.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Implementation file for Trainer class.
 ** Input: Calls from Arena class.
 ** Output: Member variables, console output.
 *********************************************************************/

/* STANDARD LIBRARIES */

#include <iostream>
#include <string>
#include <utility>
#include <cmath>


/* CUSTOM LIBRARIES */

#include "utilities.h"
#include "arena.h"
#include "trainer.h"
#include "pokemon.h"
#include "bulbasaur.h"
#include "charmander.h"
#include "squirtle.h"
#include "pikachu.h"


/* CONSTRUCTORS */

Trainer::Trainer() {
    /* default contructor */
    name = "Gary";
    //print_str("Trainer Constructor Called\n");
}


/* DESTRUCTORS */

Trainer::~Trainer() {
    /* default destructor */
    /* loops through team array, deleting pointers */
    for(int i = 0; i < 3; i++) {
        delete team[i];
    }
    
}


/* ACCESSORS */
/* return member variable values */

std::string Trainer::get_name() {
    return this->name;
}


Pokemon* Trainer::get_pokemon(const int &i) {
    return this->team[i];
}


/* MUTATORS */
/* set member variable values */

void Trainer::set_name(const std::string &name) {
    this->name = name;
}


void Trainer::set_pokemon(const int &i, const int &pokemon) {
    /* set team[i] to pokemon index */
    switch(pokemon) {
        case 1:
            this->team[i] = new Bulbasaur();
            break;
        case 2:
            this->team[i] = new Charmander();
            break;
        case 3:
            this->team[i] = new Squirtle();
            break;
        case 4:
            this->team[i] = new Pikachu();
            break;
    }
}


/* OTHER METHODS */

bool Trainer::pokemon_fainted() {
    /* check if pokemon health_points are less than or equal to zero */
    if(this->team[0]->get_health_points() <= 0) {
        return true;
    }
    return false;
}


std::string Trainer::attack_effectiveness(Pokemon* opp_poke) {
    /* return string with effectiveness statement */
    if(this->get_pokemon(0)->type_effectiveness(opp_poke) == .5) {
        return "It wasn't very effective...";
    } else if (this->get_pokemon(0)->type_effectiveness(opp_poke) == 1) {
        return "It was moderately effective.";
    } else if (this->get_pokemon(0)->type_effectiveness(opp_poke) == 2) {
        return "It was very effective!";
    }
    return "";
}


void Trainer::attack_report(
    /* construct string with attack report */
    Pokemon* opp_poke, 
    const int &damage, 
    std::string &last_move) {
        last_move = this->team[0]->get_name();
        last_move.append(" attacked "); 
        last_move.append(opp_poke->get_name()); 
        last_move.append(" for ");
        last_move.append(std::to_string(damage));
        last_move.append(" damage!\n");
        last_move.append(this->attack_effectiveness(opp_poke));
        last_move.append("\n");
        if(opp_poke->get_health_points() <= 0) {
            last_move.append(opp_poke->get_name()); 
            last_move.append(" fainted!\n");
        }
}


void Trainer::attack(Pokemon* opp_poke, std::string &last_move) {
    /* remove damage from opponent health_points until they reach zero */
    int damage = this->get_pokemon(0)->damage(opp_poke);
    if((opp_poke->get_health_points() - damage) <= 0) {
            opp_poke->set_health_points(0);
        } else {
            opp_poke->set_health_points(opp_poke->get_health_points() - damage);
        }
    this->attack_report(opp_poke, damage, last_move);
}


void Trainer::heal_report(const int &heal, std::string &last_move) {
    /* construct string with heal report */
    last_move = this->get_name();
    last_move.append(" healed "); 
    last_move.append(this->team[0]->get_name()); 
    last_move.append(" for ");
    last_move.append(std::to_string(heal));
    last_move.append(" health points!\n");
}


void Trainer::heal(std::string &last_move) {
    /* increase health_points by 1-15 until they reach max_hp */
    int heal = rand() % 15 + 1;
    if(this->team[0]->get_health_points() 
        + heal >= this->team[0]->get_max_hp()) {
            heal = this->team[0]->get_max_hp() 
            - this->team[0]->get_health_points();
        }
        this->team[0]->set_health_points(
            this->team[0]->get_health_points() + heal);
    this->heal_report(heal, last_move);
}


void Trainer::swap_report(std::string &last_move) {
    /* construct string with swap report */
    last_move = this->get_name();
    last_move.append(" took out ");
    last_move.append(this->team[0]->get_name());
    last_move.append("!\n");
}


void Trainer::swap_check(std::string &input) {
    /* verify pokemon has not fainted before allowing swap */
    while (this->team[stoi(input) - 1]->get_health_points() == 0) {
        typewriter(this->team[0]->get_name());
        typewriter(" has fainted.\nPlease select another Pokemon.\n");
        input_to_str(input);
        int_check(input, 1, 3);
    }

}


void Trainer::opponent_swap(std::string &last_move) {
    /* swap with pokemon that has highest health_points value */
    int max = 0;
    int j;
    for(int i = 2; i >= 0; i--) {
        if (this->team[i]->get_health_points() > max) {
            max = this->team[i]->get_health_points();
            j = i;
        }
    }
    Pokemon* temp = this->team[j];
    this->team[j] = this->team[0];
    this->team[0] = temp;
    this->swap_report(last_move);
}


void Trainer::swap_display(std::string &input) {
    /* print user swap prompts */
    system("clear");
    this->print_team();
    typewriter("Which pokemon would you like to swap in for ");
    typewriter(this->team[0]->get_name());
    typewriter("?\n");
    input_to_str(input);
    int_check(input, 1, 3);
    swap_check(input);
    typewriter("Ok, ");
    typewriter(this->team[0]->get_name());
    typewriter(". ");
    sleep(1000); 
    typewriter("You've had enough.\n");
}


void Trainer::swap(std::string &last_move) {
    /* perform swap */
    std::string input;
    this->swap_display(input);
    Pokemon* temp = this->team[std::stoi(input) - 1];
    this->team[std::stoi(input) - 1] = this->team[0];
    this->team[0] = temp;
    this->swap_report(last_move);
}


void Trainer::print_team() {
    /* print users entire team */
    print_str(this->get_name());
    print_str("'s Team:\n");
    for(int i = 0; i < 3; i++) {
        print_str("#");
        print_int(i + 1);
        print_str("\n___________________\n");
        this->team[i]->print();
        print_str("___________________\n");
    }
}


void Trainer::print_opponent_team() {
    /* print opponents entire team */
    for(int i = 2; i >= 0; i--) {
        //print_str("#");
        //print_int(i + 1);
        print_str("___________________\n");
        this->team[i]->print();
        print_str("___________________\n\n");
    }
    print_str(this->get_name());
    print_str("'s Team:\n");
}


bool Trainer::is_winner() {
    /* check if the users pokemon have all fainted, return true if so */
    if (this->get_pokemon(0)->get_health_points() > 0
        || this->get_pokemon(1)->get_health_points() > 0
        || this->get_pokemon(2)->get_health_points() > 0) {
            return true;
        }
    return false;
}