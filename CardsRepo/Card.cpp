/*
 * Card.cpp
 *
 *  Created on: 11/06/2020
 *      Author: Jorge Cifuentes
 */

#include "Card.h"

Card::Card() {
	bHidden = true;
	iValue = 0;
	cFigure = '#';
	cSuite = 'X';
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

Card::Card(const Card &other) {
	bHidden = other.bHidden;
	iValue = other.iValue;
	cFigure = other.cFigure;
	cSuite = other.cSuite;
}


Card::Card(int iArgValue, char cArgSuit){
	setCardValues(iArgValue, cArgSuit);
}

Card& Card::operator=(const Card& other) {
	bHidden = other.bHidden;
	iValue = other.iValue;
	cFigure = other.cFigure;
	cSuite = other.cSuite;
	return *this;
}

Card& Card::operator=(Card&& other) {
	bHidden = other.bHidden;
	iValue = other.iValue;
	cFigure = other.cFigure;
	cSuite = other.cSuite;
	other.bHidden = false;
	other.iValue = 0;
	other.cFigure = 0;
	other.cSuite = 0;
	return *this;
}


void Card::show(){
	bHidden = false;
}

void Card::hide(){
	bHidden = true;
}

string Card::getStrCard(){
	string strCardFace;

	if (bHidden){
		strCardFace = "|||";
	}
	else{
		char cHolder[3];
		if (cFigure == '#')
			sprintf(cHolder, "%d", iValue);
		else
			sprintf(cHolder, "%c", cFigure);
		strCardFace.assign(cHolder);
		sprintf(cHolder,"%c",cSuite);
		strCardFace.append(cHolder);
	}

	return strCardFace;
}

void Card::setCardValues(int iArgValue, char cArgSuit){
	switch (iArgValue) {
		case 1:
			iValue = 11;
			cFigure = 'A';
			break;
		case 11:
			iValue = 10;
			cFigure = 'J';
			break;
		case 12:
			iValue = 10;
			cFigure = 'Q';
			break;
		case 13:
			iValue = 10;
			cFigure = 'K';
			break;
		default:
			iValue = iArgValue;
			cFigure = '#';
			break;
	}
	cSuite = cArgSuit;
	bHidden = true;
}

int Card::getValue(){
	return iValue;
}

