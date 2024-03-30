#include <iostream>
#include "basic_actions.h"

int hpos(int& x, int& y, int** type){
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            if (type[i][j] == 1){
                x = i;
                y = j;
                return 0;
            }
        }
    }
    return 1;
}

void damage(int x, int y, int** type, int** hp, int nx, int ny, char l){
    if ((l=='w')&&(x>0)&&(type[x-1][y]!=0)){
        hp[x-1][y]--;
    }
    if ((l=='a')&&(y>0)&&(type[x][y-1]!=0)){
        hp[x][y-1]--;
    }
    if ((l=='s')&&(x<4)&&(type[x+1][y]!=0)){
        hp[x+1][y]--;
    }
    if ((l=='d')&&(y<4)&&(type[x][y+1]!=0)){
        hp[x][y+1]--;
    }
    
}

void step_pos(int& x1, int& y1, int** type, int** hp, int nx, int ny, char l){
    if (l=='w'){
        while ((x1>0)&&((type[x1-1][y1]==0)||(type[x1-1][y1]==1))){
            x1--;
            std::cout << x1 << " " << y1 << std::endl;
        }
    }
    if (l=='a'){
        while ((y1>0)&&((type[x1][y1-1]==0)||(type[x1][y1-1]==1))){
            y1--;
        }
    }
    if (l=='s'){
        while ((x1<(nx-1))&&((type[x1+1][y1]==0)||(type[x1+1][y1]==1))){
            x1++;
        }
    }
    if (l=='d'){
        while ((y1<(ny-1))&&((type[x1][y1+1]==0)||(type[x1][y1+1]==1))){
            y1++;
        }
    }
}

void change_pos(int x, int y, int x1, int y1, int** type, int** hp){
    int p = hp[x1][y1];
    hp[x1][y1] = hp[x][y];
    hp[x][y] = p;
    p = type[x1][y1];
    type[x1][y1] = type[x][y];
    type[x][y] = p;
}

void counter_attack(int x, int y, int** type, int** hp, int nx, int ny, char l){
    if ((l=='w')&&(x>0)&&(type[x-1][y]!=0)){
        damage(x-1,y,type,hp,nx,ny,'s');
    }
    if ((l=='a')&&(y>0)&&(type[x][y-1]!=0)){
        damage(x,y-1,type,hp,nx,ny,'d');
    }
    if ((l=='s')&&(x<(nx-1))&&(type[x+1][y]!=0)){
        damage(x+1,y,type,hp,nx,ny,'w');
    }
    if ((l=='d')&&(y<(ny-1))&&(type[x][y+1]!=0)){
        damage(x,y+1,type,hp,nx,ny,'a');
    }

}

void death_check(int** type, int** hp){
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            if (hp[i][j]==0){
                type[i][j] = 0;
            }
        }
    }
}

void board_output(int**type, int**hp, int nx, int ny){
    for (int i =0; i<nx; i++){
            for (int j = 0; j<5; j++){
                std::cout << type[i][j] << " ";
            }
            std::cout << "\t";
            for (int j =0; j<ny; j++){
                std::cout << hp[i][j] << " ";
            }
            std::cout << std::endl;
        }
}