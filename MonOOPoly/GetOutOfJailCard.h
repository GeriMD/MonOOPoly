#pragma once
#include "Card.h"

class GetOutOfJailCard : public Card
{

public:
	virtual Card* clone() const override;
};

