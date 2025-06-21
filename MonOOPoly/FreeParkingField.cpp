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
    //TODO:
}
