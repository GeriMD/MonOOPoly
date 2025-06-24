#include "Player.h"

Player::Player()
{
}

Player::Player(const MyString& name, int playerIndex, int money)
{
    this->name = name;
    this->playerIndex = playerIndex;
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

const MyString& Player::getName() const
{
    return name;
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

void Player::getOutOfJail()
{
    isInJail = false;
    skipTurn = false;
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
    std::cout << "Name: " << name << " Money: " << playersMoney << std::endl;
    std::cout << "Position on board: " << currentPlayerPositionIndex << std::endl;
    std::cout << "Has Get out of jail card: " << hasGetOutOfJailCard << std::endl;
    std::cout << "Is in jail: " << isInJail << " Skip turn: " << skipTurn << std::endl;
    std::cout << "Station owned count: " << stationOwnedCount << std::endl;
}

void Player::setHasGetOOJCard()
{
    hasGetOutOfJailCard = true;
}
void Player::setRolledPair(bool rolledPair)
{
   this->rolledPair = rolledPair;
}
bool Player::shouldSkipTurn()
{
    return skipTurn;
}
void Player::movePlayerWith(int positions)
{
    int newPosition = currentPlayerPositionIndex + positions;

    if (newPosition / 40 != 0)
    {
        newPosition %= 40; //TODO: make constant!
        setPlayerMoney(getPlayersMoney() + 200);
        std::cout << "You passed START so you earned 200 BGN." << std::endl;
    }
    currentPlayerPositionIndex = newPosition;
}
void Player::movePlayerTo(int position)
{
    if (position < currentPlayerPositionIndex)
    {
        setPlayerMoney(getPlayersMoney() + 200); //TODO: make constant!
        std::cout << "You passed START so you earned 200 BGN." << std::endl;
    }
    currentPlayerPositionIndex = position;
}
void Player::setSkipTurn(bool skip)
{
    this->skipTurn = skip;
}
Player* Player::clone() const {
    return new Player(*this);  
}

bool Player::getIsInJail() const
{
    return isInJail;
}

bool Player::getRolledPair() const
{
    return rolledPair;
}
