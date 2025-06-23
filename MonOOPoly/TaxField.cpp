#include "TaxField.h"

TaxField::TaxField() : Field()
{
    amount = 0;
}

TaxField::TaxField(int amount, int index, const MyString& description) : Field(index, description)
{
    this->amount = amount;
}

Field* TaxField::clone() const
{
    return new TaxField(*this);
}

void TaxField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();

    is >> amount;
    is.ignore();
}

void TaxField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
    std::cout << amount << std::endl;
}
