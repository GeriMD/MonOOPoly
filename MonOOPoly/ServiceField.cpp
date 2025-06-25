#include "ServiceField.h"

ServiceField::ServiceField() : Field()
{
	type = ServiceType::DEFAULT;
	ownerName = "";
}

ServiceField::ServiceField(ServiceType& type, int index, const MyString& description) : Field(index, description)
{
	this -> type = type;
	ownerName = "";
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
void ServiceField::setOwner(const MyString& ownerName)
{
	this->ownerName = ownerName;
}

void ServiceField::applyEffect(Player& player)
{
	Monopoly& monopoly = Monopoly::getInstance();
	Player* owner = monopoly.getPlayerByName(ownerName);
	//CommandFactory& factory = CommandFactory::getInstance();
	
	if (owner == nullptr)
	{
		again:
		std::cout << "This service does not have an owner. Do you want to buy it? Yes/No [y/n]" << std::endl;
		std::cout << "Answer: ";
		char answer;
		std::cin >> answer;

		switch (answer) {
		case 'y':
		case 'Y': ownerName = player.getName(); break;
		case 'n':
		case 'N': std::cout << "You did not buy this service." << std::endl; break;
		default:
			system("cls");
			goto again;
		}
	}
	else {
		std::cout << "This service has an owner. You must pay 100 BGN." << std::endl;
		player.checkIfHasMoneyToPay(100);
		player.setPlayerMoney(player.getPlayersMoney() - 100);
		owner->setPlayerMoney(owner->getPlayersMoney() + 100);
	}
}
const MyString& ServiceField::getOwnerName() const{
	return ownerName;
}