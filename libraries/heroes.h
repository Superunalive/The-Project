#ifndef HERO_H
#define HERO_H
#include <cstring>
#include <iostream>
#include <fstream>
class Hero {
    char *name_;
    int chealth_;
    int mhealth_;
    int damage_; //name, this and health are self-explanatory. c means current, m means maximum
    int mana_suck_; //placeholder name, how much mana player receives for dealing damage with this hero
    int behaviour_; //corresponds to an ability function
    int modifier_; //placeholder for ability strength-defining number
    
    public:

    Hero();
    Hero(Hero &other);
    
    char* GetName();
    int GetCurrentHealth();
    int GetMaxHealth();
    int GetDamage();
    int GetManaSuck();
    int GetBehaviour();
    int GetModifier();

    void Set(char *name, int health, int damage, int mana_suck, int behaviour, int modifier);
    void SetName(char *name);
    void SetCurrentHealth(int health);
    void SetMaxHealth(int health);
    void SetDamage(int damage);
    void SetManaSuck(int mana_suck);
    void SetBehaviour(int behaviour);
    void SetModifier(int modifier);
    
    ~Hero();


    Hero &operator=(Hero & other);
    friend std::ifstream &operator>>(std::ifstream&, Hero&);
};


#endif