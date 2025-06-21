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
    //TODO:
}
