#ifndef THIEF_H_INCLUDED
#define THIEF_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "RpgPerson.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class RpgPerson_Thief: public RpgPerson{
public:
    RpgPerson_Thief();
    RpgPerson_Thief(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
                        int cirts,int coins,int experience, int x, int y);//add cirts

    //void statusUp(); //add cirts (Thief)
    /////////////////////////////////////////I add (Could I use function? Don't implement in Class?)
    void statusUp();
    void speacialSkill(RpgCreature& monster);
    void printfSkill();
};


#endif // THIEF_H_INCLUDED
