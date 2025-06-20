#pragma once
#include "Card.h"

class PaymentCard : public Card
{
private:
	int amount;

public:
	PaymentCard();
	PaymentCard(int amount);

	int getAmount() const;
	Card* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
};

