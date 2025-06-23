#include "StartField.h"

StartField::StartField() : Field()
{
}

StartField::StartField(int index, const MyString& description) : Field(index, description)
{
}

Field* StartField::clone() const
{
    return new StartField(*this);
}

void StartField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();
}

void StartField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;

}

void StartField::applyEffect(Player& player)
{
}
