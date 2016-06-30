#include "Soldier.h"

Soldier :: Soldier(Cell loc):location(loc),life(10),strength(5),size(0),moving(0),fight(0),upDown(0),leftRight(0),deg(0){
    x=((sf::Vector2f)loc).x;
    y=((sf::Vector2f)loc).y;
}
/* void Soldier:: setWay(vector w){
 way=w;
 size=w.length();
 }*/
void Soldier:: move(){
    static int i=1,x0=x,y0=y;
    moving=1;
    if(size!=0)
    {
        if(x!=((sf::Vector2f)way[i]).x)
        {
            float m=(y0-((sf::Vector2f)way[i]).y)/(x0-((sf::Vector2f)way[i]).x);
            deg=atan(m);
            if(((sf::Vector2f)way[i]).x>x){
                x+=1;
                leftRight=1;
            }
            else{
                x-=1;
                leftRight=0;
            }
            if(((sf::Vector2f)way[i]).y>y)
                upDown=0;
            else
                leftRight=1;
            y=m*(x-((sf::Vector2f)way[i]).x)+((sf::Vector2f)way[i]).y;
        }
        if(x==((sf::Vector2f)way[i]).x){
            x0=((sf::Vector2f)way[i]).x;
            y0=((sf::Vector2f)way[i]).y;
            i++;
        }
    }
    if(i==size)
    {
        i=0;
        size=0;
        moving=0;
    }
}
void Soldier:: attack(Cell dest,Soldier* enemy){
    move();
    if(x==((sf::Vector2f)dest).x && y==((sf::Vector2f)dest).y)
    {
        fight=1;
        life-=enemy->strength;
        enemy->life-=strength;
    }
}