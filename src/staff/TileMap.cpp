#include "staff/TileMap.h"

namespace netWars
{

TileMap::TileMap(MAPS mapName, int radious)
{
    float y=0;
    for(int i=0;i<13;i++)
    {
        float x = (i%2 ? 0 : 1) * r * radious;
        std::vector<Cell*> tmp;
        if(i%2)
            tmp.push_back(nullptr);
        for(int j=0;j<13;j++)
        {
            std::string str = (std::to_string(i)+","+std::to_string(j));
            tmp.push_back( new Cell(Cell::Grass, radious, str) );
            tmp.back()->setPosition(x,y);
            tmp.push_back(nullptr);
            x += 2 * r * radious;
        }
        hexs.push_back(tmp);
        y += (1+h) * radious;
    }
    hexs[5][5]=nullptr;
    hexs[5][6]=nullptr;

    if(mapName == TileMap::SAMPLE)
    {

    }

}


TileMap::~TileMap()
{
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            delete hexs[i][j];
        }
    }
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned int i=0;i<hexs.size();i++)
    {
        for(unsigned int j=0;j<hexs[i].size();j++)
        {
            if(hexs[i][j] != nullptr)
            {
                target.draw(*hexs[i][j]);
            }
        }
    }
}

}
