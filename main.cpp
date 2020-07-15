
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
    cout << "My wallet has " << jack.GetChips() << endl;
    cout << "I bet " << jack.putBet(10) << endl;
    cout << "Now my wallet has " << jack.GetChips() << endl;
    cout << "Increase my  bet in " << jack.putBet(20) << endl;
    cout << "Now my wallet has " << jack.GetChips() << endl;

    cout << "His wallet has " << johnnie.GetChips() << endl;
    cout << "I bet same amount than his " << jack.putBet(johnnie.putBet(30)) << endl;
    cout << "Now my wallet has " << jack.GetChips() << endl;
    cout << "And his wallet has " << johnnie.GetChips() << endl;

    cout << "I bet all " << jack.allIn() << endl;
    cout << "Now my wallet has " << jack.GetChips() << endl;

    jack = johnnie;
    johnnie.allIn();

    cout << "I borrow from him all, now my wallet has " << jack.GetChips() << endl;
    cout << "And his wallet has " << johnnie.GetChips() << endl;


	return 0;
}

