#pragma once
#include "PropertyColour.h"
#include "MyString.h"
#include "Field.h"
#include "Monopoly.h"

class PropertyField : public Field
{
private:
	PropertyColour colour = PropertyColour::DEFAULT_COLOR;
	MyString name;
	unsigned priceToBuy = 0;
	unsigned rent;
	unsigned cottagePrice;
	unsigned castlePrice;
	MyString ownerName;
	int cottageCount = 0;
	int castleCount = 0;

public:
	PropertyField();
	PropertyField(MyString& name, unsigned priceToBuy, PropertyColour& colour, unsigned rent, unsigned cottagePrice, unsigned castlePrice, int index, MyString& description);

	void setOwner(MyString& ownerName);
	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
	void increaseCottageCount();
	void increaseCastleCount();
	const MyString& getOwnerName() const;
	int getCottagePrice() const;
	int getCastlePrice() const;
	PropertyColour getColour() const;
};

