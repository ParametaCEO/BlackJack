
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
#include "Game.h"


using namespace std;

int main()
{
    int cmdCode=0;
    Game Blackjack;
    do
    {
        cmdCode = Blackjack.runCommand(Blackjack.displayScreen(""));
        cout << cmdCode << endl;
    }while(cmdCode);

	return cmdCode;
}

