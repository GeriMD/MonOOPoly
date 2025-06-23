#pragma once
#include "Card.h"

class MovePositionCard : public Card
{
private:
	int positionsCount;

public:
	MovePositionCard();
	MovePositionCard(int positionsCount, const MyString& description);

	Card* clone() const override;
	int getPositionCount() const;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printCardInformation() const override;
	virtual bool isGetOutOfJail() override;
};

