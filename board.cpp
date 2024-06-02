#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include "libraries/basic_actions.h"
#include "libraries/behaviour.h"
#include "libraries/board.h"
#include "libraries/colors.h"
#include "libraries/basic_actions.cpp"
#include "libraries/behaviour.cpp"

Colors color;

void tileoutput(Cell** board, int x, int y, int n, int x1, int y1){ // n - строки от 0 до 5
    if (board[x][y].IsBusy){
        if (board[x][y].side==2){
            color.set_color(CL_RED);
            if ((x==x1)&&(y==y1)){
                color.set_color(CL_YELLOW);
            }
        }
        else{
            color.set_color(CL_BLUE);
            if ((x==x1)&&(y==y1)){
                color.set_color(CL_GREEN);
            }
        }
        std::cout << std::left << std::fixed;
        if ((n==0)||(n==5)){
            if (board[x][y].GetBehaviour()==1){ std::cout << "^^^^^^^^^^^";}
            if (board[x][y].GetBehaviour()==2){ std::cout << "@@@@@@@@@@@";}
            if (board[x][y].GetBehaviour()==3){ std::cout << "&&&&&&&&&&&";}
            if (board[x][y].GetBehaviour()==4){ std::cout << "$$$$$$$$$$$";}
            if (board[x][y].GetBehaviour()==5){ std::cout << "***********";}
            if (board[x][y].GetBehaviour()==6){ std::cout << "!!!!!!!!!!!";}
        }
        if ((n==1)||(n==4)){
            if (board[x][y].GetBehaviour()==1){ std::cout << "^^       ^^";}
            if (board[x][y].GetBehaviour()==2){ std::cout << "@@       @@";}
            if (board[x][y].GetBehaviour()==3){ std::cout << "&&       &&";}
            if (board[x][y].GetBehaviour()==4){ std::cout << "$$       $$";}
            if (board[x][y].GetBehaviour()==5){ std::cout << "**       **";}
            if (board[x][y].GetBehaviour()==6){ std::cout << "!!       !!";}
        }
        if (n==2){
            if (board[x][y].GetBehaviour()==1){ std::cout << "^^ H " << std::setw(4) << board[x][y].GetCurrentHealth() << "^^";}
            if (board[x][y].GetBehaviour()==2){ std::cout << "@@ H " << std::setw(4) << board[x][y].GetCurrentHealth() << "@@";}
            if (board[x][y].GetBehaviour()==3){ std::cout << "&& H " << std::setw(4) << board[x][y].GetCurrentHealth() << "&&";}
            if (board[x][y].GetBehaviour()==4){ std::cout << "$$ H " << std::setw(4) << board[x][y].GetCurrentHealth() << "$$";}
            if (board[x][y].GetBehaviour()==5){ std::cout << "^^ H " << std::setw(4) << board[x][y].GetCurrentHealth() << "^^";}
            if (board[x][y].GetBehaviour()==6){ std::cout << "^^ H " << std::setw(4) << board[x][y].GetCurrentHealth() << "^^";}
        }
        if (n==3){
            if (board[x][y].GetBehaviour()==1){ std::cout << "^^ D " << std::setw(4) << board[x][y].GetDamage() << "^^";}
            if (board[x][y].GetBehaviour()==2){ std::cout << "@@ D " << std::setw(4) << board[x][y].GetDamage() << "@@";}
            if (board[x][y].GetBehaviour()==3){ std::cout << "&& D " << std::setw(4) << board[x][y].GetDamage() << "&&";}
            if (board[x][y].GetBehaviour()==4){ std::cout << "$$ D " << std::setw(4) << board[x][y].GetDamage() << "$$";}
            if (board[x][y].GetBehaviour()==5){ std::cout << "** D " << std::setw(4) << board[x][y].GetDamage() << "**";}
            if (board[x][y].GetBehaviour()==6){ std::cout << "!! D " << std::setw(4) << board[x][y].GetDamage() << "!!";}
        }
        std::cout << "\t";
        color.clear();
    }
    else{
        std::cout << "00000000000\t";
    }
}

void board_output2(Cell** board, int nx, int ny, int x1, int y1){ // 1 вид вывода доски
    for (int i =0; i<nx; i++){
        for (int k =0; k<=ny; k++){
            for (int j = 0; j<5; j++){
                tileoutput(board, i, j, k, x1, y1);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        if (i<nx-1){
            std::cout << std::endl;
        }
    }
}



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
    Proto1.SetBehaviour(3);
    Proto1.SetMaxHealth(8);
    Proto1.SetCurrentHealth(Proto1.GetMaxHealth());
    Proto1.SetDamage(5);
    Hero Proto2; 
    Proto2.SetBehaviour(3);
    Proto2.SetMaxHealth(8);
    Proto2.SetCurrentHealth(Proto2.GetMaxHealth());
    Proto2.SetDamage(1);
    Hero Proto3; 
    Proto3.SetBehaviour(1);
    Proto3.SetMaxHealth(9);
    Proto3.SetCurrentHealth(Proto3.GetMaxHealth());
    Proto3.SetDamage(2);
    Hero Proto4; 
    Proto4.SetBehaviour(1);
    Proto4.SetMaxHealth(9);
    Proto4.SetCurrentHealth(Proto4.GetMaxHealth());
    Proto4.SetDamage(3);
    Hero Anto1; 
    Anto1.SetBehaviour(5);
    Anto1.SetMaxHealth(5);
    Anto1.SetCurrentHealth(Anto1.GetMaxHealth());
    Anto1.SetDamage(4);
    Hero Anto2; 
    Anto2.SetBehaviour(5);
    Anto2.SetMaxHealth(6);
    Anto2.SetCurrentHealth(Anto2.GetMaxHealth());
    Anto2.SetDamage(3);
    Hero Anto3; 
    Anto3.SetBehaviour(5);
    Anto3.SetMaxHealth(7);
    Anto3.SetCurrentHealth(Anto3.GetMaxHealth());
    Anto3.SetDamage(2);
    Hero Anto4; 
    Anto4.SetBehaviour(1);
    Anto4.SetMaxHealth(8);
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
    std::vector<int> x1 = {};
    std::vector<int> x2 = {};
    std::vector<int> y1 = {};
    std::vector<int> y2 = {};
    action::hero_spawn(board, nx, ny, lol1 , 1, x1, y1);
    action::hero_spawn(board, nx, ny, lol2 , 2, x2, y2);
    action::hero_spawn(board, nx, ny, lol3 , 1, x1, y1);
    action::hero_spawn(board, nx, ny, lol4 , 2, x2, y2);
    action::hero_spawn(board, nx, ny, lol5 , 1, x1, y1);
    action::hero_spawn(board, nx, ny, lol6 , 2, x2, y2);
    action::hero_spawn(board, nx, ny, lol7 , 1, x1, y1);
    action::hero_spawn(board, nx, ny, lol8 , 2, x2, y2);
    /*
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
    */
    int kills_one = 0;
    int kills_two = 0;
    
    int turn = 1;
    int side = 2;
    char l = 'h';
    while (l!='q'){
        std::cout << x1.size();
        std:: cout << "Номера героев:   ";
        for (int i = 0; i<x1.size(); i+=1){
            std::cout << i << ")" << x1[i] << " " << y1[i] << "  ";
        }
        for (int i = 0; i<x2.size(); i+=1){
            std::cout << i << ")" << x2[i] << " " << y2[i] << "  ";
        }
        std::cout << std::endl;
        if ((l=='0')||(l=='1')||(l=='2')||(l=='3')){
            turn = (int)l-48;
        }
        else{
            if (side==1){
                action::behaviour(x1[turn], y1[turn], board, nx, ny,l,kills_one,kills_two,x1,y1,x2,y2);
                action::death_check(board,nx,ny,kills_one,kills_two,x1,y1,x2,y2);
                //action::board_output(board,nx,ny,x2[turn],y2[turn]); // На этом моменте обновлять доску
                side = 2;
            }
            else {
                action::behaviour(x2[turn], y2[turn], board, nx, ny,l,kills_one,kills_two,x1,y1,x2,y2);
                action::death_check(board,nx,ny,kills_one,kills_two,x1,y1,x2,y2);
                //action::board_output(board,nx,ny,x2[turn],y2[turn]); // На этом моменте обновлять доску

                side = 1;
            }
            turn = 0;
            
        }
        if (side==1){
            board_output2(board,nx,ny,x1[turn],y1[turn]); // На этом моменте обновлять доску
            std::cout<<"Сторона: "<< (side)%2+1 << "  Выбран Герой под номером " << turn << "  Счёт: " << kills_one << ":"  << kills_two << std::endl;
        }
        else{
            board_output2(board,nx,ny,x2[turn],y2[turn]); // На этом моменте обновлять доску
            std::cout<<"Сторона: "<< (side)%2+1 << "  Выбран Герой под номером " << turn << "  Счёт: " << kills_one << ":"  << kills_two << std::endl;
        }
        
        std::cin >> l;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        if (kills_one>=4){
            board_output2(board,nx,ny,x2[turn],y2[turn]); // На этом моменте обновлять доску
            std::cout << "Победил игрок 1;  Уничтожено героев игроком 1: " << kills_one << " Уничтожено героев игроком 2: " << kills_two << std::endl;
            break;
        }
        if (kills_two>=4){
            board_output2(board,nx,ny,x2[turn],y2[turn]); // На этом моменте обновлять доску
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