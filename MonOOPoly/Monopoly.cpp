#include "Monopoly.h"

Monopoly::Monopoly()
	: //board(Board::getInstance()),
	factory(CommandFactory::getInstance())
{ }

Monopoly& Monopoly::getInstance()
{
	static Monopoly instance;
	std::cout << "123";
	return instance;
}

Player* Monopoly::getPlayer(int index)
{
	return nullptr;
}

Player* Monopoly::getPlayerByName(const MyString& name)
{
	return nullptr;
}

int Monopoly::getPlayersCount() const
{
	return 0;
}

int Monopoly::getCurrentPlayerIndex() const
{
	return 0;
}

void Monopoly::addPlayer(const Player& player)
{
}

void Monopoly::playTurn(int index)
{
}

void Monopoly::startGame()
{
	std::cout << "Welcome" << std::endl;
	std::cout << "Please enter number of players: ";
	int number;
	std::cin >> number;

	for (int i = 0; i < number; i++)
	{
		std::cout << "Please enter player " << i + 1 << " name.";
		MyString name;
		std::cin >> name;

		players.addObject(Player(name, i, 1500));
	}

	for (int i = 0; i < players.getSize(); i++)
	{players[i]->printPlayerInfo() ;
	}
}
