#include "RpgPerson.h"
//------------------------
#include "Map.h"
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//------------------------


RpgPerson::RpgPerson(){}
RpgPerson::RpgPerson(std::string name, int maxHp, int strength, int defence, int cirts,int coins,
                     int experience, int x, int y){
    this->name=name;
    this->maxHp=maxHp;
    this->currentHp=maxHp; //this->currentHp=maxHp;因為原本沒有，要用creature時會用到currentHp
    this->strength=strength;
    this->defence=defence;
    this->x=x;
    this->y=y;
    this->cirts = cirts;
    this->coins = coins;
    this->experience = experience;
    //this->experience=0;
    //this->experience=0; //I add
    //this->level=3; //I add coz there is 1 in .h.
    //this->cirts=20; //每種職業不一樣 (初始值20)
    //為什麼要寫成  this->name=name;等...因為初始值才能直接設定
}

int RpgPerson::getX(){
    return this->x;
}
int RpgPerson::getY(){
    return this->y;
}
void RpgPerson::setPosition(int x, int y){
    this->x=x;
    this->y=y;
}
void RpgPerson::moveUp(){
    this->y=this->y-1;
}

void RpgPerson::moveDown(){
    this->y=this->y+1;
}

void RpgPerson::moveLeft(){
    this->x=this->x-1;
}
void RpgPerson::moveRight(){
    this->x=x+1;
}
void RpgPerson::raiseExperience(int experience){
    this->experience= this->experience+experience;
}
void RpgPerson::raiseCoin(int coins){
    this->coins= this->coins+coins;
}
void RpgPerson::decreaseExperience(int experience){
    if(((this->experience)-experience) <= 0)
    {
        this->experience=0;
    }
    else
    {
        this->experience=(this->experience)-experience;
    }

}
bool RpgPerson::checkLevelUp(){
    if(experience>7*(0.5+level/2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void RpgPerson::levelUp(){
    this->experience=this->experience%level;
    this->level=this->level+1;//提升一級
}
int RpgPerson::getLevel(){
    return this->level;
}
//void RpgPerson::statusUp(){  //Abstract??  -->"player.statusup()" called this one
//    this->maxHp=this->maxHp+5; //Hp+5
//    this->strength=this->strength+1; //Strength+1
//    this->defence=this->defence+1; //defence+1
//}

string RpgPerson::getJob(){ // I add
    return this->job;
}

void RpgPerson::printStatus(){
    cout<<"Name:"<<name<<endl;
    cout<<"LV:"<<getLevel()<<endl;
    cout<<"Job:"<<job<<endl;
    cout<<"Hp:"<<currentHp<<"/"<<maxHp<<endl;
    cout<<"Strength:"<<strength<<endl;
    cout<<"Defence:"<<defence<<endl;
    cout<<"Crits:"<<cirts<<endl;
    cout<<"Coins:"<<coins<<endl;
    cout<<"Exp:"<<experience<<"/"<<7*(0.5+level/2)<<endl;
    //cout<<"Map:"<<Map::getName()<<endl;
}

void RpgPerson::attackSkill(RpgCreature& monster){
    int losehp;
    losehp = monster.getCurrentHp()/2;
    monster.loseHp(losehp); //Is this okay? class Creature method is used here?
}

void RpgPerson::healSkill(RpgPerson& player)
{
    player.currentHp = player.currentHp+(player.getMaxHp() - player.currentHp)*8/10; //player.currentHp is okay?
    if(player.currentHp>=getMaxHp())
    {
        this->currentHp=player.getMaxHp();
    }
    else
    {
        this->currentHp = player.currentHp;
    }
}

bool RpgPerson::checkSkill(int choose,RpgPerson& player){

    if(choose==1 && player.getLevel()>=1)
    {
        return true;
    }
    else if(choose==2 && player.getLevel()>=2)
    {
        return true;
    }
    else if(choose==3 && player.getLevel()>=3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
