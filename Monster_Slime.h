#ifndef MONSTER_SLIME_H_INCLUDED
#define MONSTER_SLIME_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "Monster.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class Monster_Slime: public Monster{
public:
    Monster_Slime(); //I added.
    //~Monster_Slime();
    Monster_Slime(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins);
private:
};

#endif // MONSTER_SLIME_H_INCLUDED
