#include "CardField.h"

CardField::CardField() : Field()
{
}

CardField::CardField(int index, const MyString& description) : Field(index, description)
{
}

Field* CardField::clone() const
{
	return new CardField(*this);
}

void CardField::readFromFile(std::ifstream& is)
{
	//TODO:
}

