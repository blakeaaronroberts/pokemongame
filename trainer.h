/*********************************************************************
 ** Program Filename: Program 3 - trainer.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for Trainer class.
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef TRAINER_CLASS_H
#define TRAINER_CLASS_H

/* STANDARD LIBRARIES */

#include <string>


/* CUSTOM LIBRARIES */

#include "trainer.h"
#include "pokemon.h"


class Trainer {

    private:

        std::string name;
        Pokemon* team[3];


    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Trainer object with default name value.
     ** Parameters: name, team[]
     ** Pre-Conditions: none.
     ** Post-Conditions: Trainer object created.
     *********************************************************************/

    Trainer();


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor
     ** Description: Destroys Trainer object.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: Trainer object destroyed.
     *********************************************************************/

    ~Trainer();


    /* ACCESSORS */

    /*********************************************************************
     ** Function: Get Name
     ** Description: Returns name value.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: name returned.
     *********************************************************************/

    std::string get_name();


    /*********************************************************************
     ** Function: Get Pokemon
     ** Description: Returns Pokemon pointer.
     ** Parameters: i (index)
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: Pokemon pointer returned.
     *********************************************************************/

    Pokemon* get_pokemon(const int &);


    /* MUTATORS */

    /*********************************************************************
     ** Function: Set Name
     ** Description: Sets name value.
     ** Parameters: name
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: name set.
     *********************************************************************/

    void set_name(const std::string &);


    /*********************************************************************
     ** Function: Set Pokemon
     ** Description: Sets pokemon object.
     ** Parameters: i (index), pokemon
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: name set.
     *********************************************************************/

    void set_pokemon(const int &, const int &);


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Pokemon Fainted
     ** Description: Checks if pokemon has zero health_points
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: Returns true if fainted, false otherwise.
     *********************************************************************/

    bool pokemon_fainted();


    /*********************************************************************
     ** Function: Attack Effectiveness
     ** Description: Returns string with attack effectiveness statement.
     ** Parameters: pokemon (opponent)
     ** Pre-Conditions: Pokemon objects exist.
     ** Post-Conditions: Returns string.
     *********************************************************************/

    std::string attack_effectiveness(Pokemon*);


    /*********************************************************************
     ** Function: Attack Report
     ** Description: Alters last_move string with attack report.
     ** Parameters: pokemmon (opponent), damage, last_move
     ** Pre-Conditions: Attack function called.
     ** Post-Conditions: Alters last_move string with attack report.
     *********************************************************************/

    void attack_report(Pokemon*, const int &, std::string &);


    /*********************************************************************
     ** Function: Attack
     ** Description: Attacks opponent Pokemon.
     ** Parameters: opp_poke, last_move
     ** Pre-Conditions: Is Pokemons turn.
     ** Post-Conditions: remove damage from health_points until they reach zero.
     *********************************************************************/

    void attack(Pokemon*, std::string &);

    /*********************************************************************
     ** Function: Heal Report
     ** Description: Alters last_move string with heal report.
     ** Parameters: pokemmon (opponent), damage, last_move
     ** Pre-Conditions: Heal function called.
     ** Post-Conditions: Alters last_move string with heal report.
     *********************************************************************/

    void heal_report(const int &, std::string &);


    /*********************************************************************
     ** Function: Heal
     ** Description: Heals Pokemon in attack position.
     ** Parameters: last_move
     ** Pre-Conditions: Pokemon object exists. 
     ** Post-Conditions: Increase health_points by 1-15 until they reach max_hp.
     *********************************************************************/

    void heal(std::string &);


    /*********************************************************************
     ** Function: Swap Report
     ** Description: Alters last_move string with swap report.
     ** Parameters: pokemmon (opponent), damage, last_move
     ** Pre-Conditions: Swap function called.
     ** Post-Conditions: Alters last_move string with swap report.
     *********************************************************************/

    void swap_report(std::string &);


    /*********************************************************************
     ** Function: Swap Check
     ** Description: Verify pokemon has not fainted before allowing swap.
     ** Parameters: input
     ** Pre-Conditions: User input.
     ** Post-Conditions: Swap is allowed.
     *********************************************************************/

    void swap_check(std::string &);


    /*********************************************************************
     ** Function: Opponent Swap
     ** Description: Swap with Pokemon that has highest health_points value.
     ** Parameters: last_move
     ** Pre-Conditions: Opponent Pokemon faints.
     ** Post-Conditions: Opponent swaps Pokemon.
     *********************************************************************/

    void opponent_swap(std::string &);


    /*********************************************************************
     ** Function: Swap Display.
     ** Description: Print prompts for user swap.
     ** Parameters: input
     ** Pre-Conditions: User selects swap.
     ** Post-Conditions: Swap is allowed.
     *********************************************************************/

    void swap_display(std::string &);


    /*********************************************************************
     ** Function: Swap
     ** Description: Performs swap.
     ** Parameters: last_move
     ** Pre-Conditions: User selects Pokemon to swap.
     ** Post-Conditions: Pokemon is swapped.
     *********************************************************************/

    void swap(std::string &);


    /*********************************************************************
     ** Function: Print Team
     ** Description: Prints users entire team.
     ** Parameters: none.
     ** Pre-Conditions: team[] exists and is populated.
     ** Post-Conditions: Entire team array is printed.
     *********************************************************************/

    void print_team();


    /*********************************************************************
     ** Function: Print Team
     ** Description: Prints opponents entire team.
     ** Parameters: none.
     ** Pre-Conditions: team[] exists and is populated.
     ** Post-Conditions: Entire team array is printed.
     *********************************************************************/

    void print_opponent_team();


    /*********************************************************************
     ** Function: Is Winner
     ** Description: Checks if the user won.
     ** Parameters: none.
     ** Pre-Conditions: game_over() becomes true.
     ** Post-Conditions: If user won, returns true. Returns false otherwise.
     *********************************************************************/

    bool is_winner();


};

#endif