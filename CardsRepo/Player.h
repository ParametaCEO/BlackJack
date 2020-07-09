#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "deck.h"
#include "card.h"

using namespace std;


class Player
{
    public:
        Player(string argName);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        int GetChips();
        void SetChips(int val);
        string GetName();
        void SetName(string argName);

        void Hit(Card argCard);
        Hand GetHand();

    protected:

    private:
        int iChips;
        string strName;
        Hand hand;
};

#endif // PLAYER_H
