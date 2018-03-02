#include "RpgPerson_SwordMan.h"

RpgPerson_SwordMan::RpgPerson_SwordMan(){}
RpgPerson_SwordMan::RpgPerson_SwordMan(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
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
    this->job="SwordMan"; // I add
}

void RpgPerson_SwordMan::statusUp(){
    this->maxHp=this->maxHp+5; //Hp+5
    this->strength=this->strength+1; //Strength+1
    this->defence=this->defence+2; //defence+2
    this->cirts=this->cirts+0; //cirts+0
}

void RpgPerson_SwordMan::speacialSkill(RpgCreature& monster){
    int point;
    if(monster.getDefence()<=0){
        monster.changeDefence(0);
    }
    else{
        point=monster.getDefence()-rand()%2;
        monster.changeDefence(point);
    }
}

void RpgPerson_SwordMan::printfSkill(){
    cout<<"<1>"<<"attack_skill:"<<"Everytime, Monster will lose 50% Hp."<<endl;
    cout<<"<2>"<<"heal_skill:"<<"Everytime, Player will recover 80% Hp of losing hp."<<endl;
    cout<<"<3>"<<"speacial_skill:"<<"Everytime, Monster's defence will be decreased:0~2 "<<endl;
}


//void RpgPerson_SwordMan::setJob(){ // I add
//    this->Job="SwordMan";
//}
