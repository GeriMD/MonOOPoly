#include "Monopoly.h"
#include <windows.h>
#include "CardDeck.h"

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
	do {
		
		std::cout << "Player " << index + 1 << std::endl;
		std::cout << "It is your turn. Roll the dice!" << std::endl;
		Sleep(1000);
		dice.rollDice();
		int positionsToMove = dice.getSumOfTheDice();

		player.movePlayerWith(positionsToMove);
		board.getField(player.getCurrentPosition())->printDescription();
		board.getField(player.getCurrentPosition())->applyEffect(player);
		Sleep(2000);
		player.printPlayerInfo();
		Sleep(1000);
	} while (dice.getIsPair());
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
	while (!getGameOver() || players.getSize() == 1)
	{
		for (int i = 0; i < players.getSize(); i++)
		{
			playTurn(i);
		}
	}
//playTurn(0);
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
	std::cout << "Landing on Go to Jail sends you to jail—you'll need to wait, pay, or use a Get Out of Jail card." << std::endl;
	std::cout << "If you can't pay what you owe, you go bankrupt and are out of the game." << std::endl;
	std::cout << "The last player remaining wins the game!" << std::endl;

}

bool Monopoly::getGameOver()
{
	return gameOver;
}

void Monopoly::test()
{
	CardDeck& deck = CardDeck::getInstance();
	for (int i = 0; i < 2; i++) {
		deck.drawCard();
}
	Player* player1 = new Player("Pl1",0,1500);
	Player* player2 = new Player("Pl2",0,1500);
	Player* player3 = new Player("Pl3",0,1500);
	Player* player4 = new Player("Pl4",0,1500);
	//Player* player2("Pl2",0,100);
	//Player* player3("Pl3",0,100);
	//Player* player4("Pl4",0,100);
	players.addObject(player1);
	players.addObject(player2);
	players.addObject(player3);
	players.addObject(player4);
	deck.drawCard().get()->applyCard(*player3);

	//std::cout << player1.getName();
	std::cout << (*player3).getPlayersMoney()<<"\n";
	std::cout << (*player1).getPlayersMoney()<<"\n";
	std::cout << (*player2).getPlayersMoney()<<"\n";
	std::cout << (*player4).getPlayersMoney()<<"\n";
}
