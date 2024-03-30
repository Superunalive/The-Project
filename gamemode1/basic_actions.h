#ifndef BASIC_ACTIONS_H
#define BASIC_ACTIONS_H

int hpos(int&, int&, int**);

void damage(int, int, int**, int**, int, int, char);

void step_pos(int&, int&, int**, int**, int, int, char);

void change_pos(int, int, int, int, int**, int**);

void counter_attack(int, int, int**, int**, int, int, char);

void death_check(int**, int**);

void board_output(int**, int**, int, int);

#endif // BASIC_ACTIONS_H