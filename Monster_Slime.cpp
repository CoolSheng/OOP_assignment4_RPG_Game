#include "Monster_Slime.h"

Monster_Slime::Monster_Slime(){}
Monster_Slime::Monster_Slime(std::string name, int maxHp, int strength, int defence, int experience, int cirts, int coins){
//is that right??
    this->name=name;
    this->maxHp=maxHp;
    this->currentHp=maxHp;  //this->currentHp=maxHp;�]���쥻�S���A�n��creature�ɷ|�Ψ�currentHp
    this->strength=strength;
    this->defence=defence;
    this->cirts=cirts;
    this->coins=coins;
    this->experience=experience;
}
