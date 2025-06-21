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
