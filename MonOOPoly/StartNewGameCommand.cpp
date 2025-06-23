#include "StartNewGameCommand.h"
#include <iostream>
#include "MyString.h"

void StartNewGameCommand::executeCommand()
{
	int playersCount;
	std::cin >> playersCount;

	if (playersCount < 2 || playersCount > 6)
	{
		std::cout << "invalid count" << std::endl;
		//throw std::invalid_argument("Invalid players count!");
	}

	for (int i = 0; i < playersCount; i++)
	{
		std::cout << "Player " << i + 1 << "name: ";
		MyString name;
		std::cin >> name;

		//TODO: ADD PLAYER AND START GAME
	}

}
