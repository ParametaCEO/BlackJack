#include "Game.h"

Game::Game()
{
    //ctor
    SetstrCommands("|exit|789 |hit|6789 |stand|89 |bet|6789 |play|789");
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
        case 10 : if(gameRound.GetbDrawed())
                    playRound(2);
                else
                    gameScreen.SetstrMessage(strCmd + " is not allowed, you must start a round first using \"play\" command");
            break;
        case 20: if(gameRound.GetbDrawed())
                    playRound(3);
                else
                    gameScreen.SetstrMessage(strCmd + " is not allowed, you must start a round first using \"play\" command");
            break;
        case 30: playRound(0); break;
        case 40: if(gameRound.GetiPot()==0)
                    gameScreen.SetstrMessage(strCmd + " is not allowed, you must bet first using \"bet\" command");
                else if(!gameRound.GetbDrawed())
                    playRound(1);
                else
                    gameScreen.SetstrMessage(strCmd + " is not allowed, a round is in progress");
            break;
        case 0: gameScreen.SetstrMessage(strCmd + " is for quit the game"); break;
        default: gameScreen.SetstrMessage(strCmd + " command unknown");
    }
    return resultCode;
}

void Game::playRound(unsigned int iStage)
{
    switch(iStage)
    {
        case 0:
            gameRound.SetiPot(playerOne.putBet(10));
            gameScreen.SetstrMessage("PLACING YOUR BET $10");
            gameScreen.displayScreen("hit enter...");
            iStage++;
        //FIX PLAY AND BET BAHAVIOR break;

        case 1:
            cruppier.ShuffleDeck();
            cruppier.HitPlayer(&playerOne);
            cruppier.HitPlayer(&cruppier);
            cruppier.HitPlayer(&playerOne);
            cruppier.HitPlayer(&cruppier);
            gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand());
            gameRound.SetbDrawed(true);
        break;

        case 2:
            cruppier.HitPlayer(&playerOne);
            gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand());
            if(playerOne.GetHandValue()>21)
            {
                gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand() + "\nYOU LOOSE");
                gameRound.SetbFullStand(true);
                gameRound.SetbDrawed(false);
                playerOne.throwHand();
                cruppier.throwHand();
                cruppier.ResetDeck();
            }
        break;

        case 3:
            playerOne.SetStand(true);
            while(cruppier.GetHandValue()<17)
            {
                cruppier.HitPlayer(&cruppier);
            }

            if(cruppier.GetHandValue()>21)
            {
                gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand() + "\nYOU WIN");
            }
            else
            {
                if(playerOne.DidPush(cruppier.GetHandValue()))
                    gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand() + "\nPUSH");
                else if(playerOne.DidWin(cruppier.GetHandValue()))
                    gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand() + "\nYOU WIN");
                else
                    gameScreen.SetstrMessage("Dealer hand: " + cruppier.showHand() + "\nPlayer hand: " + playerOne.showHand() + "\nYOU LOOSE");
            }
            gameRound.SetbFullStand(true);
            gameRound.SetbDrawed(false);
            playerOne.throwHand();
            cruppier.throwHand();
            cruppier.ResetDeck();
        break;
    }
}
