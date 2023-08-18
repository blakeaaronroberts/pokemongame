/*********************************************************************
 ** Program Filename: Program 3 - arena.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Implementation file for Arena class.
 ** Input: User input.
 ** Output: Game management.
 *********************************************************************/

/* STANDARD LIBRARIES */

#include <iostream>
#include <iomanip>
#include <string>


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

Arena::Arena() {
    /* default constructor */
    /* sets roster for team selection menu */
    roster[0] = new Bulbasaur();
    roster[1] = new Charmander();
    roster[2] = new Squirtle();
    roster[3] = new Pikachu();
}


/* DESTRUCTORS */

Arena::~Arena() {
    /* default destructor */
    /* loops through roster, deleting each pointer */
    for(int i = 0; i < 4; i++) {
        delete roster[i];
    }
}


/* ACCESSORS */
/* return member variables */

Trainer Arena::get_trainer(const int &i) {
    return trainer[i];
}


/* OTHER METHODS */

void Arena::open_game() {
    /* print opening sequence */
    system("clear");
    print_ascii_art("welcome.txt");
    sleep(2000);
    system("clear");
    print_ascii_art("to.txt");
    sleep(2000);
    system("clear");
    std::cout << "\033[1;33m";
    print_ascii_art("poke_logo.txt");
    std::cout << "\033[0;m";
    sleep(1000); 
    /* get player name */
    typewriter("Hello there, Trainer!\n");
    sleep(1000); 
    typewriter("What's your name? ");
    std::string input;
    std::cin >> input;
    trainer[0].set_name(input);
}


void Arena::set_opponent_team() {
    /* sets opponent team to random pokemon */
    for(int i = 0; i < 3; i++) {
        trainer[1].set_pokemon(i, rand() % 4 + 1);
        //trainer[1].set_pokemon(i, 3);
        // ^sets to all squirtles for debugging^
    }
}


void Arena::set_user_team() {
    /* sets users team to all pikachus for debugging */
    for(int i = 0; i < 3; i++) {
        trainer[0].set_pokemon(i, 4);
    }
}


void Arena::preview(const int &i) {
    /* Print ASCII art and info */
    system("clear");
    color(roster[i - 1]);
    print_ascii_art(roster[i - 1]->get_ascii()); 
    std::cout << "\033[0;m";
    roster[i - 1]->print();
    print_str("\n");
}


void Arena::select_pokemon(std::string &pokemon, std::string &input) {
    /* take user input for pokemon selection */
    print_str("Select a Pokemon: ");
    input_to_str(pokemon);
    int_check(pokemon, 1, 4);
    preview(stoi(pokemon));
    sleep(1000);
    typewriter("Do you want to add "); 
    typewriter(roster[stoi(pokemon) - 1]->get_name()); 
    typewriter(" to your team?");
    print_str("\n1. Yes\n2. No\n");
    input_to_str(input);
    int_check(input, 1, 2);
}


void Arena::selection_menu() {
    /* print selection menu */
    std::string pokemon, input;
    typewriter("Choose your team!\n\n");
    for(int i = 0; i < 3; i++) {
        print_int(3 - i);
        print_str(" spots remaining.\n\n");
        print_list_pokemon();
        select_pokemon(pokemon, input);
        if(stoi(input) == 1) {
            /* set pokemon and prompt for nickname */
           trainer[0].set_pokemon(i, stoi(pokemon));
           trainer[0].get_pokemon(i)->set_nickname(i);
           typewriter(trainer[0].get_pokemon(i)->get_name()); 
           typewriter(" was added to your team!\n\n"); 
           sleep(1000);
           system("clear");
        } else {
            i--;
            system("clear");
        }
    }
}


void Arena::print_list_pokemon() const {
    /* Print roster of pokemon */
    for(int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << roster[i]->get_name() << "\n";
    }
    print_str("\n");
}


void Arena::choose_team() {
    /* welcome message and selection menu */
    system("clear");
    typewriter("Welcome to the \033[0;32mCorvallis\033[0m region, ");
    sleep(1000);
    std::string name = "\033[1;33m" + trainer[0].get_name() + "\033[0m!\n";
    typewriter(name);
    sleep(1000);
    selection_menu();
    system("clear");
}


void Arena::battle_display_opponent() {
    /* display opponent for battle */
    print_str(trainer[1].get_name());
    print_str("\n\n↓ WAITING ↓\n\n| ");
    print_str(trainer[1].get_pokemon(2)->get_name());
    print_str(" HP: ");
    print_int(trainer[1].get_pokemon(2)->get_health_points());
    print_str(" | ");
    print_str(trainer[1].get_pokemon(1)->get_name());
    print_str(" HP: ");
    print_int(trainer[1].get_pokemon(1)->get_health_points());
    print_str(" |\n\n↓ IN BATTLE ↓\n\n");
    trainer[1].get_pokemon(0)->print();
}


void Arena::battle_display_user() {
    /* display user for battle */
    trainer[0].get_pokemon(0)->print();
    print_str("\n↑ IN BATTLE ↑\n\n| ");
    print_str(trainer[0].get_pokemon(1)->get_name());
    print_str(" HP: ");
    print_int(trainer[0].get_pokemon(1)->get_health_points());
    print_str(" | ");
    print_str(trainer[0].get_pokemon(2)->get_name());
    print_str(" HP: ");
    print_int(trainer[0].get_pokemon(2)->get_health_points());
    print_str(" |\n\n↑ WAITING ↑ \n\n");
    print_str(trainer[0].get_name());
}


void Arena::print_battle_menu() {
    /* print user battle menu */
    print_str("\nMenu: \n");
    print_str("____________________");
    print_str("\n\n1. Attack\n2. Heal\n3. Swap\n");
    print_str("____________________\n\n");
    print_str("Make a Selection: ");
}


bool Arena::game_over() {
    /* checks if either trainers entire team has fainted */
    if(
        trainer[0].get_pokemon(0)->get_health_points() <= 0
        && trainer[0].get_pokemon(1)->get_health_points() <= 0
        && trainer[0].get_pokemon(2)->get_health_points() <= 0) {
            return true; // if users team has fainted
        } else if (
            trainer[1].get_pokemon(0)->get_health_points() <= 0
            && trainer[1].get_pokemon(1)->get_health_points() <= 0
            && trainer[1].get_pokemon(2)->get_health_points() <= 0) {
                return true; // if computers team has fainted
            }
        return false; // otherwise.
}


bool Arena::user_pokemon_is_faster() {
    /* checks if the users attack pokemon is faster than the computers */
    if(trainer[0].get_pokemon(0)->get_speed() 
        > trainer[1].get_pokemon(0)->get_speed()) {
            return true; // if users is faster
        }
    return false; // otherwise.
}


void Arena::opponent_move(const int &n) {
    /* executes opponent move based on n from opponent_turn() */
    int decision = (rand() % 4) + 1; // decision odds 4 to 1
    if(n == 1 && decision == 1) { // n == 1
        trainer[1].heal(last_move); // least likely
    } else if (n == 1) {
        trainer[1].attack(trainer[0].get_pokemon(0), last_move); //most likely
    } else if (n == 2 && decision == 1) { // n == 2
        trainer[1].attack(trainer[0].get_pokemon(0), last_move); // least likely
    } else if (n == 2) {
        trainer[1].heal(last_move); // most likely
    } else if (n == 3 && decision == 1) { // n == 3
        trainer[1].heal(last_move); // least likely
    } else if (n == 3) {
        trainer[1].opponent_swap(last_move); // most likely
    }
}


void Arena::opponent_turn() {
    /* Strategy for computer trainer */
    prepare_arena();
    if(trainer[1].get_pokemon(0)->get_health_points() <= 0 && !game_over()) {
        trainer[1].opponent_swap(last_move); // swap if fainted
    } else if (trainer[1].get_pokemon(0)->get_health_points() 
        == trainer[1].get_pokemon(0)->get_max_hp() && !game_over()) {
            trainer[1].attack(trainer[0].get_pokemon(0), last_move); 
            // attack if full health_points
    }else if(trainer[1].get_pokemon(0)->get_health_points() 
        > (trainer[1].get_pokemon(0)->get_max_hp() * .66) && !game_over()) {
        opponent_move(1); // if health_points greater than 66%
    } else if(trainer[1].get_pokemon(0)->get_health_points() 
        > (trainer[1].get_pokemon(0)->get_max_hp() * .33) && !game_over()) {
        opponent_move(2); // if health_point greater than 33%
    } else if(trainer[1].get_pokemon(0)->get_health_points() 
        <= (trainer[1].get_pokemon(0)->get_max_hp() * .33) && !game_over()) {
        opponent_move(3); // if health_points lower than or equal to 33%
    }
}


void Arena::user_turn() {
    /* execute user turn */
    if(trainer[0].pokemon_fainted() && !game_over()) { // attack pokemon fainted
        prepare_arena();
        trainer[0].swap(last_move); // force swap
    } else if (!game_over()) {
        prepare_arena();
        print_battle_menu();
        std::string input;
        input_to_str(input); // user choice
        int_check(input, 1, 3);
        switch(stoi(input)) {
            case 1: // attack
                trainer[0].attack(trainer[1].get_pokemon(0), last_move);
                break;
            case 2: // heal
                trainer[0].heal(last_move);
                break;
            case 3: // swap
                trainer[0].swap(last_move);
                break;
        }
    }
}


void Arena::prepare_arena() {
    /* Display arena and give last_move update */
    system("clear");
    print_str("\n___________________________________________\n\n");
    battle_display_opponent();
    print_str("\n");
    print_str("\n___________________________________________\n");
    print_str("\n\n");
    battle_display_user();
    print_str("\n___________________________________________\n");
    print_str("\n\n");
    typewriter(last_move);
    last_move = "";
    sleep(1000);
}

void Arena::user_first() {
    /* executes round with user first */
    last_move.append(trainer[0].get_name());
    last_move.append(" gets to go first this round!\n");
    user_turn();
    sleep(2000);
    opponent_turn();
    sleep(2000);
}


void Arena::computer_first() {
    /* executes round with user first */
    last_move.append(trainer[1].get_name());
    last_move.append(" gets to go first this round!\n");
    opponent_turn();
    sleep(2000);
    user_turn();
    sleep(2000);
}

void Arena::battle_system() {
    /* executes battle system for entire battle */
    /* checks which pokemon is faster and if it is fainted */
    while(!game_over()) {
        if(user_pokemon_is_faster()
            &&  trainer[0].get_pokemon(0)->get_health_points() > 0) {
                user_first();
        } else {
            computer_first();
        }
    }
}


void Arena::print_menu_options() {
    /* print main menu for user */
    print_str("\nMenu: \n");
    print_str("____________________");
    print_str("\n\n1. Start Battle.\n2. View ");
    print_str(trainer[1].get_name());
    print_str("'s Team.\n3. View ");
    print_str(trainer[0].get_name());
    print_str("'s Team.\n4. Quit\n");
    print_str("____________________\n\n");
    print_str("Make a Selection: ");
}


void Arena::menu_system() {
    /* ececutes main menu system for user */
    std::string input = "0";
    typewriter("Ready when you are, \033[0;33m");
    sleep(1000);
    typewriter(trainer[0].get_name());
    print_str("\033[0;m!\n");
    while(stoi(input) < 4) {
        print_menu_options();
        input_to_str(input); // User input
        int_check(input, 1, 4);
        if(stoi(input) == 1) {
            battle_system(); // Battle
            input = "4";
        } else if(stoi(input) == 2) {
            system("clear");
            trainer[1].print_team(); // Print opponents team
        } else if(stoi(input) == 3) {
            system("clear");
            trainer[0].print_team(); // Print users team
        }
    }
    
}

void Arena::color(const Pokemon* pokemon) {
    /* Prints ANSI escape code for coloring text for type */
    switch(pokemon->get_type()) {
        case 0:
            break;
        case 1:
            std::cout << "\033[0;31m"; // Red
            break;
        case 2: 
            std::cout << "\033[0;32m"; // Green
            break;
        case 3:
            std::cout << "\033[0;36m"; // Blue
            break;
        case 4:
            std::cout << "\033[0;33m"; // Yellow
            break;
    }    
}


void Arena::credits() {
    /* Prints credits */
    system("clear");
    std::cout << "\033[1;33m";
    print_ascii_art("poke_logo.txt");
    std::cout << "\033[0;m";
    sleep(2000);
    system("clear");
    print_ascii_art("credits.txt");
    sleep(10000);
    system("clear");
    typewriter("Thanks for visiting the \033[0;32mCorvallis\033[0m region, ");
    sleep(1000);
    std::string name = "\033[1;33m" + trainer[0].get_name() + "\033[0m!\n";
    typewriter(name);
    typewriter("Come again soon!\n\n");
    sleep(2000);
}

void Arena::close_game() {
    /* print closing sequence */
    system("clear");
    if(trainer[0].is_winner()) {
        print_ascii_art("congratulations.txt");
        sleep(2000);
        for(int i = 0; i < 3; i++) {
            color(trainer[0].get_pokemon(i));
            print_ascii_art(trainer[0].get_pokemon(i)->get_ascii());
            print_str("\033[0m!");
            sleep(2000);
        }
        credits();
    } else {
        print_ascii_art("condolences.txt");
        sleep(2000);
        for(int i = 0; i < 3; i++) {
            color(trainer[1].get_pokemon(i));
            print_ascii_art(trainer[1].get_pokemon(i)->get_ascii());
            print_str("\033[0m!");
            sleep(2000);
        }
        sleep(2000);
        credits();
    }
}


