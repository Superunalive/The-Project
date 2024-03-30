#include "../libraries/heroes.h"
struct Cell{
    Hero* hero; //nullptr = no hero. Walls are also heroes
    bool IsBusy; //can someone stand on/go through this cell
    int special_effect;
};