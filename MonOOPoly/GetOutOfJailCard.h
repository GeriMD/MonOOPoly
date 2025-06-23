#pragma once
#include "Card.h"

class GetOutOfJailCard : public Card
{

public:
	GetOutOfJailCard();
	GetOutOfJailCard(const MyString& description);
	virtual Card* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printCardInformation() const override;
	virtual bool isGetOutOfJail() override;
	virtual void applyCard(Player& player) override;
};

