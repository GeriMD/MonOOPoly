#pragma once
#include "MyString.h"
#include "PlayerColour.h"
#pragma warning(disable:4996)

class Player
{
private:
	MyString name;
	PlayerColour colour = PlayerColour::DEFAULT;

	int playerIndex = 0;
	int currentPlayerPositionIndex = 0;
	int playersMoney = 0;
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

