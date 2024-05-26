#ifndef BASIC_ACTIONS_H
#define BASIC_ACTIONS_H

#include "board.h"
// type - таблица сторон объектов; hp - таблица здоровья

namespace without {

int hpos(int&, int&, int**, int); // где находится персонаж с классом
    
int hpos(int&, int&, int**); // где находится персонаж с классом

void damage(int, int, int**, int**, int, int, char, int); // нанесение урона объекту в (x,y); 

void step_pos(int&, int&, int**, int**, int, int, char, int); // выбор места для перемещения

void evasion_pos(int& x1, int& y1, int** type, int** hp, int nx, int ny, char l, int turn);

void change_pos(int, int, int, int, int**, int**); // два объекта меняются местами

void counter_attack(int, int, int**, int**, int, int, char); // контратака

void death_check(int**, int**); // у кого 0 хп

void board_output(int**, int**, int, int); // 1 вид вывода доски

}

namespace action{
    
int hpos(int&, int&, Cell**, int); // где находится персонаж с классом
    
int hpos(int&, int&, Cell**); // где находится персонаж с классом

void damage(int, int, Cell**, int, int, char); // нанесение урона объекту в (x,y); 

void damage(int, int, Cell**, int, int, char, double); // нанесение урона объекту в (x,y) c коэффициентом; 

void step_pos(int&, int&, Cell**, int, int, char); // выбор места для перемещения

void evasion_pos(int& x1, int& y1, Cell**, int nx, int ny, char l, int turn);

void change_pos(int&, int&, int, int, Cell**); // два объекта меняются местами

void counter_attack(int, int, Cell**, int, int, char); // контратака

void death_check(Cell**, int, int, int&, int&); // у кого 0 хп

void board_output(Cell**, int, int); // 1 вид вывода доски

}

#endif // BASIC_ACTIONS_H