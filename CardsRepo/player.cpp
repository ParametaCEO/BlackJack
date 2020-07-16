#include "player.h"
#include "Deck.h"

Player::Player(unsigned int argChips)
{
    iChips = argChips;
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    iChips = other.iChips;
    //hand = other.hand;
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->iChips = rhs.iChips;
    //this->hand = rhs.hand;
    return *this;
}

Player& Player::operator=(Player&& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->iChips = rhs.iChips;
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
