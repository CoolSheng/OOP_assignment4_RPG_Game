#include "Map.h"

//--------------------------
//--------------------------

Map::Map(){}
Map::Map(std::string name, std::string nextMapName, int initialPositionX, int initialPositionY, int width,
         int height, std::vector<std::string> mapData, std::vector<std::string>monsterName){
    this->name = name;
    this->nextMapName = nextMapName;
    this->initialPositionX = initialPositionX;
    this->initialPositionY = initialPositionY;
    this->width = width;
    this->height = height;
    this->mapData = mapData;
    this->monsterName = monsterName;

    for(int i=0; i<mapData.size();i++)
        for(int j=0; j<mapData[i].size();j++)
            if(mapData[i][j] == '0')
                this->mapData[i][j] = ' ';

}
Map::~Map(){}
std::string Map::getName(){
    return this->name;
}
std::string Map::getNextMapName(){
    return this->nextMapName;
}
int Map::getWidth(){
    return this->width;
}
int Map::getHeight(){
    return this-> height;
}
int Map::getinitialPositionX(){
    return this-> initialPositionX;
}
int Map::getinitialPositionY(){
    return this-> initialPositionY;
}
char Map::getMapData(int x, int y){
    return this->mapData[y][x];
}
bool Map::canMove(int x, int y){
    if(0 <= y && y <= height-1 && 0 <= x && x <= width-1){  //<height-1;< width-1
        if(mapData[y][x] == '1')
            return false;
        else
            return true;
    }
    else
        return false;

}
void Map::printMap(){

    for(int i=0;i<mapData.size();i++)
    {
        cout << mapData[i] <<endl;
    }

}
void Map::addPlayer(RpgPerson& player){
    mapData[player.getY()][player.getX()] = '#';
}
void Map::removePlayer(RpgPerson& player){
    mapData[player.getY()][player.getX()] = ' ';
}
std::string Map::randomMonster(){
    return monsterName[rand()%(this->monsterName.size())];

}
