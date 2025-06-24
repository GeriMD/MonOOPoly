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

Player* Monopoly::getPlayerByName(const MyString& name)
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i]->getName() == name)
		{
			return players[i];
		}
	}
	return nullptr;
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



