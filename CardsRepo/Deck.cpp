/*
 * Deck.cpp
 *
 *  Created on: 11/06/2020
 *      Author: Jorge Cifuentes
 * Version: 20200626A
 */

#include "Card.h"
#include "Deck.h"
#include <list>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
//#include <bits/stdc++.h> // shuffle

using namespace std;


Deck::Deck(bool bArgFull, bool bArgJokers)
{
	bJokers = bArgJokers;
	bFullDeck = bArgFull;
	iSizeDeck = 0;

	if(bArgFull){
		fillDeck(bArgJokers);
	}
}

Deck::~Deck() {

}

Deck::Deck(const Deck &other){
	iSizeDeck = other.iSizeDeck;
	bJokers = other.bJokers;
	cards = other.cards;
}

Deck::Deck(Deck &&other) {
    iSizeDeck = other.iSizeDeck;
	bJokers = other.bJokers;
	cards = other.cards;
}

Deck& Deck::operator=(const Deck& other) {
	iSizeDeck = other.iSizeDeck;
	bJokers = other.bJokers;
	cards = other.cards;
	return *this;
}

Deck& Deck::operator=(Deck &&other) {
    iSizeDeck = other.iSizeDeck;
	bJokers = other.bJokers;
	cards = other.cards;
	return *this;
}

Card Deck::getTopCard(){
	Card c;
	if(getSizeDeck()){
		c = cards.front();
		cards.pop_front();
		setSizeDeck(cards.size());
	}
	return c;
}

int Deck::getSizeDeck(){
	return iSizeDeck;
}

void Deck::setShuffled(){
	if(getSizeDeck()){

		list<Card> crdsTemp1;
		list<Card> crdsTemp2;

		int randomNumber,iSize;

		srand (time(NULL));

	    do{
	    	randomNumber = rand() % 10;
	    	if(randomNumber<5)
	    		crdsTemp1.push_front(cards.front());
	    	else
	    		crdsTemp2.push_front(cards.front());
	    	cards.pop_front();
	    	iSize=cards.size();
		}while(iSize>0);

	   do{
			if(crdsTemp1.size()){
				cards.push_front(crdsTemp1.back());
	    		crdsTemp1.pop_back();
	    	}
	    	if(crdsTemp2.size()){
				cards.push_front(crdsTemp2.back());
	    		crdsTemp2.pop_back();
	    	}
	    	iSize=cards.size();
		}while(iSize<getSizeDeck());
	}
}

void Deck::fillDeck(bool bArgJokers){
	setbJokers(bArgJokers);
	int i,j,s=0;
	char cSuitVar;
	Card crd;

	if (bJokers) {
		crd.setCardValues(0,'&');
		cards.push_front(crd);
		cards.push_back(crd);
	}

	do {
		for (j = 0; j < 4; j++) {
			for (i = 1; i <= 13; i++) {
				switch (j) {
					case 0:
						cSuitVar = 'H';
						break;
					case 1:
						cSuitVar = 'D';
						break;
					case 2:
						cSuitVar = 'C';
						break;
					case 3:
						cSuitVar = 'S';
						break;
					default:
						break;
				}
				crd.setCardValues(i,cSuitVar);
				cards.push_front(crd);
				s++;
			}
		}
	} while (s<52);
	setSizeDeck(cards.size());
}

void Deck::pushCard(Card crd){
	if(!getbFullDeck()){
		cards.push_back(crd);
		setSizeDeck(cards.size());
	}
}

void Deck::setbJokers(bool argJokers){
    bJokers = argJokers;
}

bool Deck::getbJokers(){
    return bJokers;
}

void Deck::setbFullDeck(bool argFullDeck){
    bFullDeck = argFullDeck;
}
bool Deck::getbFullDeck(){
    return bFullDeck;
}

void Deck::setSizeDeck(const int argSize){
    iSizeDeck = argSize;
}

void Deck::resetDeck()
{
    cards.empty();
    setSizeDeck(0);
    fillDeck(getbJokers());
}

/********************************
*			Hand Class		    	*
********************************/

Hand::Hand():Deck(false,false){
	iHandValue = 0;
	bBlackjack = false;
}

int Hand::getValue(){

	iHandValue=0;

	if(getSizeDeck()){
		for(iterCards = cards.begin(); iterCards != cards.end(); ++iterCards){
			iHandValue+= iterCards->getValue();
		}
	}
	return iHandValue;
}

bool Hand::isBlackjack(){
	if(getValue()==21 && getSizeDeck()==2)
		bBlackjack = true;
	else
		bBlackjack = false;
	return bBlackjack;
}

Hand& Hand::operator=(Hand &&other) {
    if (this == &other) return *this;
	bJokers =other.bJokers;
	iSizeDeck = other.iSizeDeck;
    cards = other.cards;
	getValue();
	isBlackjack();
    return *this;
}

Hand& Hand::operator=(const Hand &other) {
    if (this == &other) return *this;
	bJokers =other.bJokers;
	iSizeDeck = other.iSizeDeck;
    cards = other.cards;
	getValue();
	isBlackjack();
    return *this;
}

string Hand::getHandString()
{
    string strHand;
    if(getSizeDeck()){
		for(iterCards = cards.begin(); iterCards != cards.end(); ++iterCards){
			iterCards->show();
			strHand += iterCards->getStrCard();
			strHand += " ";
		}
	}
	return strHand;
}

