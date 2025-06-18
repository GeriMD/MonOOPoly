#include "AllPlayersPaymentCard.h"

AllPlayersPaymentCard::AllPlayersPaymentCard() 
{
	amount = 0; //TODO: Make a constant
}

AllPlayersPaymentCard::AllPlayersPaymentCard(int amount) 
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
