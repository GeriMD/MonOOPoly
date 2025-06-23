#include "Field.h"

Field::Field()
{
	index = -1;
	description = "";
}

Field::Field(int index, const MyString& description)
{
	this->index = index;
	this->description = description;
}

void Field::printDescription() const {
	std::cout << this->description << std::endl;
}

int Field::getFieldIndex() const
{
	return index;
}
