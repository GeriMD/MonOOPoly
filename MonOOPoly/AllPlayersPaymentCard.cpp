#include "AllPlayersPaymentCard.h"

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
