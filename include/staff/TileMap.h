#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

#include <iostream>

#include "Cell.h"

namespace netWars
{

class TileMap : public sf::Drawable
{
    std::vector< std::vector<Cell*> > hexs;
public:
    enum MAPS : int {SAMPLE};
    TileMap(MAPS mapName, int radious=71);
    ~TileMap();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif // TILEMAP_H_INCLUDED
