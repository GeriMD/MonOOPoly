#pragma once
#include "MyVector.hpp"
#include "Player.h"
#include "Board.h"
#include "HeterogeneousContainer.hpp"
#include "CommandFactory.h"
#include "Dice.h"
class Monopoly
{
private:
	bool gameOver = false;
	int currentPlayerIndex = 0;

	HeterogeneousContainer<Player> players;
	
	
	Monopoly() = default;
public:
	Monopoly(const Monopoly& other) = delete;
	Monopoly& operator=(const Monopoly& other) = delete;
	
	static Monopoly& getInstance();
	Player* getPlayer(int index);
	Player* getPlayerByName(const MyString& name);
	int getPlayersCount() const;
	int getCurrentPlayerIndex() const;
	void addPlayer(const Player& player);
	void playTurn(int index);
	void startGame();
	void printWelcomeText();
	void printRules();
	bool getGameOver();
};

