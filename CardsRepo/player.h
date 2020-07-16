#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"


class Player
{
    public:
        Player(unsigned int argChips = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);
        Player& operator=(Player&& rhs);

        unsigned int GetChips() { return iChips; }
        void SetChips(unsigned int val) { iChips = val; }
        bool GetStand() {return stand;}
        void SetStand(bool val) {stand = val}

        unsigned int putBet(unsigned int betSize);
        unsigned int allIn();
        void getBet(unsigned int betSize);
        void hitCard(const Card argCrd);
        string showHand();


    protected:
        Hand hand;


    private:
        unsigned int iChips;
        bool stand;
};

#endif // PLAYER_H
