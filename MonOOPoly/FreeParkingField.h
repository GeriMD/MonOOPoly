#pragma once
#include "Field.h"

class FreeParkingField : public Field
{
public:
	FreeParkingField();
	FreeParkingField(int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

