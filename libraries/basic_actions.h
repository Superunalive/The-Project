#ifndef BASIC_ACTIONS_H
#define BASIC_ACTIONS_H

#include "heroes.h"
#include <vector>

int hpos(int&, int&, Cell**, int); // где находится персонаж с классом
    
int hpos(int&, int&, Cell**); // где находится персонаж с классом

void damage(int, int, Cell**, int, int, char); // нанесение урона объекту в (x,y); 

void damage(int, int, Cell**, int, int, char, double); // нанесение урона объекту в (x,y) c коэффициентом; 

void step_pos(int&, int&, Cell**, int, int, char); // выбор места для перемещения

void evasion_pos(int& x1, int& y1, Cell**, int nx, int ny, char l);

void change_pos(int&, int&, int, int, Cell**); // два объекта меняются местами

void counter_attack(int, int, Cell**, int, int, char); // контратака

void death_check(Cell**, int, int, int&, int&, std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2,std::vector<int>& y2); // у кого 0 хп

void board_output(Cell**, int, int, int, int); // 1 вид вывода доски

void hero_spawn(Cell** board, int nx, int ny, Hero* hero, int side, std::vector<int>& x, std::vector<int>& y); // добавление героя на нужное место строки

void pierce_damage(int x1, int y1, Cell** board, int nx,int ny,char l);

#endif // BASIC_ACTIONS_H