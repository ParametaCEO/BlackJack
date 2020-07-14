
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
    cout << "My wallet has " << jack.GetChips() << endl;
	return 0;
}

