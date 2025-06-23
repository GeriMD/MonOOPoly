#pragma once
#include "Card.h"

class PaymentCard : public Card
{
private:
	int amount;

public:
	PaymentCard();
	PaymentCard(int amount, const MyString& description);

	int getAmount() const;
	Card* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printCardInformation() const override;
	virtual bool isGetOutOfJail() override;
	virtual void applyCard(Player& player) override;
};

