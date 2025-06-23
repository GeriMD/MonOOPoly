#include "FreeParkingField.h"
FreeParkingField::FreeParkingField() : Field()
{
}

FreeParkingField::FreeParkingField(int index, const MyString& description) : Field(index, description)
{
}

Field* FreeParkingField::clone() const
{
    return new FreeParkingField(*this);
}

void FreeParkingField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();
}

void FreeParkingField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
}
