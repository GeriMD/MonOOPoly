#include "Player.h"

Player::Player()
{
}

Player::Player(MyString name, int playerIndex, PlayerColour& colour)
{
    this->name = name;
    this->playerIndex = playerIndex;
    this->colour = colour;
}

int Player::getPlayersIndex() const
{
    return playerIndex;
}

int Player::getCurrentPosition() const
{
    return currentPlayerPositionIndex;
}

int Player::getPlayersMoney() const
{
    return playersMoney;
}
