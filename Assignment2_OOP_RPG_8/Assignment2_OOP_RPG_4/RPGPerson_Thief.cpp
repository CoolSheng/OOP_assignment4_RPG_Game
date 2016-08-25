#include "RpgPerson_Thief.h"

RpgPerson_Thief::RpgPerson_Thief(){}
RpgPerson_Thief::RpgPerson_Thief(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
                        int cirts,int coins,int experience, int x, int y){
    this->name=name;
    this->maxHp=maxHp;
    this->currentHp=maxHp;
    this->strength=strength;
    this->defence=defence;
    this->x=x;
    this->y=y;
    this->experience=experience;
    this->coins=coins;
    this->level=level;
    this->cirts=cirts; //每種職業不一樣 (初始值20)
    this->job="Thief"; // I add
}

void RpgPerson_Thief::statusUp(){
    this->maxHp=this->maxHp+5; //Hp+5
    this->strength=this->strength+1; //Strength+1
    this->defence=this->defence+1; //defence+1
    this->cirts=this->cirts+5; //cirts+5
}

void RpgPerson_Thief::speacialSkill(RpgCreature& monster){
    int point;
    if(monster.getStrength()<=0){
        monster.changeStrength(0);
    }
    else{
        point=monster.getStrength()-rand()%5;
        monster.changeStrength(point);
    }
}

void RpgPerson_Thief::printfSkill(){
    cout<<"<1>"<<"attack_skill:"<<"Everytime, Monster will lose 50% Hp."<<endl;
    cout<<"<2>"<<"heal_skill:"<<"Everytime, Player will recover 80% Hp of losing hp."<<endl;
    cout<<"<3>"<<"speacial_skill:"<<"Everytime, Monster's strength will be decreased:0~5"<<endl;
}

//void RpgPerson_Thief::setJob(){ // I add
//    this->Job="Thief";
//}
