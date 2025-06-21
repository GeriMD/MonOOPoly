#include "Field.h"

Field::Field()
{
	index = 0;
	description = "";
}

Field::Field(int index, const MyString& description)
{
	this->index = index;
	this->description = description;
}

void Field::printDescription() const {
	std::cout << this->description;
}

int Field::getFieldIndex() const
{
	return index;
}
