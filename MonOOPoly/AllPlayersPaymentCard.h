#pragma once
#include "Card.h"

class AllPlayersPaymentCard : public Card
{
private:
	int amount;

public:
	AllPlayersPaymentCard();
	AllPlayersPaymentCard(int amount);

	int getAmount() const;
	Card* clone() const override;
};

