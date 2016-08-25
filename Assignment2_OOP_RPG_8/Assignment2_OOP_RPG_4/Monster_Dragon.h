#ifndef MONSTER_DRAGON_H_INCLUDED
#define MONSTER_DRAGON_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "Monster.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class Monster_Dragon: public Monster{
public:
    Monster_Dragon(); //I added.
    //~Monster_Dragon();
    Monster_Dragon(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins);
private:
};

#endif // MONSTER_DRAGON_H_INCLUDED
