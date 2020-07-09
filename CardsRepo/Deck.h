/*
 * Deck.h
 *
 *  Created on: 11/06/2020
 *      Author: Jorge Cifuentes
 */

#ifndef DECK_H_
#define DECK_H_

#include <list>
#include "Card.h"

using namespace std;


class Deck {
public:
	Deck(bool bArgFull=true, bool bArgJokers=false);
	virtual ~Deck();
	Deck(const Deck& other);
	Deck(Deck &&other);
	Deck& operator=(const Deck& other);
	Deck& operator=(Deck &&other);
	Card getTopCard();
	void pushCard(Card crd);
	int getSizeDeck();
	void setShuffled();

	//Getters & Setters
	void setbJokers(bool argJokers);
	bool getbJokers();
	void setbFullDeck(bool argFullDeck);
	bool getbFullDeck();
	void setSizeDeck(int argSize);

private:
	bool bJokers;
	bool bFullDeck;
	list<Card> cards;
	int iSizeDeck;

	void fillDeck(bool bArgJokers);
};

class Hand : public Deck {
	public:
		Hand();
		int getValue();
		bool isBlackjack();
		void operator=(Hand other);


	private:
		int iValue;
		bool bBlackjack;
};

#endif /* DECK_H_ */