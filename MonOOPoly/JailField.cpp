#include "JailField.h"

JailField::JailField() : Field()
{
}

JailField::JailField(int index, const MyString& description) : Field(index, description)
{
}

Field* JailField::clone() const
{
    return new JailField(*this);
}

void JailField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();
}

void JailField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
}

void JailField::applyEffect(Player& player)
{
    std::cout << "You are just visiting the jail...";
}
