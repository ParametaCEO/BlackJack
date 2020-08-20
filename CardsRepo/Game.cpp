#include "Game.h"

Game::Game()
{
    //ctor
    SetstrCommands("|exit|789 |hit|6789 |stand|89");
    gameScreen.SetstrTextTable("Blackjack>");
    gameScreen.SetstrMessage("W E L C O M E\nLet\'s play !!!");
}

Game::~Game()
{
    //dtor
}

string Game::displayScreen(string val)
{
    return gameScreen.displayScreen(val);
}

int Game::runCommand(string strCmd)
{
    int resultCode = 0;
    resultCode = strCommands.find("|"+strCmd+"|");
    switch (resultCode)
    {
        case 10 : gameScreen.SetstrMessage(strCmd + " is for request a card"); break;
        case 20: gameScreen.SetstrMessage(strCmd + " is for stop receiving cards"); break;
        case 0: gameScreen.SetstrMessage(strCmd + " is for quit the game"); break;
        default: gameScreen.SetstrMessage(strCmd + " command unknown");
    }
    return resultCode;
}
