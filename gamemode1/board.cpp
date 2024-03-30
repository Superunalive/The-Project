#include <iostream>
#include <limits>
#include "basic_actions.h"
#include "behaviour.h"

#include "basic_actions.cpp"
#include "behaviour.cpp"

int main()
{
    int nx = 5;
    int ny = 5;
    int **type = new int* [nx];
    int **hp = new int* [nx];
    for (int i =0; i<5; i++){
        type[i] = new int [ny];
        hp[i] = new int [ny];
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
    int x = 0;
    int y = 0;
    char l = 'h';
    while (l!='0')
    {   
        if (hpos(x,y,type)==1){
            break;
        }
        behaviour1(x,y,type,hp,nx,ny,l);
        death_check(type,hp);
        board_output(type,hp,nx,ny);
        std::cin >> l;
        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    for (int i = 0; i<5; i++){
            delete type[i];
            delete hp[i];
        }
    delete[] type;
    delete[] hp;
    return 0;
}
