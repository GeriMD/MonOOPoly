#include "Player.h"
#include "Dice.h"
#include "Board.h"
#include "PropertyField.h"
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
    //skipTurn = true;
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
    std::cout << "Stations owned count: " << stationOwnedCount << std::endl;
}

void Player::setHasGetOOJCard()
{
    hasGetOutOfJailCard = true;
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
bool Player::getIsBancrupted() const
{
    return isBancrupted;
}
void Player::setIsBancrupted(bool isBancrupted)
{
    this->isBancrupted = isBancrupted;
}
void Player::checkIfHasMoneyToPay(int amount)
{
    if (getPlayersMoney() < amount)
    {
        setIsBancrupted(true);
        //std::cout << "1";
    }
}
void Player::buyCottage(int index)
{
    Board& board = Board::getInstance();
    PropertyField* property = dynamic_cast<PropertyField*>(&board.getField(index));
    if (property && hasAllProperties(property->getColour())) {


        if (!property)
        {
            std::cout << "Invalid index! Field on this index is not a property!" << std::endl;
            system("pause");
            return;
        }
        if (!hasProperty(index))
        {
            std::cout << "Player " << name << " does not own this property!" << std::endl;
            system("pause");
            return;
        }
        property->increaseCottageCount();
        setPlayerMoney(getPlayersMoney() - property->getCottagePrice());
       // std::cout << property->getCottagePrice();
        std::cout << "Bought cottage." << std::endl;
    } else 
    {
        std::cout << "Player does not have all properties with this colour!" << std::endl;
        system("pause");
        return;
    }
}
void Player::buyCastle(int index)
{
    Board& board = Board::getInstance();
    PropertyField* property = dynamic_cast<PropertyField*>(&board.getField(index));
    if (!property)
    {
        std::cout << "Invalid index! Field on this index is not a property!" << std::endl;
        return;
    }
    if (!hasProperty(index))
    {
        std::cout << "Player " << name << " does not own this property!" << std::endl;
        system("pause");
        return;
    }
    property->increaseCastleCount();
    setPlayerMoney(getPlayersMoney() - property->getCastlePrice());
}
void Player::checkIsJail()
{
    if (isInJail) {
        Dice& dice = Dice::getInstance();
        jail:
        std::cout << "You are in jail." << std::endl;
        if (checkForGetOutOfJailCard())
        {
std::cout << "You have get ouf of jail card. You can either use it or roll dice or pay 200 BGN to get out. [u/r/p]" << std::endl;
        
        }
        else {
            std::cout << "Choose to roll the dice or pay 200 BGN." << std::endl;
        }
        char ans;
        std::cin >> ans;

        if (ans == 'r') {
            dice.rollDice();
            if (dice.getIsPair())
                isInJail = false;
        }
        else if (ans == 'p') {
            setPlayerMoney(getPlayersMoney() - 200);
            isInJail = false;
        }
        else if (ans == 'c' && checkForGetOutOfJailCard()) {
            isInJail = false;
            hasGetOutOfJailCard = false;
        }
        else goto jail;
    }
}
bool Player::hasProperty(int index)
{
    Board& board = Board::getInstance();
    PropertyField* property = dynamic_cast<PropertyField*>(&board.getField(index));
    if (!property)
    {
        std::cout << "Invalid index! Field on this index is not a property!" << std::endl;
        return false;
    }

    if (property->getOwnerName() == getName())
    {
        return true;
    }
    return false;
}
bool Player::hasAllProperties(PropertyColour colour)
{
    Board& board = Board::getInstance();

    int propertyWithColourCount = 0;
    int playerOwnedFieldsCount = 0;

    for (int i = 0; i < 40; i++)
    {
        Field* current = &board.getField(i);
        PropertyField* property = dynamic_cast<PropertyField*>(current);
        if (property && property->getColour() == colour)
        {
            propertyWithColourCount++;
            if (property->getOwnerName() == getName())
            {
                playerOwnedFieldsCount++;
            }
        }
    }
    //std::cout << propertyWithColourCount << " " << playerOwnedFieldsCount;
    if (propertyWithColourCount == playerOwnedFieldsCount)
    {
        return true;
    }
   
    return false;
}
Player* Player::clone() const {
    return new Player(*this);  
}

bool Player::getIsInJail() const
{
    return isInJail;
}

