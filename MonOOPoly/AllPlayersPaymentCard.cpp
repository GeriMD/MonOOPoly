#include "AllPlayersPaymentCard.h"
#include "Monopoly.h"
AllPlayersPaymentCard::AllPlayersPaymentCard() : Card()
{
	amount = 0; //TODO: Make a constant
}

AllPlayersPaymentCard::AllPlayersPaymentCard(int amount, const MyString& description) : Card(description)
{
	this->amount = amount;
}

int AllPlayersPaymentCard::getAmount() const
{
	return amount;
}

Card* AllPlayersPaymentCard::clone() const
{
	return new AllPlayersPaymentCard(*this);
}

void AllPlayersPaymentCard::readFromFile(std::ifstream& is)
{
	char buffer[1024];
	
	is.getline(buffer, 1024);

	description = buffer;
	is >> amount;
	is.ignore();
}

void AllPlayersPaymentCard::printCardInformation() const
{
	std::cout << description << std::endl;
	if (amount > 0)
	{
		std::cout << "You should receive " << amount << " BGN from each person." << std::endl;
	}
	else {
		std::cout << "You should give " << amount * (-1) << " BGN to each person." << std::endl;
	}
}

bool AllPlayersPaymentCard::isGetOutOfJail()
{
	return false;
}

void AllPlayersPaymentCard::applyCard(Player& player)
{
	Monopoly& monopoly = Monopoly::getInstance();
	printDescription();
	for (int i = 0; i < monopoly.getPlayersCount(); i++)
	{
		if (player.getPlayersIndex() != monopoly.getPlayer(i)->getPlayersIndex())
		{
			if (amount < 0)
			{
				if (player.getPlayersMoney() < amount * (-1))
				{
					//TODO:
				}
				player.setPlayerMoney(player.getPlayersMoney() - amount * (-1));
				monopoly.getPlayer(i)->setPlayerMoney(monopoly.getPlayer(i)->getPlayersMoney() + amount * (-1));
			}
			else {
				player.setPlayerMoney(player.getPlayersMoney() + amount);
				monopoly.getPlayer(i)->setPlayerMoney(monopoly.getPlayer(i)->getPlayersMoney() + amount);
			}
		}
	}
}
