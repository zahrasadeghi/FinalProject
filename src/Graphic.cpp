#include "Graphic.h"

Graphic::Graphic()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "NetWars");
    window->setFramerateLimit(30);
    isOpen = true;
}

void Graphic::start()
{

}

void Graphic::main()
{
    eventHandler();

    drawObjects();
}

Event Graphic::getEvent()
{
    Event tmp;
    eventQmutex.lock();
    if(!eventQ.empty())
    {
        tmp = eventQ.front();
        eventQ.pop();
    }
    eventQmutex.unlock();

    return tmp;
}

void Graphic::eventHandler()
{
    sf::Event event;
    Event output;
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            isOpen = false;
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        output.clicked = true;
    }
    output.mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));


    if(lastEvent != output)
    {
        eventQmutex.lock();
        eventQ.push(output);
        eventQmutex.unlock();
        lastEvent = output;
    }
}

void Graphic::draw(sf::Drawable* object)
{
    objects.push_back(object);
}

void Graphic::drawObjects()
{
    window->clear();
    for(auto obj : objects)
    {
        window->draw(*obj);
    }
    window->display();
}
