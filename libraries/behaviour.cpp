#include <iostream>
#include "behaviour.h"
#include "basic_actions.h"

namespace without{

void behaviour1(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int dm){ // обычный
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,dm);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l,3);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour2(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int dm){ //толкающий
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,dm);
    //push_pos(x1,y1,type,hp,nx,ny,l);
    damage(x1,y1,type,hp,nx,ny,l,3);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour3(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int dm){ //пробивающий
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,dm);
    change_pos(x,y,x1,y1,type,hp);
    //pierce_damage(x1,y1,type,hp,nx,ny,l);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour4(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int dm){ // защищающий , не забыть проверку класса при контратаке
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,dm);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l,3);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour5(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn){ //уклоняющий
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,turn);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l,3);
    int x2 = x1;
    int y2 = y1;
    evasion_pos(x2,y2,type,hp,nx,ny,l,turn); 
    change_pos(x1,y1,x2,y2,type,hp);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}

void behaviour6(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int dm){ // прыгающий, мне лень реализовывать
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,type,hp,nx,ny,l,dm);
    change_pos(x,y,x1,y1,type,hp);
    damage(x1,y1,type,hp,nx,ny,l,3);
    counter_attack(x1,y1,type,hp,nx,ny,l);
}
}

namespace action{

void behaviour(int& x, int& y, Cell** board, int nx, int ny, char l){ //выбор поведения
    if (board[x][y].GetBehaviour()==1){
        behaviour1(x, y, board, nx, ny, l);
    }
}

void behaviour1(int& x, int& y, Cell** board, int nx, int ny, char l){ // обычный
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,board,nx,ny,l);
    change_pos(x,y,x1,y1,board);
    damage(x1,y1,board,nx,ny,l);
    counter_attack(x1,y1,board,nx,ny,l);
}

}