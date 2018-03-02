#include <iostream>  //Attention 死掉時要遊戲結束
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
//--------------------------
#include "Map.h"
#include "RpgCreature.h"
//--------------------------
#include "RpgPerson.h"
#include "RpgPerson_SwordMan.h"
#include "RpgPerson_Thief.h"
#include "RpgPerson_Magician.h"
//--------------------------
#include "Monster.h"
#include "Monster_Slime.h"
#include "Monster_Troll.h"
#include "Monster_Dragon.h"
//-------------------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-------------------------
using namespace std;

//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class SaveData{
public:
	SaveData(string name,int level,string job,int currentHp,int maxHp,
	int strength,int defence,int cirts,int coin,int experience,string mapName,int x,int y)
	{
		this->name=name;
		this->level=level;
		this->job=job;
		this->currentHp=currentHp;
		this->maxHp=maxHp;
		this->strength=strength;
		this->defence=defence;
		this->cirts=cirts;
		this->coin=coin;
		this->experience=experience;
		this->mapName=mapName;
		this->x=x;
		this->y=y;
	}
	~SaveData(){}

	string getName()
	{
		return name;
	}
	int getLevel()
	{
		return level;
	}
	string getJob()
	{
		return job;
	}
	int getCurrentHp()
	{
		return currentHp;
	}
	int getMaxHp()
	{
		return maxHp;
	}
	int getStrength()
	{
		return strength;
	}
	int getDefence()
	{
		return defence;
	}
	int getCirts()
	{
		return cirts;
	}
	int getCoin()
	{
		return coin;
	}
	int getExperience()
	{
		return experience;
	}
	string getMapName()
	{
		return mapName;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
///////////////////////////////////////////
	void setName(string name)
	{
		this->name=name;
	}
	void setLevel(int level)
	{
		this->level=level;
	}
	void setJob(string job)
	{
		this->job=job;
	}
	void setCurrentHp(int currentHp)
	{
		this->currentHp=currentHp;
	}
	void setMaxHp(int maxHp)
	{
		this->maxHp=maxHp;
	}
	void setStrength(int strength)
	{
		this->strength=strength;
	}
	void setDefence(int defence)
	{
		this->defence=defence;
	}
	void setCirts(int cirts)
	{
		this->cirts=cirts;
	}
	void setCoin(int coin)
	{
		this->coin=coin;
	}
	void setExperience(int experience)
	{
		this->experience=experience;
	}
	void setmapName(string mapName)
	{
		this->mapName=mapName;
	}
	void setX(int x)
	{
		this->x=x;
	}
	void setY(int y)
	{
		this->y=y;
	}

private:
	string name,job,mapName;
	int level,currentHp,maxHp,strength,defence,cirts,coin,experience,x,y;
};

//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


vector<string> mapData;
//void meetMonster(RpgPerson &player);
void meetMonster(RpgPerson &player, vector<Map> game_Map, int j);

int main()
{
    cout<<"-----------------------------------------"<<endl;
    cout<<"| Welcome to oop assignment4 rpg. |"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"| 1. New game                     |"<<endl;
    cout<<"| 2. Load game                    |"<<endl;
    cout<<"| 3. Exit                         |"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"Enter your choice:";

    RpgPerson *player_role; //Upcasting //Polymorphism

    //////////////////////////////////////
    /*--------------------
     Map
     --------------------*/
    int j = 0;// mapNumber
    vector<Map> game_Map; //map
    string line;
    string name,nextMapName;
    int initialPositionX,initialPositionY,width,height,order=0;
    vector<string> mapData; //string可直接用string[][]
    vector<string> monsterName;

    ifstream mapFile ("map.txt");
    while(mapFile>>name>>nextMapName>>initialPositionX>>initialPositionY>>width>>height)
    {
        string line;
        for(int i=0;i<height;i++)
        {
            mapFile >> line;
            mapData.push_back(line);
        }

        while(1)
        {
            mapFile >> line;
            if(line=="---")
            {
                break;
            }
            else
            {
                monsterName.push_back(line);
            }
        }
        game_Map.push_back(Map(name,nextMapName,initialPositionX,initialPositionY,width,height,mapData,monsterName));
        monsterName.clear();
        mapData.clear();
    }

    /////////////////////////////////////
    /////////////////////////////////////
    ////////////////////////////////////

    int mode;
    cin>>mode;
    switch(mode)
    {
        case 1:
            {
                //////////////////////////////////////
                /*--------------------
                 New player
                 --------------------*/
                //////////////////////////////////////

                //RpgPerson *player_role; //Upcasting //Polymorphism
                cout<<"Enter your name:";
                string player_name;
                cin>>player_name;

                cout<<"Enter your Job (1-3) 1.SwordMan 2.Thief 3.Magician:";
                int character; //choose character寫在RPGPerson class裡
                cin>>character;
                cout<<endl;

                switch(character)
                {
                    case 1:
                        {
                            player_role = new RpgPerson_SwordMan(player_name,1,"SwordMan",100,100,7,2,20,0,0,
                                                                game_Map[0].getinitialPositionX(),game_Map[0].getinitialPositionY());
                        }
                        break;

                    case 2:
                        {
                            player_role = new RpgPerson_Thief(player_name,1,"Thief",100,100,7,2,20,0,0,
                                                             game_Map[0].getinitialPositionX(),game_Map[0].getinitialPositionY());
                        }
                        break;

                    case 3:
                        {
                            player_role = new RpgPerson_Magician(player_name,1,"Magician",100,100,7,2,20,0,0,
                                                             game_Map[0].getinitialPositionX(),game_Map[0].getinitialPositionY());
                        }
                        break;

                    default:
                        {
                            cout<<"Wrong Input"<<endl;
                        }
                }
                j=0;
            }
            break;

        case 2:
            {
                ///////////////////////////////////////
                //---------Open importSaveFile/------//
                //////////////////////////////////////
                ifstream importSaveFile("save.txt");
                string name,job,mapName;
                int level,currentHp,maxHp,strength,defence,cirts,coin,experience,x,y;

                ///////////////////////////////////////
                //////////Reand and Print Data/////////
                ///////////////////////////////////////
                vector<SaveData> saveDatas;

                while(importSaveFile>>name>>level>>job>>currentHp>>maxHp>>strength>>defence>>cirts>>coin>>experience>>mapName>>x>>y)
                {
                    saveDatas.push_back(SaveData(name,level,job,currentHp,maxHp,strength,defence,cirts,
                                                coin,experience,mapName,x,y));

                }

                cout<<"You have "<<saveDatas.size()<<" records."<<endl;
                for(int i=0;i<saveDatas.size();i++)
                {
                    cout<<"---------------record "<<i<<" -----------------"<<endl;
                    cout<<"Name: "<<saveDatas[i].getName()<<endl;
                    cout<<"Job: "<<saveDatas[i].getJob()<<endl;
                    cout<<"Level: "<<saveDatas[i].getLevel()<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                }
                cout<<"Load record (Enter 0, 1, 2, .....)"<<endl;

                ///////////////////////////////////////
                ////////////chooseDataNumber///////////
                ///////////////////////////////////////

                while(1)
                {
                    int chooseDataNumber;
                    cin>>chooseDataNumber;
                    if(chooseDataNumber<=saveDatas.size()){
                            ///////////////////////////////////////
                            ///////////////////Job/////////////////
                            ///////////////////////////////////////
                            //need to be cout!

                            if(saveDatas[chooseDataNumber].getJob()=="SwordMan")
                            {
                                player_role = new RpgPerson_SwordMan(saveDatas[chooseDataNumber].getName(),
                                saveDatas[chooseDataNumber].getLevel(),
                                saveDatas[chooseDataNumber].getJob(),
                                saveDatas[chooseDataNumber].getCurrentHp(),
                                saveDatas[chooseDataNumber].getMaxHp(),
                                saveDatas[chooseDataNumber].getStrength(),
                                saveDatas[chooseDataNumber].getDefence(),
                                saveDatas[chooseDataNumber].getCirts(),
                                saveDatas[chooseDataNumber].getCoin(),
                                saveDatas[chooseDataNumber].getExperience(),
                                saveDatas[chooseDataNumber].getX(),
                                saveDatas[chooseDataNumber].getY());
                            }
                            else if(saveDatas[chooseDataNumber].getJob()=="Thief")
                            {
                                player_role = new RpgPerson_Thief(saveDatas[chooseDataNumber].getName(),
                                saveDatas[chooseDataNumber].getLevel(),
                                saveDatas[chooseDataNumber].getJob(),
                                saveDatas[chooseDataNumber].getCurrentHp(),
                                saveDatas[chooseDataNumber].getMaxHp(),
                                saveDatas[chooseDataNumber].getStrength(),
                                saveDatas[chooseDataNumber].getDefence(),
                                saveDatas[chooseDataNumber].getCirts(),
                                saveDatas[chooseDataNumber].getCoin(),
                                saveDatas[chooseDataNumber].getExperience(),
                                saveDatas[chooseDataNumber].getX(),
                                saveDatas[chooseDataNumber].getY());
                            }
                            else if(saveDatas[chooseDataNumber].getJob()=="Magician")
                            {
                                player_role = new RpgPerson_Magician(saveDatas[chooseDataNumber].getName(),
                                saveDatas[chooseDataNumber].getLevel(),
                                saveDatas[chooseDataNumber].getJob(),
                                saveDatas[chooseDataNumber].getCurrentHp(),
                                saveDatas[chooseDataNumber].getMaxHp(),
                                saveDatas[chooseDataNumber].getStrength(),
                                saveDatas[chooseDataNumber].getDefence(),
                                saveDatas[chooseDataNumber].getCirts(),
                                saveDatas[chooseDataNumber].getCoin(),
                                saveDatas[chooseDataNumber].getExperience(),
                                saveDatas[chooseDataNumber].getX(),
                                saveDatas[chooseDataNumber].getY());
                            }
                            else{}

                            ///////////////////////////////////////
                            ///////////////Exist Map///////////////
                            ///////////////////////////////////////

                            if(saveDatas[chooseDataNumber].getMapName()=="Omen")
                            {
                                j=0;
                            }
                            else if(saveDatas[chooseDataNumber].getMapName()=="Tinda")
                            {
                                j=1;
                            }
                            else if(saveDatas[chooseDataNumber].getMapName()=="Fongo")
                            {
                                j=2;
                            }
                            else{}
                      break;
                    }
                    else{
                        cout<<"You don't have this data"<<endl;
                    }
                }
                saveDatas.clear();
            }
            break;

        case 3:
            {
                exit(0);
            }
            break;

        default:
            {
                cout<<"Wrong Input"<<endl;
                exit(0);
            }
    }

    RpgPerson &player = *player_role; //RpgPerson player = *player_role;

    game_Map[j].addPlayer(player); //*player 是傳值進去??
    game_Map[j].printMap();


/////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------Move----------------------------------//
/////////////////////////////////////////////////////////////////////////////////////
    //int j = 0;
    while(1)
    {
        cout<<endl;
        cout<<"*****"<<endl;
        cout<<"Use w/s/a/d to move up/down/left/right."<<endl;
        cout<<"Enter i to show your status."<<endl;
        cout<<"Enter h to recover your hp (need 5 coins)."<<endl;
        cout<<"Enter save to save game."<<endl;
        cout<<"Enter exit to leave game."<<endl;
        cout<<"*****"<<endl;

        string input;
        cin>>input;
        if(input=="w")
        {
            if(game_Map[j].canMove(player.getX(),player.getY()-1)==true && (game_Map[j].getMapData(player.getX(),player.getY()-1)!='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                player.moveUp();
                game_Map[j].addPlayer(player);//#
                //meetMonster(player);
                meetMonster(player,game_Map,j);
                game_Map[j].printMap();

            }
            else if((game_Map[j].canMove(player.getX(),player.getY()-1)==true) && (game_Map[j].getMapData(player.getX(),player.getY()-1)=='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                if(game_Map[j].getNextMapName()=="Fongo"){
                    j=2;
                }
                else if(game_Map[j].getNextMapName()=="Omen"){
                    j=0;
                }
                else if(game_Map[j].getNextMapName()=="Tinda"){
                    j=1;
                }
                else{}

                player.setPosition(game_Map[j].getinitialPositionX(),game_Map[j].getinitialPositionY());
                game_Map[j].addPlayer(player);
                game_Map[j].printMap(); //wrong!
            }
            else
            {
                cout<<"Can't move up, try another direction."<<endl;
                cout<<endl;
                game_Map[j].printMap();
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        else if(input=="s")
        {
            if(game_Map[j].canMove(player.getX(), player.getY()+1)==true && (game_Map[j].getMapData(player.getX(),player.getY()+1)!='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                player.moveDown();
                game_Map[j].addPlayer(player);//加#
                //meetMonster(player);
                meetMonster(player,game_Map,j);
                game_Map[j].printMap();

            }
            else if((game_Map[j].canMove(player.getX(),player.getY()+1)==true) && (game_Map[j].getMapData(player.getX(),player.getY()+1)=='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                if(game_Map[j].getNextMapName()=="Fongo"){
                    j=2;
                }
                else if(game_Map[j].getNextMapName()=="Omen"){
                    j=0;
                }
                else if(game_Map[j].getNextMapName()=="Tinda"){
                    j=1;
                }
                else{}
                player.setPosition(game_Map[j].getinitialPositionX(),game_Map[j].getinitialPositionY());
                game_Map[j].addPlayer(player);
                game_Map[j].printMap();
            }
            else
            {
                cout<<"Can't move down, try another direction."<<endl;
                cout<<endl;
                game_Map[j].printMap();
            }
        }
        /////////////////////////////////////////////////////////////////////////////
        else if(input=="a")
        {
            if(game_Map[j].canMove(player.getX()-1, player.getY())==true && (game_Map[j].getMapData(player.getX()-1,player.getY())!='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                player.moveLeft();
                game_Map[j].addPlayer(player);//加#
                //meetMonster(player);
                meetMonster(player,game_Map,j);
                game_Map[j].printMap();

            }
            else if((game_Map[j].canMove(player.getX()-1,player.getY())==true) && (game_Map[j].getMapData(player.getX()-1,player.getY())=='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                if(game_Map[j].getNextMapName()=="Fongo"){
                    j=2;
                }
                else if(game_Map[j].getNextMapName()=="Omen"){
                    j=0;
                }
                else if(game_Map[j].getNextMapName()=="Tinda"){
                    j=1;
                }
                else{}
                player.setPosition(game_Map[j].getinitialPositionX(),game_Map[j].getinitialPositionY());
                game_Map[j].addPlayer(player);
                game_Map[j].printMap();
            }
            else
            {
                cout<<"Can't move left, try another direction."<<endl;
                cout<<endl;
                game_Map[j].printMap();
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////
        else if(input=="d")
        {
            if(game_Map[j].canMove(player.getX()+1, player.getY())==true && (game_Map[j].getMapData(player.getX()+1,player.getY())!='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                player.moveRight();
                game_Map[j].addPlayer(player);//加#
                //meetMonster(player);
                meetMonster(player,game_Map,j);
                game_Map[j].printMap();

            }
            else if((game_Map[j].canMove(player.getX()+1,player.getY())==true) && (game_Map[j].getMapData(player.getX()+1,player.getY())=='@'))
            {
                game_Map[j].removePlayer(player);//刪#
                if(game_Map[j].getNextMapName()=="Fongo"){
                    j=2;
                }
                else if(game_Map[j].getNextMapName()=="Omen"){
                    j=0;
                }
                else if(game_Map[j].getNextMapName()=="Tinda"){
                    j=1;
                }
                else{}
                player.setPosition(game_Map[j].getinitialPositionX(),game_Map[j].getinitialPositionY());
                game_Map[j].addPlayer(player);
                game_Map[j].printMap();
            }
            else
            {
                cout<<"Can't move Right, try another direction."<<endl;
                cout<<endl;
                game_Map[j].printMap();
            }
        }

        ///////////////////////////////////////////////////////////////////////////
        else if(input=="i")
        {
            player.printStatus();
            cout<<"Map:"<<game_Map[j].getName()<<endl;
        }
        ///////////////////////////////////////////////////////////////////////////
        else if(input=="h")
        {
            cout<<"Use 5 coins to recover your hp. (yes/no)"<<endl;
            string input;
            cin>>input;
            if(input=="yes")
            {
                if(player.RpgCreature::getCoins()<5)
                {
                    cout<<"You don't have enough coins. "<<"("<<player.RpgCreature::getCoins()<<"/5)"<<endl;
                }
                else
                {
                    player.RpgCreature::reduceCoins();
                    player.RpgCreature::recoverHp();
                }
            }
            else if(input=="no"){}
            else{}
        }
        ///////////////////////////////////////////////////////////////////////////
        else if(input=="save")
        {
            //--------------------Read Data--------------------------//
            fstream importSaveFile("save.txt",ios::in|ios::app);
            string name,job,mapName;
            int level,currentHp,maxHp,strength,defence,cirts,coin,experience,x,y;
            vector<SaveData> saveDatas;

            while(importSaveFile>>name>>level>>job>>currentHp>>maxHp>>strength>>defence>>cirts>>coin>>experience>>mapName>>x>>y)
            {
                saveDatas.push_back(SaveData(name,level,job,currentHp,maxHp,strength,defence,cirts,coin,experience,mapName,x,y));
                //cout<<name<<level<<job<<currentHp<<maxHp<<strength<<defence<<cirts<<coin<<experience<<mapName<<x<<y<<endl;
            }
            importSaveFile.close();

            //---------------------show choice----------------------//
            cout<<"You have "<<saveDatas.size()<<" records."<<endl;
            for(int i=0;i<saveDatas.size();i++)
            {
                cout<<"---------------record "<<i<<" -----------------"<<endl;
                cout<<"Name: "<<saveDatas[i].getName()<<endl;
                cout<<"Job: "<<saveDatas[i].getJob()<<endl;
                cout<<"Level: "<<saveDatas[i].getLevel()<<endl;
                cout<<"-----------------------------------------------"<<endl;
            }
            cout<<"Load record (Enter 0, 1, 2, .....)"<<endl;

            //--------------------Change/Overwrite Data--------------------------//
            int record;
            cin>>record;
            //--------------------------Overwrite Data--------------------------//
            if(record<saveDatas.size())
            {
                cout<<"Overwrite record "<<record<<" ? (yes/no)"<<endl;
                string yes_or_no;
                cin>>yes_or_no;

                if(yes_or_no=="yes")
                {
                    fstream exportFile("save.txt",ios::out|ios::trunc);
                    saveDatas[record].setName(player.getName());
                    saveDatas[record].setLevel(player.getLevel());
                    saveDatas[record].setJob(player.getJob());
                    saveDatas[record].setCurrentHp(player.getCurrentHp());
                    saveDatas[record].setMaxHp(player.getMaxHp());
                    saveDatas[record].setStrength(player.getStrength());
                    saveDatas[record].setDefence(player.getDefence());
                    saveDatas[record].setCirts(player.getCrits());
                    saveDatas[record].setCoin(player.getCoins());
                    saveDatas[record].setExperience(player.getExperience());
                    saveDatas[record].setmapName(game_Map[j].getName());
                    saveDatas[record].setX(player.getX());
                    saveDatas[record].setY(player.getY());


                    for(int i=0;i<saveDatas.size();i++)
                    {
                        exportFile<<saveDatas[i].getName()<<endl;
                        exportFile<<saveDatas[i].getLevel()<<endl;
                        exportFile<<saveDatas[i].getJob()<<endl;
                        exportFile<<saveDatas[i].getCurrentHp()<<endl;
                        exportFile<<saveDatas[i].getMaxHp()<<endl;
                        exportFile<<saveDatas[i].getStrength()<<endl;
                        exportFile<<saveDatas[i].getDefence()<<endl;
                        exportFile<<saveDatas[i].getCirts()<<endl;
                        exportFile<<saveDatas[i].getCoin()<<endl;
                        exportFile<<saveDatas[i].getMapName()<<endl;
                        exportFile<<saveDatas[i].getExperience()<<endl;
                        exportFile<<saveDatas[i].getX()<<endl;
                        exportFile<<saveDatas[i].getY()<<endl;
                    }
                    exportFile.close();
                }
                else{}
            }

            //--------------------Add Data--------------------------//
            else
            {
                fstream exportFile("save.txt",ios::out|ios::app);
                exportFile<<name<<endl;
                exportFile<<level<<endl;
                exportFile<<job<<endl;
                exportFile<<currentHp<<endl;
                exportFile<<maxHp<<endl;
                exportFile<<strength<<endl;
                exportFile<<defence<<endl;
                exportFile<<cirts<<endl;
                exportFile<<coin<<endl;
                exportFile<<experience<<endl;
                exportFile<<mapName<<endl;
                exportFile<<x<<endl;
                exportFile<<y<<endl;
                exportFile.close();
            }
            saveDatas.clear();
        }
        ///////////////////////////////////////////////////////////////////////////
        else if(input=="exit")
        {
            break;
        }
        ///////////////////////////////////////////////////////////////////////////
        else
        {
            cout<<"Wrong input"<<endl;
            cout<<endl;
            game_Map[j].printMap();

        }

    }
    return 0;
}

//meetMonster移到副程式//
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////Encounter a monster////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//void meetMonster(RpgPerson &player){
void meetMonster(RpgPerson &player,vector<Map> game_Map,int j){   //monster name

        int meet_monster_prabobility;
        /* initialize random seed: */
        srand (time(NULL));

        /* generate secret number between 1 and 4: */
        meet_monster_prabobility = rand() % 4 + 1;

        if(meet_monster_prabobility == 1)
        {
            /////////////////////////////////////////////////////
            Monster *chooseMonster;

            if(game_Map[j].randomMonster()== "Slime")//"Slime" //problem: game_Map[j].randomMonster()
            {
                chooseMonster = new Monster_Slime("Slime", 30, 10, 3, 2, 20, 1);
            }
            else if(game_Map[j].randomMonster()== "Troll") //"Troll"
            {
                chooseMonster = new Monster_Troll("Troll", 35, 20, 5, 10, 35, 5);
            }
            else if(game_Map[j].randomMonster()== "Dragon") //"Dragon"
            {
                chooseMonster = new Monster_Dragon("Dragon", 150, 20, 30, 25, 1, 15);
            }
            else{}
            Monster &monster = *chooseMonster;

            cout<<"########"<<monster.RpgCreature::getName()<<"######"<<endl;////////////////////////////////
            cout<<"########"<<monster.RpgCreature::getCoins()<<"######"<<endl;////////////////////////////////
            cout<<"########"<<monster.RpgCreature::getExperience()<<"######"<<endl;////////////////////////////////

            //I can use chooseMonster but I have to use monster->getName()
            /////////////////////////////////////////////////////////

            //Monster monster;
            //monster=Monster("Slime",30,10,3,20);
            ////Monster monster("Slime",20,6,3);  //和上面兩行有何不同?Ask!

            cout<<endl;
            cout<<"You meet a "<<monster.RpgCreature::getName()<<"!!! The fight starts!!!"<<endl;
            cout<<endl;

            bool is_Effective_Input=false;
            do{
                string attack_skill_escape;
                cout<<"------------------------------"<<endl;
                cout<<"Enter '1' to attack, '2' to use skill, '3' to escape."<<endl;
                cout<<"------------------------------"<<endl;
                cin>>attack_skill_escape;
                if(attack_skill_escape=="1")
                {
                    is_Effective_Input=true;

                    //////////////////////////////
                    //player attack monster///////
                    /////////////////////////////
                    player.attack(monster);
                    if(monster.RpgCreature::isDead()== true)
                    {
                        //int value;
                        //srand (time(NULL));
                        //value = rand() % 2 + 1;
                        player.raiseExperience(monster.RpgCreature::getExperience());
                        player.raiseCoin(monster.RpgCreature::getCoins());

                        cout<<"You beat "<<monster.RpgCreature::getName()<<" ,got "
                        <<monster.RpgCreature::getExperience()<<" exp."<<endl;
                        if(player.checkLevelUp()==true)
                        {
                            player.levelUp();
                            player.statusUp();
                            cout<<"Level up!!! You are level ";
                            cout<<player.getLevel()<<endl;
                        }
                        else{}

                        //player.RpgCreature::recoverHp();
                        //cout<<"Hp recovered."<<endl;
                        cout<<endl;

                        break;
                    }
                    else
                    {
                        cout<<monster.RpgCreature::getName()<<"'s hp:"<<" "
                        <<monster.RpgCreature::getCurrentHp()<<endl;
                    }


                    //////////////////////////////
                    //monster attack player///////
                    /////////////////////////////
                    monster.attack(player);
                    if(player.RpgCreature::isDead()== true)
                    {
                        int value;
                        srand (time(NULL));
                        value = rand() % 2 + 1;
                        //player.raiseExperience(value);
                        player.decreaseExperience(value);

                        cout<<"Your hero is dead. Lost "<<value<<" exp."<<endl;

                        player.RpgCreature::recoverHp();
                        cout<<"Hp recovered."<<endl;
                        cout<<endl;

                        break;
                    }
                    else
                    {
                        cout<<player.RpgCreature::getName()<<"'s hp:"<<" "
                        <<player.RpgCreature::getCurrentHp()<<endl;
                    }
                }





                else if(attack_skill_escape=="2")
                {
                    is_Effective_Input=true;

                    //////////////////////////////
                    //player Choose Skills////////
                    /////////////////////////////
                    player.printfSkill();
                    cout<<"Choose Skill:";
                    bool is_input_right=true;
                    do{
                        int choose;
                        cin>>choose;
                        if(player.checkSkill(choose,player)==true)
                        {
                            switch(choose)
                            {
                                case 1:
                                    {
                                        player.attackSkill(monster);
                                    }
                                    break;

                                case 2:
                                    {
                                        player.healSkill(player);
                                    }
                                    break;

                                case 3:
                                    {
                                        player.speacialSkill(monster);
                                    }
                                    break;

                                default: //It's won't be excute Think!!!
                                    {
                                        cout<<"Have no this choose"<<endl;
                                        cout<<"Choose another one:";
                                        is_input_right=false;
                                    }
                            }
                            is_input_right=true;
                        }
                        else
                        {
                            cout<<"Cannot use this skill! Your Level is too low"<<endl;
                            cout<<"Choose another one:";
                            is_input_right=false;
                        }
                    }while(is_input_right==false);


                    //////////////Judge monster_isDead()
                    //////////////
                    if(monster.RpgCreature::isDead()== true)
                    {
                        //int value;
                        //srand (time(NULL));
                        //value = rand() % 2 + 1;
                        player.raiseExperience(monster.RpgCreature::getExperience());
                        player.raiseCoin(monster.RpgCreature::getCoins());

                        cout<<"You beat "<<monster.RpgCreature::getName()<<" ,got "
                        <<monster.RpgCreature::getExperience()<<" exp."<<endl;
                        if(player.checkLevelUp()==true)
                        {
                            player.levelUp();
                            player.statusUp();
                            cout<<"Level up!!! You are level ";
                            cout<<player.getLevel()<<endl;
                        }
                        else{}

                        //player.RpgCreature::recoverHp();
                        //cout<<"Hp recovered."<<endl;
                        cout<<endl;

                        break;
                    }
                    else
                    {
                        cout<<monster.RpgCreature::getName()<<"'s hp:"<<" "
                        <<monster.RpgCreature::getCurrentHp()<<endl;
                    }

                    //////////////////////////////
                    //monster attack player///////
                    /////////////////////////////
                    monster.attack(player);
                    if(player.RpgCreature::isDead()== true)
                    {
                        int value;
                        srand (time(NULL));
                        value = rand() % 2 + 1;
                        //player.raiseExperience(value);
                        player.decreaseExperience(value);
                        cout<<"Your hero is dead."<<" Lost "<<value<<" exp."<<endl;

                        player.RpgCreature::recoverHp();
                        cout<<"Hp recovered."<<endl;
                        cout<<endl;

                        break;
                    }
                    else
                    {
                        cout<<player.RpgCreature::getName()<<"'s hp:"<<" "
                        <<player.RpgCreature::getCurrentHp()<<endl;
                    }

                }


                /////////////////////////////
                //////Escape/////////////////
                /////////////////////////////

                else if(attack_skill_escape=="3")
                {
                    is_Effective_Input=true;

                    int escape_prabobility;
                    srand (time(NULL));
                    meet_monster_prabobility = rand() % 3 + 1;
                    if(meet_monster_prabobility == 1)
                    {
                        cout<<"You successfully escaped from the fight!"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Escape failed!!!"<<endl;

                        //////////////////////////////
                        //Monster attack player///////
                        /////////////////////////////
                        monster.attack(player);
                        if(player.RpgCreature::isDead()== true)
                        {
                            int value;
                            srand (time(NULL));
                            value = rand() % 2 + 1;
                            //player.raiseExperience(value);
                            player.decreaseExperience(value);
                            cout<<"Your hero is dead."<<" Lost "<<value<<" exp."<<endl;

                            player.RpgCreature::recoverHp();
                            cout<<"Hp recovered."<<endl;
                            cout<<endl;

                            break;
                        }
                        else
                        {
                            cout<<player.RpgCreature::getName()<<"'s hp:"<<" "
                            <<player.RpgCreature::getCurrentHp()<<endl;
                        }
                    }
                }


                else
                {
                    cout<<"Wrong Input"<<endl;
                    is_Effective_Input=true;
                }
            }while(is_Effective_Input==true);
        }
        else{}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

