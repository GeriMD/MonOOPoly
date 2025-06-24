#pragma once
#include "MyString.h"
#include "PlayerColour.h"
#pragma warning(disable:4996)

class Player
{
private:
	MyString name;

	int playerIndex = 0;
	int currentPlayerPositionIndex = 0;
	int playersMoney = 0;
	bool hasGetOutOfJailCard = false;
	int stationOwnedCount = 0;
	bool skipTurn = false;
	bool isInJail = false;
	bool rolledPair = false;
	//TODO: Add properties

public:
	Player();
	Player(const MyString& name, int playerIndex, int money); //TODO: Maybe add balance?

	virtual ~Player() = default;
	int getPlayersIndex() const;
	int getCurrentPosition() const;
	int getPlayersMoney() const;
	bool checkForGetOutOfJailCard() const;
	int getStationCount() const;
	const MyString& getName() const;
	virtual Player* clone() const;
	bool getIsInJail() const;
	bool getRolledPair() const;
	void setCurrentPosition(int index);
	void sendToJail();
	void getOutOfJail();
	void setPlayerMoney(int money);
	void setPlayerName(const MyString& name);
	void addStation();
	void printPlayerInfo() const;
	void setHasGetOOJCard();
	void setRolledPair(bool rolledPair);
	bool shouldSkipTurn();
	void movePlayerWith(int positions);
	void movePlayerTo(int position);
	void setSkipTurn(bool skip);
	//TODO: add more functions

};

