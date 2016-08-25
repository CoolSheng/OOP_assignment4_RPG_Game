#include "Monster.h"



Monster::Monster(){}
Monster::Monster(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins){
//is that right??
    this->name=name;
    this->maxHp=maxHp;
    this->currentHp=maxHp;  //this->currentHp=maxHp;因為原本沒有，要用creature時會用到currentHp
    this->strength=strength;
    this->defence=defence;
    this->cirts=cirts;
    this->coins=coins;
    this->experience=experience;
}
