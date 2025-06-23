#pragma once
#include "MyVector.hpp"
#include "Player.h"
#include "Board.h"
#include "HeterogeneousContainer.hpp"
#include "Player.h"
class Monopoly
{
private:
	bool gameOver = false;
	int currentPlayerIndex = 0;

	HeterogeneousContainer<Player> players;
	Board& board = Board::getInstance();
	
	Monopoly();
public:
	Monopoly(const Monopoly& other) = delete;
	Monopoly& operator=(const Monopoly& other) = delete;
	
	static Monopoly& getInstance();

	Player* getPlayer(int index);
	int getPlayersCount() const;
	int getCurrentPlayerIndex() const;
	void addPlayer(const Player& player);
	void playTurn(int index);
};

