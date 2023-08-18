/*********************************************************************
 ** Program Filename: Program 3 - pokemon.h
 ** Author: Blake Roberts (robeblak@oregonstate.edu)
 ** Date: 2021-07-20
 ** Description: Header file for abstract Pokemon class.
 ** Input: none.
 ** Output: none.
 *********************************************************************/

#ifndef POKEMON_CLASS_H
#define POKEMON_CLASS_H

/* STANDARD LIBRARIES */

#include <string>


class Pokemon {

    protected:

        enum eType {
            none,
            fire,
            grass,
            water,
            electric
        };


    private:

        std::string name;
        eType type;
        int health_points;
        int max_hp;
        int attack;
        int defense;
        int speed;
        std::string ascii;


    public:


    /* CONSTRUCTORS */

    /*********************************************************************
     ** Function: Default Constructor
     ** Description: Creates Pokemon object with default values.
     ** Parameters: name, type, health_points, max_hp, attack, defense, speed
     ** Pre-Conditions: none.
     ** Post-Conditions: Pokemon object created. 
     *********************************************************************/

    Pokemon(
        const std::string &name = "default", 
        const eType &type = none, 
        const int &health_points = 0, 
        const int &max_hp = 0,
        const int &attack = 0, 
        const int &defense = 0, 
        const int &speed = 0,
        const std::string &ascii = "");


    /* DESTRUCTORS */

    /*********************************************************************
     ** Function: Default Destructor (virtual)
     ** Description: Destroys Pokemon object.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists. 
     ** Post-Conditions: Pokemon object destroyed. 
     *********************************************************************/

    virtual ~Pokemon();


    /* ACCESSORS */

    /*********************************************************************
     ** Function: Get Name
     ** Description: Returns name value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: name returned.
     *********************************************************************/

    std::string get_name() const;


    /*********************************************************************
     ** Function: Get Type
     ** Description: Returns type value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists. 
     ** Post-Conditions: type returned.
     *********************************************************************/

    eType get_type() const;


    /*********************************************************************
     ** Function: Get health points.
     ** Description: Returns health_points value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: health_points returned.
     *********************************************************************/

    int get_health_points() const;


    /*********************************************************************
     ** Function: Get Max HP
     ** Description: Returns max_hp value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: max_hp returned.
     *********************************************************************/

    int get_max_hp() const;


    /*********************************************************************
     ** Function: Get Attack
     ** Description: Returns attack value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: attack returned.
     *********************************************************************/

    int get_attack() const;


    /*********************************************************************
     ** Function: Get Defense
     ** Description: Returns defense value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: defense returned.
     *********************************************************************/

    int get_defense() const;


    /*********************************************************************
     ** Function: Get Speed
     ** Description: Returns speed value.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: speed returned. 
     *********************************************************************/

    int get_speed() const;


    /*********************************************************************
     ** Function: Get ASCII
     ** Description: Returns ascii (filename).
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: ascii returned.
     *********************************************************************/

    std::string get_ascii() const;


    /* MUTATORS */

    /*********************************************************************
     ** Function: Set Name
     ** Description: Sets name value.
     ** Parameters: name
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: name set.
     *********************************************************************/

    void set_name(const std::string &);


    /*********************************************************************
     ** Function: Set Nickname
     ** Description: Give prompts to user to set alternate name value.
     ** Parameters: i (index)
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: name set.
     *********************************************************************/

    void set_nickname(const int &);


    /*********************************************************************
     ** Function: Set Type
     ** Description: Sets type value.
     ** Parameters: type
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: type set.
     *********************************************************************/

    void set_type(const eType &);


    /*********************************************************************
     ** Function: Set Health Points
     ** Description: Sets health_points value.
     ** Parameters: health_points
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: health_points set.
     *********************************************************************/

    void set_health_points(const int &);


    /*********************************************************************
     ** Function: Set Attack
     ** Description: Sets attack value.
     ** Parameters: attack
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: attack set.
     *********************************************************************/

    void set_attack(const int &);


    /*********************************************************************
     ** Function: Set Defense
     ** Description: Sets defense value.
     ** Parameters: defense
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: defense set.
     *********************************************************************/

    void set_defense(const int &);


    /*********************************************************************
     ** Function: Set Speed
     ** Description: Sets speed value.
     ** Parameters: speed
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: speed set.
     *********************************************************************/

    void set_speed(const int &);


    /*********************************************************************
     ** Function: Set ASCII
     ** Description: Sets ascii (filename) value.
     ** Parameters: ascii
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: ascii set.
     *********************************************************************/

    void set_ascii(const std::string &);


    /* OTHER METHODS */

    /*********************************************************************
     ** Function: Damage
     ** Description: Calculates damage value of Pokemon attack.
     ** Parameters: pokemon
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: returns damage value.
     *********************************************************************/

    int damage(Pokemon*);


    /*********************************************************************
     ** Function: Type Effectiveness
     ** Description: Return type effectiveness of Pokemon attack.
     ** Parameters: pokemon (opponent)
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: returns type_effectiveness
     *********************************************************************/

    double type_effectiveness(Pokemon*);


    /*********************************************************************
     ** Function: Translate Type
     ** Description: Returns string containing type name.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: type name returned. 
     *********************************************************************/

    std::string translate_type();


    /*********************************************************************
     ** Function: Print (virtual)
     ** Description: Prints Pokemon info.
     ** Parameters: none.
     ** Pre-Conditions: Pokemon object exists.
     ** Post-Conditions: Pokemon info printed.
     *********************************************************************/

    virtual void print();


};

#endif