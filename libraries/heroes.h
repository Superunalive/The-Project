#ifndef HERO_H
#define HERO_H
#include <cstring>
#include <iostream>
#include <fstream>
class Hero {
    char *name_;
    int chealth_;
    int mhealth_;
    int damage_; //name, this and health are self-explanatory. c means current, m means maximum
    int mana_suck_; //placeholder name, how much mana player receives for dealing damage with this hero
    int behaviour_; //corresponds to an ability function
    
    public:

    Hero();
    Hero(Hero &other);
    
    char* GetName();
    int GetCurrentHealth();
    int GetMaxHealth();
    int GetDamage();
    int GetManaSuck();
    int GetBehaviour();

    void Set(char *name, int health, int damage, int mana_suck, int behaviour, int modifier);
    void SetName(char *name);
    void SetCurrentHealth(int health);
    void SetMaxHealth(int health);
    void SetDamage(int damage);
    void SetManaSuck(int mana_suck);
    void SetBehaviour(int behaviour);
    
    ~Hero();

    friend void behaviour(int& x, int& y, Cell** board, int nx, int ny, char l,int& kills_one = nullptr, int& kills_two = nullptr, std::vector<int>& x1 = nullptr,std::vector<int>& y1 = nullptr,std::vector<int>& x2 = nullptr, std::vector<int>& y2 = nullptr);
    Hero &operator=(Hero & other);
    friend std::ifstream &operator>>(std::ifstream&, Hero&);
};
class Basic : public Hero{
    public:
    using Hero::Hero:
    behaviour (int& x, int& y, Cell** board, int nx, int ny, char l) {
        int x1 = x;
        int y1 = y;
        step_pos(x1,y1,type,hp,nx,ny,l,dm);
        change_pos(x,y,x1,y1,type,hp);
        damage(x1,y1,type,hp,nx,ny,l,3);
        counter_attack(x1,y1,type,hp,nx,ny,l);
    }
}
class Strikethrough : public Hero{
    public:
    using Hero::Hero:
    behaviour (int& x, int& y, Cell** board, int nx, int ny, char l) {
        int x1 = x;
        int y1 = y;
        step_pos(x1,y1,type,hp,nx,ny,l,dm);
        change_pos(x,y,x1,y1,type,hp);
        //pierce_damage(x1,y1,type,hp,nx,ny,l);
        counter_attack(x1,y1,type,hp,nx,ny,l);
    }
}
class Dodging : public Hero{
    public:
    using Hero::Hero:
    behaviour (int& x, int& y, Cell** board, int nx, int ny, char l,int& kills_one, int& kills_two,std::vector<int>& x1,std::vector<int>& y1,std::vector<int>& x2, std::vector<int>& y2) {
        int x1 = x;
        int y1 = y;
        step_pos(x1,y1,type,hp,nx,ny,l,turn);
        change_pos(x,y,x1,y1,type,hp);
        damage(x1,y1,type,hp,nx,ny,l,3);
        int x2 = x1;
        int y2 = y1;
        evasion_pos(x2,y2,type,hp,nx,ny,l,turn); 
        change_pos(x1,y1,x2,y2,type,hp);
        counter_attack(x1,y1,type,hp,nx,ny,l);
    }
}
#endif