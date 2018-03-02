#ifndef Magician_H_INCLUDED
#define Magician_H_INCLUDED

//----------------------------------
#include "RpgCreature.h"
#include "RpgPerson.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

class RpgPerson_Magician: public RpgPerson{
public:
    RpgPerson_Magician();
    RpgPerson_Magician(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
                        int cirts,int coins,int experience, int x, int y); //add cirts


    //void statusUp(); //add cirts (Magician)
    //////////////////////////////////////I add (Could I use function? Don't implement in Class?)
    void statusUp();
    virtual void speacialSkill(RpgCreature& monster);
    virtual void printfSkill();


};




#endif // Magician_H_INCLUDED
