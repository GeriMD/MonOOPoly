#pragma once
#include "Card.h"
#include "Monopoly.h"
class AllPlayersPaymentCard : public Card
{
private:
	int amount;
	

public:
	AllPlayersPaymentCard();
	AllPlayersPaymentCard(int amount, const MyString& description);

	int getAmount() const;
	Card* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printCardInformation() const override;
	virtual bool isGetOutOfJail() override;
	virtual void applyCard(Player& player) override;
};

