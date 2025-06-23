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
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();

    char buffer2[1024];
    is.getline(buffer2, 1024);
    name = buffer2;
}

void StationField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
    std::cout << name << std::endl;

}
