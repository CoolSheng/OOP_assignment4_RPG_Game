#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class Monster: public RpgCreature{
public:
    Monster(); //I added.
    //~Monster();
    Monster(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins);
private:
};

#endif // MONSTER_H_INCLUDED
