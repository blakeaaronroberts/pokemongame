/*********************************************************************
 ** Program Filename: Program 3 - arena.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Header file for Arena class.
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef ARENA_CLASS_H
#define ARENA_CLASS_H

/* STANDARD LIBRARIES */

#include <iostream>
#include <fstream>
#include <string>


/* CUSTOM LIBRARIES */

#include "utilities.h"
#include "trainer.h"
#include "pokemon.h"


class Arena {

    private:
        Trainer trainer[2];
        Pokemon* roster[4];
        std::string last_move = ""; 
        std::string effectiveness = "";


    public:

    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Arena object.
     ** Parameters: none
     ** Pre-Conditions: none.
     ** Post-Conditions: Arena object created.
     *********************************************************************/

    Arena();


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor
     ** Description: Destroys Arena object.
     ** Parameters: none.
     ** Pre-Conditions: Arena object exists.
     ** Post-Conditions: Arena object destroyed.
     *********************************************************************/

    ~Arena();


    /* ACCESSORS */

    /*********************************************************************
     ** Function: get Trainer
     ** Description: Returns trainer.
     ** Parameters: i (index)
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: Trainer object returned.
     *********************************************************************/

    Trainer get_trainer(const int &);


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Open Game
     ** Description: Display opening sequence of game.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: User name is set.
     *********************************************************************/

    void open_game();


    /*********************************************************************
     ** Function: Set Opponent Team
     ** Description: Sets opponents team to a random selection of Pokemon.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: team[] is set.
     *********************************************************************/

    void set_opponent_team();


    /*********************************************************************
     ** Function: Set User Team
     ** Description: Sets users team to all Pikachus for debugging.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: User team[] set to all Pikachu objects.
     *********************************************************************/

    void set_user_team();


    /*********************************************************************
     ** Function: Preview
     ** Description: Displays ASCII art and Pokemon stats.
     ** Parameters: i (index)
     ** Pre-Conditions: roster[] exists and is populated.
     ** Post-Conditions: User is prompted to select Pokemon.
     *********************************************************************/

    void preview(const int &);


    /*********************************************************************
     ** Function: Select Pokemon
     ** Description: Takes user input for pokemon selection.
     ** Parameters: pokemon, input
     ** Pre-Conditions: Pokemon is previewed.
     ** Post-Conditions: Pokemon is added to team, or not.
     *********************************************************************/

    void select_pokemon(std::string &, std::string&);


    /*********************************************************************
     ** Function: Selection Menu
     ** Description: Logic for previewing and selecting Pokemon.
     ** Parameters: none.
     ** Pre-Conditions: choose_team()
     ** Post-Conditions: User team[] is set.
     *********************************************************************/

    void selection_menu();


    /*********************************************************************
     ** Function: Print List of Pokemon
     ** Description: Prints roster[] names.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: roster[] names are printed.
     *********************************************************************/

    void print_list_pokemon() const;


    /*********************************************************************
     ** Function: Choose Team
     ** Description: Welcome message and selection menu.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: selection_menu()
     *********************************************************************/

    void choose_team();


    /*********************************************************************
     ** Function: Battle Display Opponent
     ** Description: Displays opponent team in battle formation.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: opponent team is printed.
     *********************************************************************/

    void battle_display_opponent();


    /*********************************************************************
     ** Function: Battle Display User
     ** Description: Displays users team in battle formation.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Users team is printed.
     *********************************************************************/

    void battle_display_user();


    /*********************************************************************
     ** Function: Print Battle Menu
     ** Description: Prints battle menu
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Battle menu printed.
     *********************************************************************/

    void print_battle_menu();


    /*********************************************************************
     ** Function: Game Over
     ** Description: Checks if either trainers pokemon are all fainted.
     ** Parameters: none.
     ** Pre-Conditions: Trainer objects exists with populated team[].
     ** Post-Conditions: Returns true if game is over, false otherwise.
     *********************************************************************/

    bool game_over();


    /*********************************************************************
     ** Function: User Pokemon is Faster
     ** Description: Checks if users attack Pokemon is faster
     ** Parameters: none.
     ** Pre-Conditions: Trainer objects exist with populated team[].
     ** Post-Conditions: Return true if user Pokemon is faster, false otherwise.
     *********************************************************************/

    bool user_pokemon_is_faster();


    /*********************************************************************
     ** Function: Opponent Move
     ** Description: Makes move decisions based on odds.
     ** Parameters: n (health result)
     ** Pre-Conditions: opponent_turn()
     ** Post-Conditions: Opponent makes move.
     *********************************************************************/

    void opponent_move(const int &);


    /*********************************************************************
     ** Function: Opponent Turn
     ** Description: Takes a turn based on health, send health to move.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: Opponent takes turn.
     *********************************************************************/

    void opponent_turn();


    /*********************************************************************
     ** Function: User Turn
     ** Description: Executes a user turn.
     ** Parameters: none.
     ** Pre-Conditions: Trainer object exists.
     ** Post-Conditions: User executes turn.
     *********************************************************************/

    void user_turn();


    /*********************************************************************
     ** Function: Prepare Arena
     ** Description: Prints arena each turn for battle.
     ** Parameters: none.
     ** Pre-Conditions: Battle in progress.
     ** Post-Conditions: Arena printed.
     *********************************************************************/

    void prepare_arena();


    /*********************************************************************
     ** Function: User First
     ** Description: Plays round with user going first. 
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Round is executed.
     *********************************************************************/

    void user_first();


    /*********************************************************************
     ** Function: Computer First
     ** Description: Plays round with computer going first. 
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Round is executed.
     *********************************************************************/

    void computer_first();


    /*********************************************************************
     ** Function: Battle System
     ** Description: Logic for entire battle.
     ** Parameters: none.
     ** Pre-Conditions: Trainer objects exist with populated team[].
     ** Post-Conditions: One trainer wins.
     *********************************************************************/

    void battle_system();


    /*********************************************************************
     ** Function: Print Menu Options
     ** Description: Prints main menu for user.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Main menu is printed.
     *********************************************************************/

    void print_menu_options();


    /*********************************************************************
     ** Function: Menu System
     ** Description: Executes main menu logi for user.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Game starts, Trainers viewed, or game ends.
     *********************************************************************/

    void menu_system();


    /*********************************************************************
     ** Function: Color
     ** Description: Finds corresponding ANSI color for Pokemon.
     ** Parameters: pokemon
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: ANSI escape code is printed. (must close elsewhere)
     *********************************************************************/

    void color(const Pokemon*);


    /*********************************************************************
     ** Function: Credits
     ** Description: Prints game credits
     ** Parameters: none.
     ** Pre-Conditions: close_game()
     ** Post-Conditions: Credits are printed.
     *********************************************************************/

    void credits();


    /*********************************************************************
     ** Function: Close Game
     ** Description: Displays message to user and prints winners team.
     ** Parameters: none.
     ** Pre-Conditions: none.
     ** Post-Conditions: Message and team printed. 
     *********************************************************************/

    void close_game();


};

#endif