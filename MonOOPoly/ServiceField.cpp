#include "ServiceField.h"
#include "CommandFactory.h"

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
void ServiceField::setOwner(Player* owner)
{
	this->owner = owner;
}

void ServiceField::applyEffect(Player& player)
{
	CommandFactory& factory = CommandFactory::getInstance();
	if (owner == nullptr)
	{
		std::cout << "This service does not have an owner. Do you want to buy it? Please enter buy_property/cancel." << std::endl;
		std::cout << "Answer: ";

		MyString answer;
		std::cin >> answer;

		factory.readCommand(answer)->executeCommand();
	}
	else {
		std::cout << "This service has an owner. You must roll the dice again. Please enter roll." << std::endl;
		MyString answer;
		std::cin >> answer;

		factory.readCommand(answer)->executeCommand();
		
		int diceSum; // TODO: GET FROM THE COMMAND
		player.setPlayerMoney(player.getPlayersMoney() - diceSum * 5);
		this->owner->setPlayerMoney(this->owner->getPlayersMoney() + diceSum * 5);
	}
}
