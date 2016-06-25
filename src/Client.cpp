#include "Client.h"

Client::Client()
{
    graphic = new Graphic();
    PlayerID = 0;

    tileMap = new netWars::TileMap(netWars::TileMap::SAMPLE);
    graphic->draw(tileMap);

    hud = new HUD;
    hud->setPosition(0, 600-92);
    graphic->draw(hud);
}

void Client::start()
{
    graphic->start();
    sf::Thread eThread(Client::eventHander, this);
    eThread.launch();

    this->main();

    eThread.wait();
}

void Client::main()
{
    while(graphic->isOpen)
    {
        graphic->main();
    }
}

void Client::eventHander()
{
    while(graphic->isOpen)
    {
        Event event = graphic->getEvent();

        hud->eventHandler(event);
        //player[PlayerID]->eventHandler(event);
    }
}
