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
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();
}

void CardField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl; 
}

