#ifndef SOLDIER_H
#define SOLDIER_H
#include "Cell.h"
using namespace netWars;
class Soldier
{
public:
    HexPosition location;
    int life;
    int strength;
    std::vector <HexPosition> way;
    int size;
    bool moving;
    bool fight;
    bool upDown;
    bool leftRight;
    int x;
    int y;
    int deg;
    Soldier (HexPosition loc);
    //void setWay(vector <HexPosition> w);
    void move();
    void attack(HexPosition dest,Soldier* enemy);
protected:
private:
};

#endif // SOLDIER_H