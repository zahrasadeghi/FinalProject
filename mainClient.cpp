#include "Client.h"

using namespace std;

int main()
{
    netWars::Configuration::init();
    Client *client = new Client();
    client->start();
    return 0;
}
