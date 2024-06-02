#include "heroes.h"
#include <iostream>
#include <fstream>


Hero::Hero(){
    name_ = new char[20];
    chealth_, mhealth_, damage_, mana_suck_ = 0;
    modifier_ = 1;
}
Hero::Hero(Hero &other){
    (*this).name_ = new char[20];
    *this = other;
}
    
char* Hero::GetName(){
    return name_;
}
int Hero::GetCurrentHealth(){
    return chealth_;
}
int Hero::GetMaxHealth(){
    return mhealth_;
}
int Hero::GetDamage(){
    return damage_;
}
int Hero::GetManaSuck(){
    return mana_suck_;
}
int Hero::GetBehaviour(){
    return behaviour_;
}
int Hero::GetModifier(){
    return modifier_;
}

void Hero::Set(char *name, int health, int damage, int mana_suck, int behaviour, int modifier){
    (*this).SetName(name);
    (*this).SetCurrentHealth(health);
    (*this).SetMaxHealth(health);
    (*this).SetDamage(damage);
    (*this).SetManaSuck(mana_suck);
    (*this).SetBehaviour(behaviour);
    (*this).SetModifier(modifier);
}
void Hero::SetName(char *name){
    strcpy(name_, name);
}
void Hero::SetCurrentHealth(int health){
    this->chealth_ = health;
}
void Hero::SetMaxHealth(int health){
    this->mhealth_ = health;
}
void Hero::SetDamage(int damage){
    this->damage_ = damage;
}
void Hero::SetManaSuck(int mana_suck){
    this->mana_suck_ = mana_suck;
}
void Hero::SetBehaviour(int behaviour){
    this->behaviour_ = behaviour;
}
void Hero::SetModifier(int modifier){
    this->modifier_ = modifier;
}
    
Hero::~Hero(){
    delete [] name_;
}

Hero &Hero::operator=(Hero & other){
    if (this == &other){
        return *this;
    }
    (*this).Set(other.name_, other.mhealth_, other.damage_, other.mana_suck_, other.behaviour_, other.modifier_);
    return *this;
}

std::ifstream &operator>>(std::ifstream &in, Hero &hero){
    in >> hero.name_;
    in >> hero.mhealth_ >> hero.damage_ >> hero.mana_suck_ >> hero.behaviour_ >> hero.modifier_;
    hero.chealth_ = hero.mhealth_;
    return in;
}
void read_db(Hero *&db){
    int n;
    std::ifstream in("heroes_db.txt", std::ios::in | std::ios::binary);
    in >> n;
    delete [] db;
    db = new Hero[n];
    for(int i = 0; i < n; i++){
        in >> db[i];
    }
    in.close();
}
