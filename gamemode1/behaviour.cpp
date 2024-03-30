#include <iostream>
#include "behaviour.h"
#include "basic_actions.h"



void behaviour1(int& x, int& y, int** type, int** hp, int nx, int ny, char l){
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour2(int& x, int& y, int** type, int** hp, int nx, int ny, char l){
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour5(int& x, int& y, int** type, int** hp, int nx, int ny, char l){
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}