
//============================================================================
// Name        : BlackJack Main
// Author      : Jorge Cifuentes
// Version     :
// Copyright   : Copyleft
//============================================================================

#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "player.h"
#include "Round.h"
#include "Screen.h"

using namespace std;

int main() {
    Player jack(100);
    Player johnnie(jack);
    Dealer crupier;
    Round onlyRound;
    Screen gameScreen("BlackJack: Action>");
    string responseCmd;

    responseCmd = gameScreen.displayScreen("My wallet has 100 - Enter any command to bet 10");
    onlyRound.SetiPot(jack.putBet(10));
    responseCmd = gameScreen.displayScreen("I bet 10");

    crupier.ShuffleDeck();
    crupier.HitPlayer(&jack);
    crupier.HitPlayer(&crupier);
    crupier.HitPlayer(&jack);
    crupier.HitPlayer(&crupier);

    gameScreen.SetstrMessage("Delaer Hand is: " + crupier.showHand());
    if(jack.HasBlackjack())
    {
        responseCmd = gameScreen.displayScreen("I got Blackjack!!! " + jack.showHand());
        jack.SetStand(true);
    }
    else
    {
        responseCmd = gameScreen.displayScreen("I have " + jack.showHand());
    }

    do
    {
        if(responseCmd == "stand")
        {
            jack.SetStand(true);
        }
        else if(responseCmd == "hit")
        {
            crupier.HitPlayer(&jack);
            responseCmd = gameScreen.displayScreen("Now I have " + jack.showHand());
        }
        else
        {
            responseCmd = gameScreen.displayScreen("Action not recognized, please try again");
        }
    }while(responseCmd != "stand");


    if(crupier.GetHandValue()>=17){ crupier.SetStand(true);}

    cout << "Dealer hand is:\n" << crupier.showHand() << endl;

    if(crupier.HasBlackjack())
    {
        cout << "Dealer Blackjack!!!\n" << endl;
        crupier.SetStand(true);
    }
    cout << "Dealer has: " << crupier.GetHandValue() << endl;


    while(!crupier.GetStand())
    {
        crupier.HitPlayer(&crupier);
        if(crupier.GetHandValue()>=17)
        {
            crupier.SetStand(true);
        }
    }


    onlyRound.SetbPush(jack.GetStand() && crupier.GetStand());

    jack.DidWin(crupier.GetHandValue());
    if(jack.HasWin())
    {
        responseCmd = gameScreen.displayScreen("I win!!! " + jack.showHand());;
        onlyRound.SetiPot(onlyRound.GetiPot() + crupier.putBet(onlyRound.GetiPot()));
        jack.getBet(onlyRound.GetiPot());
    }
    else
    {
        responseCmd = gameScreen.displayScreen("I loose " + jack.showHand());
        crupier.getBet(onlyRound.GetiPot());
        onlyRound.SetiPot(0);
    }

	return 0;
}

