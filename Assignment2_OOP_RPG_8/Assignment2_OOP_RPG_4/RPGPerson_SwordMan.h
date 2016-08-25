#ifndef SWORDMAN_H_INCLUDED
#define SWORDMAN_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "RpgPerson.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class RpgPerson_SwordMan: public RpgPerson{
public:
    RpgPerson_SwordMan();
    RpgPerson_SwordMan(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
                        int cirts,int coins,int experience, int x, int y); //add cirts

    //void statusUp(); //add cirts (SwordMan)
    /////////////////////////////////////////////I add  (Could I use function? Don't implement in Class?)
    void statusUp();
    void speacialSkill(RpgCreature& monster);
    void printfSkill();

};

#endif // SWORDMAN_H_INCLUDED
