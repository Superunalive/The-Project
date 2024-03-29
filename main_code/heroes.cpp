#include <heroes.h>

//an example of how it might look like
void BasicClass(Hero* hero1, Hero* hero2, bool IsAttacking){
    if (IsAttacking){ //hero1 (the Basic one) is attacking
        hero2->SetCurrentHealth(hero2->GetCurrentHealth - hero1->GetDamage);
    }
    else{ //counterattack
        hero2->SetCurrentHealth(hero2->GetCurrentHealth - hero1->GetDamage * hero1->GetModifier);
    }
}