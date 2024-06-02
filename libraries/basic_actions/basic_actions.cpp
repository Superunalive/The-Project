#include <iostream>
#include "basic_actions.h"
#include <ctime>


// type - таблица сторон объектов; hp - таблица здоровья

void damage(int x, int y, Cell** board, int nx, int ny, char l){ // нанесение урона объект в (x,y); 
if ((l=='w')&&(x>0)&&(board[x-1][y].IsBusy!=0)&&(board[x-1][y].side!=board[x][y].side)){
        board[x-1][y].SetCurrentHealth(board[x-1][y].GetCurrentHealth()-board[x][y].GetDamage());
    }
    if ((l=='a')&&(y>0)&&(board[x][y-1].IsBusy!=0)&&(board[x][y-1].side!=board[x][y].side)){
        board[x][y-1].SetCurrentHealth(board[x][y-1].GetCurrentHealth()-board[x][y].GetDamage());
    }
    if ((l=='s')&&(x<4)&&(board[x+1][y].IsBusy!=0)&&(board[x+1][y].side!=board[x][y].side)){
        board[x+1][y].SetCurrentHealth(board[x+1][y].GetCurrentHealth()-board[x][y].GetDamage());
    }
    if ((l=='d')&&(y<4)&&(board[x][y+1].IsBusy!=0)&&(board[x][y+1].side!=board[x][y].side)){
        board[x][y+1].SetCurrentHealth(board[x][y+1].GetCurrentHealth()-board[x][y].GetDamage());
    }
}

void damage(int x, int y, Cell** board, int nx, int ny, char l, double k){ // нанесение урона объект в (x,y); 
    if ((l=='w')&&(x>0)&&(board[x-1][y].IsBusy!=0)&&(board[x-1][y].side!=board[x][y].side)){
        board[x-1][y].SetCurrentHealth(board[x-1][y].GetCurrentHealth()-board[x][y].GetDamage()*k);
    }
    if ((l=='a')&&(y>0)&&(board[x][y-1].IsBusy!=0)&&(board[x][y-1].side!=board[x][y].side)){
        board[x][y-1].SetCurrentHealth(board[x][y-1].GetCurrentHealth()-board[x][y].GetDamage()*k);
    }
    if ((l=='s')&&(x<4)&&(board[x+1][y].IsBusy!=0)&&(board[x+1][y].side!=board[x][y].side)){
        board[x+1][y].SetCurrentHealth(board[x+1][y].GetCurrentHealth()-board[x][y].GetDamage()*k);
    }
    if ((l=='d')&&(y<4)&&(board[x][y+1].IsBusy!=0)&&(board[x][y+1].side!=board[x][y].side)){
        board[x][y+1].SetCurrentHealth(board[x][y+1].GetCurrentHealth()-board[x][y].GetDamage()*k);
    }
}

void step_pos(int& x1, int& y1, Cell** board, int nx, int ny, char l){
    if (l=='w'){
        while ((x1>0)&&((board[x1-1][y1].IsBusy==0))){
            x1--;
        }
    }
    if (l=='a'){
        while ((y1>0)&&((board[x1][y1-1].IsBusy==0))){
            y1--;
        }
    }
    if (l=='s'){
        while ((x1<(nx-1))&&((board[x1+1][y1].IsBusy==0))){
            x1++;
        }
    }
    if (l=='d'){
        while ((y1<(ny-1))&&((board[x1][y1+1].IsBusy==0))){
            y1++;
        }
    }
}

void pierce_damage(int x, int y, Cell** board, int nx,int ny,char l){
    int x1 = x;
    int y1 = y;
    if (l=='w'){
        while ((x1>0)&&((board[x1-1][y1].side!=board[x][y].side))){
            x1--;
            board[x1][y1].SetCurrentHealth(board[x1][y1].GetCurrentHealth()-1);
        }
    }
    if (l=='a'){
        while ((y1>0)&&((board[x1][y1-1].side!=board[x][y].side))){
            y1--;
            board[x1][y1].SetCurrentHealth(board[x1][y1].GetCurrentHealth()-1);
        }
    }
    if (l=='s'){
        while ((x1<(nx-1))&&((board[x1+1][y1].side!=board[x][y].side))){
            x1++;
            board[x1][y1].SetCurrentHealth(board[x1][y1].GetCurrentHealth()-1);
        }
    }
    if (l=='d'){
        while ((y1<(ny-1))&&((board[x1][y1+1].side!=board[x][y].side))){
            y1++;
            board[x1][y1].SetCurrentHealth(board[x1][y1].GetCurrentHealth()-1);
        }
    }
}

void change_pos(int& x, int& y, int x1, int y1, Cell** board){
    Cell p = board[x1][y1];
    board[x1][y1] = board[x][y];
    board[x][y] = p;
    x = x1;
    y = y1;
}

void counter_attack(int x, int y, Cell** board, int nx, int ny, char l){
    double k = 0.3;
    if ((l=='w')&&(x>0)&&(board[x-1][y].IsBusy)&&(board[x-1][y].side!=board[x][y].side)){
        damage(x-1,y,board,nx,ny,'s',k);
    }
    if ((l=='a')&&(y>0)&&(board[x][y-1].IsBusy)&&(board[x][y-1].side!=board[x][y].side)){
        damage(x,y-1,board,nx,ny,'d',k);
    }
    if ((l=='s')&&(x<(nx-1))&&(board[x+1][y].IsBusy)&&(board[x+1][y].side!=board[x][y].side)){
        damage(x+1,y,board,nx,ny,'w',k);
    }
    if ((l=='d')&&(y<(ny-1))&&(board[x][y+1].IsBusy)&&(board[x][y+1].side!=board[x][y].side)){
        damage(x,y+1,board,nx,ny,'a',k);
    }
}

void evasion_pos(int& x, int& y, Cell** board, int nx, int ny, char l){
    if ((l=='w')||(l=='s')){
        if ((y>0)&&(board[x][y+1].IsBusy==0)){
            y--;
        }
        else{
            if ((y<(ny-1))&&(board[x][y-1].IsBusy==0)){
                y++;
            }
        }
    }
    if ((l=='a')||(l=='d')){
        if ((x>0)&&(board[x][y+1].IsBusy==true)){
            x--;
        }
        else{
            if ((x<(nx-1))&&((board[x][y+1].IsBusy==0))){
                x++;
            }
        }
    }
}

void death_check(Cell** board, int nx, int ny, int& kills_one, int& kills_two, std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2,std::vector<int>& y2){
    for (int i = 0; i<nx; i++){
        for (int j = 0; j<ny; j++){
            if ((board[i][j].GetCurrentHealth()<=0)&&(board[i][j].IsBusy)){
                if (board[i][j].side==1){
                    kills_one+=1;
                    for (int k = 0; k < x1.size(); k++){
                        if ((x1[k]==i)&&(y1[k]==j)){
                            x1.erase(x1.begin()+k);
                            y1.erase(y1.begin()+k);
                        }
                    }
                }
                else{
                    kills_two+=1;
                    for (int k = 0; k < x2.size(); k++){
                        if ((x2[k]==i)&&(y2[k]==j)){
                            x2.erase(x2.begin()+k);
                            y2.erase(y2.begin()+k);
                        }
                    }
                }
                board[i][j].side = 0;
                board[i][j].hero = nullptr;
                board[i][j].IsBusy = false;
            }
        }
    }
}

void board_output(Cell** board, int nx, int ny, int x1, int y1){ // 1 вид вывода доски
    std::cout << "Стороны         Здоровье        Урон            Поведение" << std::endl;
    for (int i =0; i<nx; i++){
        for (int j = 0; j<5; j++){
            std::cout << board[i][j].side << " ";
        }
        std::cout << "\t";
        for (int j =0; j<ny; j++){
            std::cout << board[i][j].GetCurrentHealth() << " ";
        }
        std::cout << "\t";
        for (int j =0; j<ny; j++){
            std::cout << board[i][j].GetDamage() << " ";
        }
        std::cout << "\t";
        for (int j =0; j<ny; j++){
            std::cout << board[i][j].GetBehaviour() << " ";
        }
        std::cout << std::endl;
    }
}

void hero_spawn(Cell** board, int nx, int ny, Hero* hero, int side, std::vector<int>& x, std::vector<int>& y){
    srand(time(NULL));
    int k = 1;
    while (k==1){
    int px = rand()%nx;
    int py = rand()%ny;
    if (board[px][py].IsBusy==0){
        k = 0;
        board[px][py].IsBusy = true;
        board[px][py].side= side;
        board[px][py].hero = hero;
        x.push_back(px);
        y.push_back(py);
    }  
    }
}
