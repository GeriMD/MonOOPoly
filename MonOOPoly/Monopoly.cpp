#include "Monopoly.h"


Monopoly& Monopoly::getInstance() {
	static Monopoly instance;
	return instance;
}

Player* Monopoly::getPlayer(int index) 
{
	//TODO: invalid index handle
	return players[index];
}

int Monopoly::getPlayersCount() const
{
	return players.getSize();
}

int Monopoly::getCurrentPlayerIndex() const
{
	return currentPlayerIndex;
}

void Monopoly::addPlayer(const Player& player)
{
	players.addObject(player);
}

void Monopoly::playTurn(int index)
{
	//TODO: 
}



