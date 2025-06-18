#include "Card.h"
#include <iostream>

Card::Card()
{
	description = "Default description.";
}

Card::Card(const MyString& description)
{
	this->description = description;
}

void Card::printDescription() const
{
	std::cout << this->description;
}
