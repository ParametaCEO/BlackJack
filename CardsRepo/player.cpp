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
