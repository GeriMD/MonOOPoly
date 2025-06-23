#pragma once
#include "Field.h"

class TaxField : public Field
{
private:
	int amount;

public:
	TaxField();
	TaxField(int amount, int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

