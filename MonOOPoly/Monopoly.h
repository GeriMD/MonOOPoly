#pragma once
#include "MyVector.hpp"
#include "Player.h"
#include "Board.h"
#include "MyVector.hpp"
#include "Player.h"
class Monopoly
{
private:
	bool gameOver = false;
	int currentPlayerIndex = 0;

	MyVector<Player> players;
	Board& board = Board::getInstance();
	
public:
	Monopoly() = default;
	//Monopoly(const PlayersContainer& players);
	int getCurrPlayerIndex() const;
	bool isGameOver() const;
	Player& getPlayer(int index);//TODO: !!!
	int getPlayersCount() const;
	void addPlayer(const Player& player);
};

