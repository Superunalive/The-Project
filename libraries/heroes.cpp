#include "heroes.h"
#include <iostream>
#include <fstream>

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
