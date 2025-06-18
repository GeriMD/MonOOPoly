#pragma once
#include "Card.h"

class MovePositionCard : public Card
{
private:
	int positionsCount;

public:
	MovePositionCard();
	MovePositionCard(int positionsCount);

	Card* clone() const override;
	int getPositionCount() const;
};

