/*********************************************************************
 ** Program Filename: Program 3 - application.cpp
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-08-01
 ** Description: Plays one Pokemon battle between user and computer.
 ** Input: User.
 ** Output: Console.
 *********************************************************************/

/*  ASCII art taken from https://www.asciiart.eu/video-games/pokemon */

/* STANDARD LIBRARIES */

#include <iostream>
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


int main () {

    srand(time(NULL));

    Arena arena;
    arena.open_game();
    arena.set_opponent_team();
    arena.choose_team();
    arena.menu_system();
    arena.close_game();

    return 0;
}