#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <queue>

#include "staff/Event.h"

class Graphic
{
    sf::RenderWindow *window;
    sf::View view;
    std::queue<Event> eventQ;
    Event lastEvent;
    sf::Mutex eventQmutex;
    std::vector<sf::Drawable*> objects;
public:
    bool isOpen;
private:
    void eventHandler();
    void drawObjects();
public:
    Graphic();
    void start();
    void main();
    Event getEvent();
    void draw(sf::Drawable* object);
};

#endif // GRAPHIC_H_INCLUDED
