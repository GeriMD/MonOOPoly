#include "Monopoly.h"
#include <windows.h>
#include "CardDeck.h"
#include "PropertyField.h"

Dice& dice = Dice::getInstance();
Board& board = Board::getInstance();

Monopoly& Monopoly::getInstance()
{
	static Monopoly instance;
	return instance;
}

Player& Monopoly::getPlayer(int index)
{
	return *players[index];
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
}

void Monopoly::playTurn(int index)
{
//Dice& dice = Dice::getInstance();
		
		Player& player = getPlayer(index);
		//Board& board = Board::getInstance();
	
		if (player.getIsNotActive()) {
			return;
		}
			


		std::cout << "Player " << index + 1 << std::endl;
		player.checkIsJail();

		if (player.getIsInJail()) {
			return;
		}
		std::cout << "It is your turn. Roll the dice!" << std::endl;
		Sleep(1000);
		dice.rollDice();
		int positionsToMove = dice.getSumOfTheDice();

		player.movePlayerWith(positionsToMove);
		board.getField(player.getCurrentPosition()).printDescription();
		board.getField(player.getCurrentPosition()).applyEffect(player);
		Sleep(2000);
		player.printPlayerInfo();
		Sleep(1000);
	
	system("pause");
	system("cls");
}

void Monopoly::startGame()
{
	printWelcomeText();
	printRules();
	again_enter_players:
	std::cout << "Please enter number of players: ";
	int number;
	std::cin >> number;
	if (number < 2 || number > 6)
	{
		std::cout << "Invalid input! Players must be between 2 and 6!" << std::endl;
		goto again_enter_players;
	}

	for (int i = 0; i < number; i++)
	{
		std::cout << "Please enter player " << i + 1 << " name: ";
		MyString name;
		std::cin >> name;

		players.addObject(Player(name, i, 1500));
		
	}
	for (int i = 0; i < players.getSize(); i++)
	{
		players[i]->printPlayerInfo();
		std::cout << std::endl;
	}
	while (!getGameOver() || getPlayersActiveCount() == 1)
	{
		for (int i = 0; i < players.getSize(); i++)
		{
			playTurn(i);
		}
	}

}


void Monopoly::printWelcomeText()
{
	std::cout << "Welcome to Monopoly Bulgaria!" << std::endl;
	std::cout << "Get ready to buy properties, collect rent, and compete to become the wealthiest player in Bulgaria!" << std::endl;
	std::cout << "Roll the dice, build your empire, and outsmart your opponents in this exciting journey across iconic Bulgarian locations." << std::endl;
	std::cout << "Let the game begin!" << std::endl;
	std::cout << std::endl;
}

void Monopoly::printRules()
{
	std::cout << "Quick Rules" << std::endl;
	std::cout << "Players take turns rolling two dice and move around the board." << std::endl;
	std::cout << "If you land on an unowned property, you can buy it." << std::endl;
	std::cout << "If you land on another player's property, you must pay rent." << std::endl;
	std::cout << "Owning all properties of the same color lets you build houses and hotels." << std::endl;
	std::cout << "Landing on Go to Jail sends you to jail�you'll need to wait, pay, or use a Get Out of Jail card." << std::endl;
	std::cout << "If you can't pay what you owe, you go bankrupt and are out of the game." << std::endl;
	std::cout << "The last player remaining wins the game!" << std::endl;

}

bool Monopoly::getGameOver()
{
	return gameOver;
}

void Monopoly::test()
{
	Player* player = new Player("pl1", 0, 1500);
	Player* pl = new Player("pl2", 0, 1500);
	players.addObject(player);
	players.addObject(pl);
player->movePlayerTo(37);
board.getField(37).applyEffect(*player);
PropertyField* property = dynamic_cast<PropertyField*>(&board.getField(37));
std::cout << property->getOwnerName() << std::endl;
player->surrender();
std::cout << property->getOwnerName() << std::endl;
//player->buyCottage(37);
//player->printPlayerInfo();

}

int Monopoly::getPlayersActiveCount() const
{
	int playersActive = 0;

	for (int i = 0; i < players.getSize(); i++)
	{
		if (!players[i]->getIsNotActive())
		{
			playersActive++;
		}
	}
	return playersActive;
}
