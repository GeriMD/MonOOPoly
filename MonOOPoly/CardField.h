#pragma once
#include "Field.h"

class CardField : public Field
{
public:
	CardField();
	CardField(int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;

	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

