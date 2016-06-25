#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "staff/Event.h"

class HUD : public sf::Drawable, public sf::Transformable
{
    sf::Sprite *barracksSample;
    sf::RectangleShape *background;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    HUD();
    void eventHandler(Event);
};

#endif // HUD_H_INCLUDED
