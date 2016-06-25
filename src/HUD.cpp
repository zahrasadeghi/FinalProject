#include "HUD.h"
#include "Configuration.h"
#include <iostream>

HUD::HUD()
{
    background = new sf::RectangleShape(sf::Vector2f(240, 92));
    background->setFillColor(sf::Color::White);
    barracksSample = new sf::Sprite(netWars::Configuration::textures.get(netWars::Configuration::TexBarracks));
}

void HUD::eventHandler(Event event)
{
    if(event.clicked)
    {
        sf::Vector2f mousePos = this->getInverseTransform().transformPoint(event.mousePos);

        std::cout <<mousePos.x <<"\t" <<mousePos.y <<"\n\n";
        if(barracksSample->getGlobalBounds().contains(mousePos))
        {
            std::cout <<"Clicked On Barracks\n";
        }
    }
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(*background, states);
    target.draw(*barracksSample, states);
}
