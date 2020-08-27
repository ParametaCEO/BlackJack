
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
    Deck spainDeck(Deck(true,true));
	Card c;

    frenchDeck = spainDeck;

	do{
		c = frenchDeck.getTopCard();
		c.show();
		cout << c.getStrCard() << endl; // prints card by card
		c = spainDeck.getTopCard();
		c.show();
		cout << c.getStrCard() << endl; // prints card by card

	}while(spainDeck.getSizeDeck());
	return 0;
}

