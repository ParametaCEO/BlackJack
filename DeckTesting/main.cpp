
//============================================================================
// Name        : TestingDeck
// Author      : Jorge Cifuentes
// Version     :
// Copyright   : Copyleft
//============================================================================

#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

int main() {
    Deck frenchDeck;
    Hand playerHand;
    frenchDeck.setShuffled();

    playerHand.pushCard(frenchDeck.getTopCard()); //First Hit
    playerHand.pushCard(frenchDeck.getTopCard()); //Second Hit
    if(playerHand.isBlackjack())
        cout << "Blackjack!!! Viva las Vegas!!!" << endl;
    cout << "Hand Value is...\n" << playerHand.getValue() << endl;

/*
	do{
		c = frenchDeck.getTopCard();
		c.show();
		cout << c.getStrCard() << endl; // prints card by card
		c = spainDeck.getTopCard();
		c.show();
		cout << c.getStrCard() << endl; // prints card by card

	}while(spainDeck.getSizeDeck());*/
	return 0;
}



