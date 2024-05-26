#ifndef SPELL_H
#define SPELL_H

class Spell{
    char name_[20]; //no comment
    int mana_; //mana cost
    int damage_; //how much damage. =0 deals no damage and <0 heals
    int behaviour_; //what else it does
    public:
    Spell(){
        name_ = "placeholder";
        mana_, damage_ = 0;
        behaviour_ = 1;
    }
    Spell(Spell &other){
        (*this).SetName(other.name_);
        (*this).SetMana(other.mana_);
        (*this).SetDamage(other.damage_);
        (*this).SetBehaviour(other.behaviour_);
    }
    char* GetName(){
        return name_;
    }
    int GetMana(){
        return mana_;
    }
    int GetDamage(){
        return damage_;
    }
    int GetBehaviour(){
        return behaviour_;
    }
    void SetName(const char* name){
        this->name_ = name;
    }
    void SetDamage(int damage){
        this->damage_ = damage;
    }
    void SetMana(int mana){
        this->mana_ = mana;
    }
    void SetBehaviour(int behaviour){
        this->behaviour_ = behaviour;
    }
};

//tbd - types of spells (for now - AOE damage and heal, single-target damage and heal, move hero, inflict status effect/ailment)
#endif