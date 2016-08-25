#ifndef MONSTER_TROLL_H_INCLUDED
#define MONSTER_TROLL_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "Monster.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------


class Monster_Troll: public Monster{
public:
    Monster_Troll(); //I added.
    //~Monster_Troll();
    Monster_Troll(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins);
private:
};

#endif // MONSTER_TROLL_H_INCLUDED
