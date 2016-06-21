#include <SFML/Graphics.hpp>
#include "staff/TileMap.h"
using namespace std;

int main()
{
    const float PI = 3.1415;
    netWars::Configuration::init();
    float zoomLevel = 1;
    sf::RenderWindow window(sf::VideoMode(800, 600), "TileMap Test!");
    sf::View view1 = window.getDefaultView();
    window.setView(view1);
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    sf::Event event;
    netWars::TileMap tileMap(netWars::TileMap::SAMPLE);
    sf::Sprite _cursor(netWars::Configuration::textures.get(netWars::Configuration::TexCursor));

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if(event.type == sf::Event::MouseWheelMoved)
            {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                view1.setCenter(worldPos);
                if(event.mouseWheel.delta < 0)
                {
                    view1.zoom(2.0f);
                    zoomLevel *= 2.0f;
                }
                else
                {
                    view1.zoom(0.5f);
                    zoomLevel *= 0.5f;
                }
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                std::cout <<worldPos.x <<"\t" <<worldPos.y <<"\n";
            }
            if(event.type ==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Z)
                {
                    view1.rotate(5);
                }
                if(event.key.code == sf::Keyboard::X)
                {
                    view1.rotate(-5);
                }
                if(event.key.code == sf::Keyboard::Up)
                {
                    view1.move(-10*sin(view1.getRotation()*PI/180), -10*cos(view1.getRotation()*PI/180));
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    view1.move(0, 10);
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    view1.move(-10, 0);
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    view1.move(10, 0);
                }
            }
        }
        window.setView(view1);
        _cursor.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
        window.clear();
        window.draw(tileMap);
        window.draw(_cursor);
        window.display();
    }
    return 0;
}
