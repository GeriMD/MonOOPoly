#include "PaymentCard.h"

PaymentCard::PaymentCard() : Card()
{
    amount = 0;
}

PaymentCard::PaymentCard(int amount, const MyString& description) : Card(description)
{
    this->amount = amount;
}

Card* PaymentCard::clone() const
{
    return new PaymentCard(*this);
}

void PaymentCard::readFromFile(std::ifstream& is)
{
	char buffer[1024];
	
	is.getline(buffer, 1024);

	description = buffer;
	is >> amount;
    is.ignore();
	
}

void PaymentCard::printCardInformation() const
{
	std::cout << description << std::endl;
	if (amount > 0)
	{
		std::cout << "You have to receive " << amount << " BGN from the Bank." << std::endl;
	}
	else {
		std::cout << "You have to pay " << amount * (-1) << " BGN to the Bank." << std::endl;
	}
}

bool PaymentCard::isGetOutOfJail()
{
	return false;
}

void PaymentCard::applyCard(Player& player)
{
}
