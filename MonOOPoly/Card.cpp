#include "Card.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Field.h"

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
	std::cout << this->description << std::endl;
}




