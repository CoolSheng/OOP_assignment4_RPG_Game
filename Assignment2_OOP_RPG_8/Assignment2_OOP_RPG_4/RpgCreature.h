#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED
#include <iostream>
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

using namespace std;

class RpgCreature{
public:
    RpgCreature();
    RpgCreature(std::string name);
    RpgCreature(std::string name, int maxHp, int strength, int defence,int cirts,int coin,int experience);
    std::string getName();
    int getMaxHp();
    int getCurrentHp();
    int getStrength();
    int getDefence();
    bool isDead();
    void loseHp(int losehp);
    void recoverHp();
    void attack(RpgCreature& enemy);
    int getCrits();//add cirts
    int getExperience();
    void changeStrength(int point);
    void changeDefence(int point);
    void changeCirts(int point);

    void reduceCoins();
    void decreaseCoins();
    int getCoins();

protected:
    std::string name;
    int maxHp;
    int currentHp;
    int strength;
    int defence;
    int cirts;// add cirts
    int coins;
    int experience;
};

#endif // RPGCREATURE_H_INCLUDED
