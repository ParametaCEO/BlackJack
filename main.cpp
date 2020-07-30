
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

using namespace std;

int main() {
    Player jack(100);
    Player johnnie(jack);
    Dealer crupier;
    unsigned int betPool;

    cout << "My wallet has " << jack.GetChips() << endl;
    betPool = jack.putBet(10);
    cout << "I bet " << betPool << endl;
    cout << "Now my wallet has " << jack.GetChips() << endl;

    crupier.ShuffleDeck();
    crupier.HitPlayer(&jack);
    crupier.HitPlayer(&jack);

    if(jack.GetHandValue()>=17){ jack.SetStand(true);}


    cout << "My hand is:\n" << jack.showHand() << endl;

    if(jack.HasBlackjack())
    {
        cout << "I got Blackjack!!!\n" << endl;
        jack.SetStand(true);
    }
    cout << "I have: " << jack.GetHandValue() << endl;

    crupier.HitPlayer(&crupier);
    crupier.HitPlayer(&crupier);

    if(crupier.GetHandValue()>=17){ crupier.SetStand(true);}

    cout << "Dealer hand is:\n" << crupier.showHand() << endl;

    if(crupier.HasBlackjack())
    {
        cout << "Dealer Blackjack!!!\n" << endl;
        crupier.SetStand(true);
    }
    cout << "Dealer has: " << crupier.GetHandValue() << endl;

    while(!jack.GetStand())
    {
        crupier.HitPlayer(&jack);
        if(jack.GetHandValue()>=17)
        {
            jack.SetStand(true);
        }
    }
    cout << "My hand is:\n" << jack.showHand() << endl;
    cout << "I have: " << jack.GetHandValue() << endl;

    while(!crupier.GetStand())
    {
        crupier.HitPlayer(&crupier);
        if(crupier.GetHandValue()>=17)
        {
            crupier.SetStand(true);
        }
    }
    cout << "Dealer hand is:\n" << crupier.showHand() << endl;
    cout << "Dealer has: " << crupier.GetHandValue() << endl;

    jack.DidWin(crupier.GetHandValue());
    if(jack.HasWin())
    {
        cout << "I win!!!\n" << endl;
        betPool += crupier.putBet(betPool);
        jack.getBet(betPool);
        cout << "Now my wallet has " << jack.GetChips() << endl;
    }
    else
    {
        cout << "I loose." << endl;
        crupier.getBet(betPool);
        betPool = 0;
    }

	return 0;
}

