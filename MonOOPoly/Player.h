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
	int stationOwnedCount = 0;
	bool skipTurn = false;
	bool isInJail = false;
	//TODO: Add properties

public:
	Player();
	Player(const MyString& name, int playerIndex, PlayerColour& colour, int money); //TODO: Maybe add balance?

	int getPlayersIndex() const;
	int getCurrentPosition() const;
	int getPlayersMoney() const;
	bool checkForGetOutOfJailCard() const;
	int getStationCount() const;
	const MyString& getName() const;

	void setCurrentPosition(int index);
	void sendToJail();
	void setPlayerMoney(int money);
	void setPlayerName(const MyString& name);
	void addStation();
	void printPlayerInfo() const;
	void setHasGetOOJCard();
	//TODO: add more functions

};

