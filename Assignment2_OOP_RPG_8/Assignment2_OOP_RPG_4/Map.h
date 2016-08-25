#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <vector>
#include "RpgPerson.h"
//----------------------------
#include<string>
//-----------------<Random>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//-----------------

using namespace std;

class Map{
public:
    Map();
    Map(std::string name, std::string nextMapName, int initialPositionX, int initialPositionY, int width,
        int height,std::vector<std::string> mapData, std::vector<std::string>monsterName);
    ~Map();
    std::string getName();
    std::string getNextMapName();
    int getWidth();
    int getHeight();
    int getinitialPositionX();
    int getinitialPositionY();
    char getMapData(int x, int y);
    bool canMove(int x, int y);
    void printMap(); //check
    void addPlayer(RpgPerson& player);
    void removePlayer(RpgPerson& player);
    string randomMonster();
private:
    std::string name;
    std::string nextMapName;
    int width;
    int height;
    int initialPositionX;
    int initialPositionY;
    std::vector<std::string> mapData;
    RpgPerson* player;
    std::vector<std::string> monsterName;
};

#endif // MAP_H_INCLUDED
