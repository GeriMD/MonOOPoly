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
	char buffer[1024];
	is.getline(buffer, 1024);
	description = buffer;

	is >> index;
	is.ignore();
	int serviceType;
	is >> serviceType;
	switch (serviceType)
	{
	case 1: 
	{ 
		type = ServiceType::WATER_SERVICE; 
		break; 
	}
	case 2: { type = ServiceType::ELECTRICITY_SERVICE; break; }
	default:
		throw std::invalid_argument("Invalid service type!");
	}
	is.ignore();
}

void ServiceField::printFieldInformation() const
{
	std::cout << description << std::endl;
	std::cout << index << std::endl;
	if (type == ServiceType::ELECTRICITY_SERVICE)
	{
		std::cout << "Type: Electricity service" << std::endl;
	}
	else if(type == ServiceType::WATER_SERVICE)
	{
		std::cout << "Type: Water service" << std::endl;
	}
	else {
		std::cout << "NO TYPE!!!" << std::endl;
	}
}
