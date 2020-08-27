/*
 * Card.h
 *
 *  Created on: 11/06/2020
 *      Author: Jorge Cifuentes
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

using namespace std;

class Card {
public:
	Card();
	virtual ~Card();
	Card(const Card& other);
	Card(const Card&& other);
	Card(int iArgValue, char cArgSuit);

	Card& operator=(const Card& other);
	Card& operator=(Card&& other);


	void hide();
	void show();
	int getValue();
	void setCardValues(int iArgValue, char cArgSuit);
	string getStrCard();

private:
	bool bHidden;
	int iValue;
	char cFigure;
	char cSuite;
};

#endif /* CARD_H_ */

