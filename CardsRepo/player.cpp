#include "player.h"
#include "deck.h"
#include "card.h"
#include <string>

Player::Player(string argName){
    strName = argName;
}

Player::~Player(){

}

int Player::GetChips() {
    return iChips;
}

void Player::SetChips(int val) {
    iChips = val;
}

string Player::GetName(){
    return strName;
}

void Player::SetName(string argName){
    strName = argName;
}

void Player::Hit(Card argCard){
    hand.pushCard(argCard);
}

Hand Player::GetHand(){
    return hand;
}
