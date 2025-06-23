#pragma once
#include "PropertyColour.h"
#include "MyString.h"
#include "Field.h"

class PropertyField : public Field
{
private:
	PropertyColour colour = PropertyColour::DEFAULT_COLOR;
	MyString name;
	unsigned priceToBuy = 0;
	unsigned rent;
	unsigned cottagePrice;
	unsigned castlePrice;
	Player* owner;
public:
	PropertyField();
	PropertyField(MyString& name, unsigned priceToBuy, PropertyColour& colour, unsigned rent, unsigned cottagePrice, unsigned castlePrice, int index, MyString& description);

	void setOwner(Player* owner);
	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

