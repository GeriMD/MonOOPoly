#include "PropertyField.h"

PropertyField::PropertyField() : Field(1, "")
{
	name = "";
	priceToBuy = 0;
	colour = PropertyColour::DEFAULT;
	rent = 0;
	cottagePrice = 0;
	castlePrice = 0;

}

PropertyField::PropertyField(MyString& name, unsigned priceToBuy, PropertyColour& colour, unsigned rent, unsigned cottagePrice, unsigned castlePrice, int index, MyString& description) : Field(index, description)
{
	this->name = name;
	this->priceToBuy = priceToBuy;
	this->colour = colour;
	this->cottagePrice = cottagePrice;
	this->rent = rent;
	this->castlePrice = castlePrice;
}

Field* PropertyField::clone() const
{
	return new PropertyField(*this);
}

void PropertyField::readFromFile(std::ifstream& is)
{
	// TODO: 
}
