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
    //TODO:
}
