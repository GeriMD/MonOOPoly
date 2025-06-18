#pragma once
#include "MyString.h"
#include "PlayerColour.h"
#pragma warning(disable:4996)

class Player
{
private:
	MyString name;
	PlayerColour colour;

	int playerIndex;
	int currentPlayerPositionIndex;
	int playersMoney;
	bool hasGetOutOfJailCard = false;

	bool skipTurn = false;
	//TODO: Add properties

public:
	Player();
	Player(MyString name, int playerIndex, PlayerColour& colour); //TODO: Maybe add balance?

	int getPlayersIndex() const;
	int getCurrentPosition() const;
	int getPlayersMoney() const;
	
	//TODO: add more functions

};

