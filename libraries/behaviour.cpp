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

void behaviour(int& x, int& y, Cell** board, int nx, int ny, char l,int& kills_one, int& kills_two,std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2, std::vector<int>& y2){ //выбор поведения
    if (board[x][y].GetBehaviour()==1){
        behaviour1(x, y, board, nx, ny, l);
    }
    if (board[x][y].GetBehaviour()==2){
        behaviour1(x, y, board, nx, ny, l);
    }
    if (board[x][y].GetBehaviour()==3){
        behaviour3(x, y, board, nx, ny, l);
    }
    if (board[x][y].GetBehaviour()==4){
        behaviour1(x, y, board, nx, ny, l);
    }
    if (board[x][y].GetBehaviour()==5){
        behaviour5(x, y, board, nx, ny, l,kills_one,kills_two,x1,y1,x2,y2);
    }
    if (board[x][y].GetBehaviour()==6){
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

void behaviour2(int& x, int& y, Cell** board, int nx, int ny, char l){ // толкающий
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,board,nx,ny,l);
    change_pos(x,y,x1,y1,board);
    damage(x1,y1,board,nx,ny,l);
    counter_attack(x1,y1,board,nx,ny,l);
    //не сделал
}

void behaviour3(int& x, int& y, Cell** board, int nx, int ny, char l){
    int x1 = x;
    int y1 = y;
    step_pos(x1,y1,board,nx,ny,l);
    change_pos(x,y,x1,y1,board);
    pierce_damage(x1,y1,board,nx,ny,l);
    counter_attack(x1,y1,board,nx,ny,l);
}

void behaviour5(int& x, int& y, Cell** board, int nx, int ny, char l,int& kills_one, int& kills_two,std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2, std::vector<int>& y2){ //уклоняющий
    int x3 = x;
    int y3 = y;
    step_pos(x3,y3,board,nx,ny,l);
    change_pos(x,y,x3,y3,board);
    damage(x3,y3,board,nx,ny,l);
    int x4 = x3;
    int y4 = y3;
    evasion_pos(x4,y4,board,nx,ny,l); 
    death_check(board,nx,ny,kills_one,kills_two,x1,y1,x2,y2);
    change_pos(x,y,x4,y4,board);
}

}
