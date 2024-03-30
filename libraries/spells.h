
class Spell{
    char name_[20]; //no comment
    int mana_; //mana cost
    int damage_; //how much damage. =0 deals no damage and <0 heals
    int behaviour_; //what else it does
    public:
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