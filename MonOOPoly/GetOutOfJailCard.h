#pragma once
#include "Card.h"

class GetOutOfJailCard : public Card
{

public:
	GetOutOfJailCard();
	GetOutOfJailCard(const MyString& description);
	virtual Card* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
};

