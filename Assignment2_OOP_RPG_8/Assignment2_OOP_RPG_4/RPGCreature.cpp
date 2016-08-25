#include "RpgCreature.h"
//-----------------------
#include "Map.h"
//-----------------------


RpgCreature::RpgCreature(){

}
RpgCreature::RpgCreature(std::string name){
    this->name = name;
}
RpgCreature::RpgCreature(std::string name, int maxHp, int strength, int defence,int cirts,int coin,int experience){
    this->name = name;
    this->maxHp = maxHp;
    this->strength = strength;
    this->defence = defence;
    this->cirts = cirts; //每種職業不一樣 (初始值20)
    this->coins = coins;
    this->experience = experience;
}
std::string RpgCreature::getName(){
    return this->name;
}
int RpgCreature::getMaxHp(){
    return this->maxHp;
}
int RpgCreature::getCurrentHp(){
    return this->currentHp;
}
int RpgCreature::getStrength(){
    return this->strength;
}
int RpgCreature::getDefence(){
    return this->defence;
}
int RpgCreature::getCrits(){
    return this->cirts;
}
void RpgCreature::changeStrength(int point){
    this->strength = point;
}
void RpgCreature::changeDefence(int point){
    this->defence = point;
}
void RpgCreature::changeCirts(int point){
    this->cirts = point;
}
bool RpgCreature::isDead(){
    if(currentHp <= 0)
    {
        return true;
    }
    else return false;
}
void RpgCreature::loseHp(int losehp){
    this->currentHp -= losehp;
}
void RpgCreature::recoverHp(){
    this->currentHp = maxHp;
}
void RpgCreature::attack(RpgCreature& enemy){
    //think and check!//

    /* initialize random seed: */
    srand (time(NULL));
    int drift_damage;

    /* generate secret number between -3 and 3: */
    drift_damage = rand() % 6 - 3;

    int losehp;
    losehp=this->strength-enemy.getDefence()+drift_damage;
    cout<<name<<" "<<"attack, caused"<<" "<<losehp<<" "<<"damages!"<<endl;

    if(enemy.getDefence()>=(losehp))
    {
        enemy.loseHp(1);
    }
    else
    {
        double chance_of_cirts,sample;
        sample=rand();
        chance_of_cirts=(sample+cirts)/sample;

        if(chance_of_cirts>=1)
        {
            enemy.loseHp(losehp);
        }
        else
        {
            enemy.loseHp(losehp*2);
        }
    }
}

void RpgCreature::reduceCoins(){
    this->coins=this->coins-5;
}
int RpgCreature::getCoins(){
    return this->coins;
}

int RpgCreature::getExperience(){
    return this->experience;
}
