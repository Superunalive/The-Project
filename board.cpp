#include <iostream>
#include <limits>
#include "libraries/basic_actions.h"
#include "libraries/behaviour.h"
#include "main_code/board.h"

#include "libraries/basic_actions.cpp"
#include "libraries/behaviour.cpp"


void gamemode1(int nx, int ny, int** type, int **hp);

void gamemode2(int nx, int ny, int** type, int **hp);

int main()
{
    #ifdef WIN32
    system("chcp 65001");   
    #else
    setlocale(LC_ALL, "Russian");
    #endif
    int nx = 5;
    int ny = 5;
    int **type = new int* [nx];
    int **hp = new int* [nx];
    for (int i =0; i<5; i++){
        type[i] = new int [ny];
        hp[i] = new int [ny];

        //новый код с доской
    }
    for (int i =0; i<5; i++){
        for (int j =0; j<5; j++){
            std::cin >> type[i][j];
        }
    }
    for (int i =0; i<5; i++){
        for (int j =0; j<5; j++){
            std::cin >> hp[i][j];
        }
    }
    gamemode2(nx, ny, type, hp);
    for (int i = 0; i<5; i++){
            delete type[i];
            delete hp[i];
        }
    delete[] type;
    delete[] hp;
    return 0;
}

void gamemode1(int nx, int ny, int** type, int **hp){
    int x = 0;
    int y = 0;
    char l = 'h';
    while (l!='0')
    {   
        if (hpos(x,y,type)==1){
            break;
        }
        behaviour1(x,y,type,hp,nx,ny,l,1);
        death_check(type,hp);
        board_output(type,hp,nx,ny);
        std::cin >> l;
        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void gamemode2(int nx, int ny, int** type, int **hp){
    int x = 0;
    int y = 0;
    int x2 = 0;
    int y2 = 0;
    char l = 'h';
    int turn = 2;
    while (l!='0')
    {   
        hpos(x,y,type);
        hpos(x2,y2,type,2);
        if (hpos(x,y,type)){
            break;
        }
        if (turn==1){
            behaviour1(x,y,type,hp,nx,ny,l,1);
            turn = 2;
            death_check(type,hp);
            board_output(type,hp,nx,ny);
            std::cout << "Ход игрока 2:";
        }
        else {
            behaviour5(x2,y2,type,hp,nx,ny,l,2);
            turn = 1;
            death_check(type,hp);
            board_output(type,hp,nx,ny);
            std::cout << "Ход игрока 1:";
        }
        std::cin >> l;
        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}