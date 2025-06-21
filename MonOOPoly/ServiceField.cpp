#include "ServiceField.h"

ServiceField::ServiceField() : Field()
{
	type = ServiceType::DEFAULT;
}

ServiceField::ServiceField(ServiceType& type, int index, const MyString& description) : Field(index, description)
{
	this -> type = type;
}

Field* ServiceField::clone() const
{
	return new ServiceField(*this);
}

void ServiceField::readFromFile(std::ifstream& is)
{
	// TODO:
}
