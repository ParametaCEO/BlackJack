#include "player.h"
#include "Deck.h"

Player::Player(unsigned int argChips)
{
    iChips = argChips;
    bWin = false;
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    iChips = other.iChips;
    bWin = other.bWin;
    //hand = other.hand;
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->iChips = rhs.iChips;
    this->bWin = rhs.bWin;
    //this->hand = rhs.hand;
    return *this;
}

Player& Player::operator=(Player&& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->iChips = rhs.iChips;
    this->bWin = rhs.bWin;
    //this->hand = rhs.hand;
    return *this;
}

unsigned int Player::putBet(unsigned int betSize)
{
    if(betSize == 0) return 0;

    if(iChips<betSize) return 0;

    iChips -= betSize;

    return betSize;
}

unsigned int Player::allIn()
{
    return putBet(iChips);
}

void Player::getBet(unsigned int betSize)
{
    if(betSize != 0) iChips += betSize;
}

void Player::hitCard(const Card argCrd)
{
    hand.pushCard(argCrd);
}

string Player::showHand()
{
    return hand.getHandString();
}

bool Player::HasBlackjack()
{
    return hand.isBlackjack();
}

unsigned int Player::GetHandValue()
{
    return hand.getValue();
}

bool Player::DidWin(unsigned int argValue)
{
    if(GetHandValue()<=21)
    {
        if(argValue>21) bWin = true;
        else if(argValue<GetHandValue()) bWin = true;
        else bWin = false;
    }
    return bWin;
}

/***********
DEALER CLASS
************/

Dealer::Dealer(unsigned int argChips) : Player(argChips)
{
    bUnlimitedChips = false;
    Deck theDeck();
    Hand discarted();
}

Dealer::Dealer(bool argUnlimited) : Player()
{
    bUnlimitedChips = argUnlimited;
    if(bUnlimitedChips) getBet(65000);
    else getBet(0);
}

Dealer::Dealer(const Dealer& other) : Player(other)
{
    bUnlimitedChips = other.bUnlimitedChips;
    iChips = other.iChips;
}

void Dealer::ShuffleDeck()
{
    theDeck.setShuffled();
}

void Dealer::HitPlayer(Player* argPlayer)
{
    argPlayer->hitCard( theDeck.getTopCard() );
}
