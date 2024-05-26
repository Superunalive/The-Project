#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "board.h"

namespace without {
void behaviour1(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);

void behaviour2(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);

void behaviour3(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);

void behaviour4(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);

void behaviour5(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);

void behaviour6(int& x, int& y, int** type, int** hp, int nx, int ny, char l, int turn);
}

namespace action{
void behaviour(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour1(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour2(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour3(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour4(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour5(int& x, int& y, Cell** board, int nx, int ny, char l);

void behaviour6(int& x, int& y, Cell** board, int nx, int ny, char l);
}
#endif // BEHAVIOUR_H 