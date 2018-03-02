#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED

#include "RpgCreature.h"
//----------------------
#include <vector>
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------


class RpgPerson: public RpgCreature{
public:
    RpgPerson();
    RpgPerson(std::string name, int maxHp, int strength, int defence, int cirts,int coins,
              int experience, int x, int y);
    int getX();
    int getY();
    void setPosition(int x, int y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void raiseExperience(int experience);
    void decreaseExperience(int experience);
    void raiseCoin(int coins);

    bool checkLevelUp();
    void levelUp();
    int getLevel();

    virtual void statusUp(){};//or use statusUp()=0; // I change?? is okay?              //Statusup()加入cirts up!-->移到各個角色中 (haven't done)
    void printStatus();
    string getJob(); //I add

    void attackSkill(RpgCreature& monster);
    void healSkill(RpgPerson& player); //
    virtual void speacialSkill(RpgCreature& monster){};
    virtual void printfSkill(){};
    bool checkSkill(int choose,RpgPerson& player);


//private:
protected://change private:-->protected:
    int level;
    //int experience;
    int x;
    int y;
    //int value;
    string job;// I add
};

#endif // RPGPERSON_H_INCLUDED
