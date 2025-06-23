#include "Player.h"

Player::Player()
{
}

Player::Player(const MyString& name, int playerIndex, PlayerColour& colour, int money)
{
    this->name = name;
    this->playerIndex = playerIndex;
    this->colour = colour;
    this->playersMoney = money;
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

bool Player::checkForGetOutOfJailCard() const
{
    return hasGetOutOfJailCard;
}

int Player::getStationCount() const
{
    return stationOwnedCount;
}

void Player::setCurrentPosition(int index)
{
    currentPlayerPositionIndex = index;
}

void Player::sendToJail()
{
    isInJail = true;
    skipTurn = true;
}

void Player::setPlayerMoney(int money)
{
    playersMoney = money;
}

void Player::setPlayerName(const MyString& name)
{
    this->name = name;
}

void Player::addStation()
{
    stationOwnedCount++;
}


void Player::printPlayerInfo() const
{
    std::cout << "Name: " << name << " Money: " << playersMoney << " Position: " << currentPlayerPositionIndex << " Has OOJ card: " << hasGetOutOfJailCard << " Is in jail: " << isInJail << " Skip turn: " << skipTurn << std::endl;
}
