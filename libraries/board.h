#include "../libraries/heroes.h"
#ifndef BOARD_H
#define BOARD_H
struct Cell{
    Hero* hero; //nullptr = no hero. Walls are also heroes
    bool IsBusy; //can someone stand on/go through this cell
    int special_effect;
    int side;
    void SetCurrentHealth(int health){
        if (hero != nullptr){
            return hero->SetCurrentHealth(health);
        }
    }
    int GetCurrentHealth(){
        if (hero == nullptr){
            return 0;
        }
        return hero->GetCurrentHealth();
    }
    int GetDamage(){
        if (hero == nullptr){
            return 0;
        }
        return hero->GetDamage();
    }
    int GetBehaviour(){
        if (hero == nullptr){
            return 0;
        }
        return hero->GetBehaviour();
    }
};
#endif