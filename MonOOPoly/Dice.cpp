#include "Dice.h"

void Dice::rollDice()
{
	std::srand(std::time(nullptr));

	int dice1 = std::rand() % 6 + 1;
	int dice2 = std::rand() % 6 + 1;

	std::cout << "You rolled " << dice1 << " on the first dice." << std::endl;
	std::cout << "You rolled " << dice2 << " on the second dice." << std::endl;

	if (dice1 == dice2)
	{
		isPair = true;
	}
	sumOfTheDice = dice1 + dice2;
}

Dice& Dice::getInstance() {
	static Dice instance;
	return instance;
}

int Dice::getSumOfTheDice() const
{
	return sumOfTheDice;
}

bool Dice::getIsPair() const
{
	return isPair;
}
