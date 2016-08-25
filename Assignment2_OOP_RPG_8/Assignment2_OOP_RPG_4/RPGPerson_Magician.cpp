#include "RpgPerson_Magician.h"

RpgPerson_Magician::RpgPerson_Magician(){}
RpgPerson_Magician::RpgPerson_Magician(std::string name, int level, string job,int currentHp, int maxHp, int strength, int defence,
                        int cirts,int coins,int experience, int x, int y){
    this->name=name;
    this->maxHp=maxHp;
    this->currentHp=maxHp;
    this->strength=strength;
    this->defence=defence;
    this->x=x;
    this->y=y;
    this->experience=experience;
    this->level=level;
    this->coins=coins;
    this->cirts=cirts; //每種職業不一樣 (初始值20)
    this->job="Magician"; // I add
}

void RpgPerson_Magician::statusUp(){  //+virtual才可以!!!!!!!!!!!!!
    this->maxHp=this->maxHp+5; //Hp+5
    this->strength=this->strength+2; //Strength+2
    this->defence=this->defence+1; //defence+1
    this->cirts=this->cirts+0; //cirts+0
}

void RpgPerson_Magician::speacialSkill(RpgCreature& monster){ //how to programming would be better(won't change this->defence)
    int point;
    if(monster.getCrits()<=0){
        monster.changeCirts(0);
    }
    else{
        point=monster.getCrits()-rand()%10;
        monster.changeCirts(point);
    }

}

void RpgPerson_Magician::printfSkill(){
    cout<<"<1>"<<"attack_skill:"<<"Everytime, Monster will lose 50% Hp."<<endl;
    cout<<"<2>"<<"heal_skill:"<<"Everytime, Player will recover 80% Hp of losing hp."<<endl;
    cout<<"<3>"<<"speacial_skill:"<<"Everytime, Monster's cirts will be decreased:0~9 "<<endl;
}

//void RpgPerson_Magician::setJob(){ // I add
//    this->Job="Magician";
//}
