#ifndef CELL_H
#define CELL_H
#include "heroes.h"

class Cell{
    int fraction_;
    Hero *hero_;
    int status_;
    public:
    Cell() {hero_ = nullptr;}
    Cell(Cell &other) { //should I copy heroes as well?
      this->fraction_ = other.fraction_;
      this->status_ = other.status_;
    }
    void SetFraction(int fraction);
    void SetHero(Hero &hero);
    void SetStatus(int status);

    int GetFraction();
    int GetStatus();
    Hero GetHero();
    
};

#endif