#include "GoToJailField.h"

GoToJailField::GoToJailField() : Field()
{
}

GoToJailField::GoToJailField(int index, const MyString& description) : Field(index, description)
{
}

Field* GoToJailField::clone() const
{
    return new GoToJailField(*this);
}

void GoToJailField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();
}

void GoToJailField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
}
