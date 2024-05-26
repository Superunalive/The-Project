#include <iostream>
#include <limits>
#include <vector>
#include "libraries/basic_actions.h"
#include "libraries/behaviour.h"
#include "libraries/board.h"

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

    Hero Proto1; 
    Proto1.SetBehaviour(1);
    Proto1.SetMaxHealth(9);
    Proto1.SetCurrentHealth(Proto1.GetMaxHealth());
    Proto1.SetDamage(3);
    Hero Proto2; 
    Proto2.SetBehaviour(1);
    Proto2.SetMaxHealth(9);
    Proto2.SetCurrentHealth(Proto2.GetMaxHealth());
    Proto2.SetDamage(3);
    Hero Proto3; 
    Proto3.SetBehaviour(1);
    Proto3.SetMaxHealth(9);
    Proto3.SetCurrentHealth(Proto3.GetMaxHealth());
    Proto3.SetDamage(3);
    Hero Proto4; 
    Proto4.SetBehaviour(1);
    Proto4.SetMaxHealth(9);
    Proto4.SetCurrentHealth(Proto4.GetMaxHealth());
    Proto4.SetDamage(3);
    Hero Anto1; 
    Anto1.SetBehaviour(1);
    Anto1.SetMaxHealth(9);
    Anto1.SetCurrentHealth(Anto1.GetMaxHealth());
    Anto1.SetDamage(3);
    Hero Anto2; 
    Anto2.SetBehaviour(1);
    Anto2.SetMaxHealth(9);
    Anto2.SetCurrentHealth(Anto2.GetMaxHealth());
    Anto2.SetDamage(3);
    Hero Anto3; 
    Anto3.SetBehaviour(1);
    Anto3.SetMaxHealth(9);
    Anto3.SetCurrentHealth(Anto3.GetMaxHealth());
    Anto3.SetDamage(3);
    Hero Anto4; 
    Anto4.SetBehaviour(1);
    Anto4.SetMaxHealth(9);
    Anto4.SetCurrentHealth(Anto4.GetMaxHealth());
    Anto4.SetDamage(3);
    
    Cell **board = new Cell* [nx];
    for (int i =0; i < nx; i++){
        board[i] = new Cell [ny];
        for (int j = 0; j < ny; j++){
            board[i][j].hero = nullptr;
            board[i][j].IsBusy = false;
            board[i][j].special_effect = 0;
            board[i][j].side = 0;
        }
    }
    Hero * lol1 = &Proto1;
    Hero * lol2 = &Anto1;
    Hero * lol3 = &Proto2;
    Hero * lol4 = &Anto2;
    Hero * lol5 = &Proto3;
    Hero * lol6 = &Anto3;
    Hero * lol7 = &Proto4;
    Hero * lol8 = &Anto4;
    std::vector<int> x1 = {2,3,1,3};
    std::vector<int> x2 = {2,4,0,2};
    std::vector<int> y1 = {3,1,1,0};
    std::vector<int> y2 = {4,2,4,0};
    int* x = new int[8] {2,2,3,4,1,0,3,2};
    int* y = new int[8] {3,4,1,2,1,4,0,0};
    for (int i = 0; i<8; i++){
        if (i%2==0){
            board[x[i]][y[i]].IsBusy = true;
            board[x[i]][y[i]].side= 1;
        }
        else{
            board[x[i]][y[i]].IsBusy = true;
            board[x[i]][y[i]].side= 2;
        }
    }
    board[x[0]][y[0]].hero = lol1;
    board[x[1]][y[1]].hero = lol2;
    board[x[2]][y[2]].hero = lol3;
    board[x[3]][y[3]].hero = lol4;
    board[x[4]][y[4]].hero = lol5;
    board[x[5]][y[5]].hero = lol6;
    board[x[6]][y[6]].hero = lol7;
    board[x[7]][y[7]].hero = lol8;
    
    int kills_one = 0;
    int kills_two = 0;
    
    int turn = 1;
    char l = 'h';
    while (l!='q'){
        std:: cout << "Номера героев:   ";
        for (int i = 0; i<7; i+=2){
            std::cout << (i/2) << ")" << x[i] << " " << y[i] << "  ";
        }
        for (int i = 1; i<8; i+=2){
            std::cout << ((i-1)/2) << ")" << x[i] << " " << y[i] << "  ";
        }
        std::cout << std::endl;
        if ((l=='0')||(l=='1')||(l=='2')||(l=='3')){
            turn = (turn%2)+2*((int)l-48);
        }
        else{
            std::cout << std::endl;
            action::behaviour(x[turn], y[turn], board, nx, ny,l);
            action::death_check(board,nx,ny,kills_one,kills_two);
            action::board_output(board,nx,ny); // На этом моменте обновлять доску
            turn = (turn+1)%2;
        }
        std::cout<<"Сторона: "<< (turn)%2+1 << "  Выбран Герой под номером " << turn/2 << "   " << kills_one << ":"  << kills_two << std::endl;
        std::cin >> l;
        if (kills_one>=4){
            std::cout << "Победил игрок 1;  Уничтожено героев игроком 1: " << kills_one << " Уничтожено героев игроком 2: " << kills_two << std::endl;
            break;
        }
        if (kills_two>=4){
            std::cout << "Победил игрок 2;  Уничтожено героев игроком 1: " << kills_one << " Уничтожено героев игроком 2: " << kills_two << std::endl;
            break;
        }
        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } 
    

    /*
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
    gamemode2(nx, ny, type, hp);
    for (int i = 0; i<5; i++){
            delete type[i];
            delete hp[i];
        }
    delete[] type;
    delete[] hp;
    */
    return 0;
}

void gamemode1(int nx, int ny, int** type, int **hp){
    int x = 0;
    int y = 0;
    char l = 'h';
    while (l!='0')
    {   
        if (without::hpos(x,y,type)==1){
            break;
        }
        without::behaviour1(x,y,type,hp,nx,ny,l,1);
        without::death_check(type,hp);
        without::board_output(type,hp,nx,ny);
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
        without::hpos(x,y,type);
        without::hpos(x2,y2,type,2);
        if (without::hpos(x,y,type)){
            break;
        }
        if (turn==1){
            without::behaviour1(x,y,type,hp,nx,ny,l,1);
            turn = 2;
            without::death_check(type,hp);
            without::board_output(type,hp,nx,ny);
            std::cout << "Ход игрока 2:";
        }
        else {
            without::behaviour5(x2,y2,type,hp,nx,ny,l,2);
            turn = 1;
            without::death_check(type,hp);
            without::board_output(type,hp,nx,ny);
            std::cout << "Ход игрока 1:";
        }
        std::cin >> l;
        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}