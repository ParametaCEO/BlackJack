#include "player.h"

Player::Player(unsigned int argChips)
{
    iChips = argChips; //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    iChips = other.iChips;
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    iChips = rhs.iChips;
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
