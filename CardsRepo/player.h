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
        void SetStand(bool val) {stand = val;}
        bool HasWin() {return bWin;}
        void SetWin(bool val) {bWin = val;}


        unsigned int putBet(unsigned int betSize);
        unsigned int allIn();
        void getBet(unsigned int betSize);
        void hitCard(const Card argCrd);
        string showHand();
        void throwHand();
        bool HasBlackjack();
        unsigned int GetHandValue();
        bool DidWin(unsigned int argValue);
        bool DidPush(unsigned int argValue);


    protected:
        Hand hand;
        unsigned int iChips;

    private:
        bool stand;
        bool bWin;
};

/***********
DEALER CLASS
************/

class Dealer : public Player{
public:
    Dealer(unsigned int argChips);
    Dealer(bool argUnlimited = true);
    Dealer(const Dealer& other);

    //Getters & Setters
    void SetUnlimitedChips(bool argUnlimit) { bUnlimitedChips = argUnlimit; }
    bool GetUnlimitedChips() { return bUnlimitedChips; }

    void ShuffleDeck();
    void HitPlayer(Player* argPlayer);
    void ResetDeck();


protected:
    Deck theDeck;
    Hand discarted;

private:
    bool bUnlimitedChips;
};

#endif // PLAYER_H
