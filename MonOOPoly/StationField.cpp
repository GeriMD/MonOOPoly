#include "StationField.h"

StationField::StationField() : Field()
{
    name = "Default";
}

StationField::StationField(const MyString& name, int index, const MyString& description) : Field(index, description)
{
    this->name = name;
}

Field* StationField::clone() const
{
    return new StationField(*this);
}

void StationField::readFromFile(std::ifstream& is)
{
    // TODO:
}
