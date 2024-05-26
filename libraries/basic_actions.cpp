#include <iostream>
#include "basic_actions.h"
#include <ctime>


// type - таблица сторон объектов; hp - таблица здоровья

namespace without {
int hpos(int& x, int& y, int** type, int lol1){ // где находится персонаж с классом 1
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            if (type[i][j] == lol1){
                x = i;
                y = j;
                return 0;
            }
        }
    }
    return 1;
}

int hpos(int& x, int& y, int** type){ // где находится персонаж с классом 1
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

void damage(int x, int y, int** type, int** hp, int nx, int ny, char l, int dm){ // нанесение урона объект в (x,y); 
    if ((l=='w')&&(x>0)&&(type[x-1][y]!=0)){
        hp[x-1][y]-=dm;
    }
    if ((l=='a')&&(y>0)&&(type[x][y-1]!=0)){
        hp[x][y-1]-=dm;
    }
    if ((l=='s')&&(x<4)&&(type[x+1][y]!=0)){
        hp[x+1][y]-=dm;
    }
    if ((l=='d')&&(y<4)&&(type[x][y+1]!=0)){
        hp[x][y+1]-=dm;
    }
    
}

void step_pos(int& x1, int& y1, int** type, int** hp, int nx, int ny, char l, int turn){
    if (l=='w'){
        while ((x1>0)&&((type[x1-1][y1]==0)||(type[x1-1][y1]==turn))){
            x1--;
        }
    }
    if (l=='a'){
        while ((y1>0)&&((type[x1][y1-1]==0)||(type[x1][y1-1]==turn))){
            y1--;
        }
    }
    if (l=='s'){
        while ((x1<(nx-1))&&((type[x1+1][y1]==0)||(type[x1+1][y1]==turn))){
            x1++;
        }
    }
    if (l=='d'){
        while ((y1<(ny-1))&&((type[x1][y1+1]==0)||(type[x1][y1+1]==turn))){
            y1++;
        }
    }
}

void evasion_pos(int& x1, int& y1, int** type, int** hp, int nx, int ny, char l, int turn){
    if ((l=='w')||(l=='s')){
        if (((y1>0)&&((type[x1][y1-1]==0)||(type[x1][y1-1]==turn)))){
            y1--;
        }
        else{
            if ((y1<(ny-1))&&((type[x1][y1+1]==0)||(type[x1][y1+1]==turn))){
                y1++;
            }
        }
    }
    if ((l=='a')||(l=='d')){
        if ((x1>0)&&((type[x1-1][y1]==0)||(type[x1-1][y1]==turn))){
            x1--;
        }
        else{
            if ((x1<(nx-1))&&((type[x1+1][y1]==0)||(type[x1+1][y1]==turn))){
                x1++;
            }
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
        damage(x-1,y,type,hp,nx,ny,'s',1);
    }
    if ((l=='a')&&(y>0)&&(type[x][y-1]!=0)){
        damage(x,y-1,type,hp,nx,ny,'d',1);
    }
    if ((l=='s')&&(x<(nx-1))&&(type[x+1][y]!=0)){
        damage(x+1,y,type,hp,nx,ny,'w',1);
    }
    if ((l=='d')&&(y<(ny-1))&&(type[x][y+1]!=0)){
        damage(x,y+1,type,hp,nx,ny,'a',1);
    }
}

void death_check(int** type, int** hp){
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            if (hp[i][j]<=0){
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
}

namespace action{

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

void change_pos(int& x, int& y, int x1, int y1, Cell** board){
    // пока нет присваивания не работает
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

void death_check(Cell** board, int nx, int ny, int& kills_one, int& kills_two, std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2,std::vector<int>& y2){
    for (int i = 0; i<nx; i++){
        for (int j = 0; j<ny; j++){
            if ((board[i][j].GetCurrentHealth()<=0)&&(board[i][j].IsBusy)){
                if (board[i][j].side==1){
                    kills_one+=1;
                    for (int k = 0; k < x1.size(); k++){
                        if ((x1[i]==i)&&(y1[i]==j)){
                            x1.erase(x1.begin()+i);
                            y1.erase(y1.begin()+i);
                        }
                    }
                }
                else{
                    kills_two+=1;
                    for (int k = 0; k < x2.size(); k++){
                        if ((x2[i]==i)&&(y2[i]==j)){
                            x2.erase(x2.begin()+i);
                            y2.erase(y2.begin()+i);
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

void board_output(Cell** board, int nx, int ny){ // 1 вид вывода доски
    for (int i =0; i<nx; i++){
        for (int j = 0; j<5; j++){
            std::cout << board[i][j].side << " ";
        }
        std::cout << "\t";
        for (int j =0; j<ny; j++){
            std::cout << board[i][j].GetCurrentHealth() << " ";
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
}