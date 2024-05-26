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

    Hero(){
        name_ = new char[20];
        chealth_, mhealth_, damage_, mana_suck_ = 0;
        modifier_ = 1;
    }
    Hero(Hero &other){
        (*this).name_ = new char[20];
        *this = other;
    }
    
    char* GetName(){
        return name_;
    }
    int GetCurrentHealth(){
        return chealth_;
    }
    int GetMaxHealth(){
        return mhealth_;
    }
    int GetDamage(){
        return damage_;
    }
    int GetManaSuck(){
        return mana_suck_;
    }
    int GetBehaviour(){
        return behaviour_;
    }
    int GetModifier(){
        return modifier_;
    }

    void Set(char *name, int health, int damage, int mana_suck, int behaviour, int modifier){
        (*this).SetName(name);
        (*this).SetCurrentHealth(health);
        (*this).SetMaxHealth(health);
        (*this).SetDamage(damage);
        (*this).SetManaSuck(mana_suck);
        (*this).SetBehaviour(behaviour);
        (*this).SetModifier(modifier);
    }
    void SetName(char *name){
        strcpy(name_, name);
    }
    void SetCurrentHealth(int health){
        this->chealth_ = health;
    }
    void SetMaxHealth(int health){
        this->mhealth_ = health;
    }
    void SetDamage(int damage){
        this->damage_ = damage;
    }
    void SetManaSuck(int mana_suck){
        this->mana_suck_ = mana_suck;
    }
    void SetBehaviour(int behaviour){
        this->behaviour_ = behaviour;
    }
    void SetModifier(int modifier){
        this->modifier_ = modifier;
    }
    
    ~Hero(){
        delete [] name_;
    }

    Hero &operator=(Hero & other){
        if (this == &other){
            return *this;
        }
        (*this).Set(other.name_, other.mhealth_, other.damage_, other.mana_suck_, other.behaviour_, other.modifier_);
        return *this;
    }
    friend std::ifstream &operator>>(std::ifstream&, Hero&);
};


#endif