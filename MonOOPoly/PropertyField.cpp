#include "PropertyField.h"
#include "CommandFactory.h"

PropertyField::PropertyField() : Field()
{
	name = "";
	priceToBuy = 0;
	colour = PropertyColour::DEFAULT_COLOR;
	rent = 0;
	cottagePrice = 0;
	castlePrice = 0;
	this->ownerName = "";
}

PropertyField::PropertyField(MyString& name, unsigned priceToBuy, PropertyColour& colour, unsigned rent, unsigned cottagePrice, unsigned castlePrice, int index, MyString& description) : Field(index, description)
{
	this->name = name;
	this->priceToBuy = priceToBuy;
	this->colour = colour;
	this->cottagePrice = cottagePrice;
	this->rent = rent;
	this->castlePrice = castlePrice;
	this->ownerName = "";
}

void PropertyField::setOwner(MyString& ownerName)
{
	this->ownerName = ownerName;
}

Field* PropertyField::clone() const
{
	return new PropertyField(*this);
}

void PropertyField::readFromFile(std::ifstream& is)
{
	
	char buffer[1024];
	is.getline(buffer, 1024);

	description = buffer;
	//std::cout << "des " << description << std::endl;
	is >> index;
//	std::cout << "index " << index << std::endl;
	is.ignore();

	int colourType;
	is >> colourType;
	//std::cout << "col " << colourType << std::endl;
	switch (colourType)
	{
	case 1: { colour = PropertyColour::BROWN; break; }
	case 2: { colour = PropertyColour::LIGHT_BLUE; break; }
	case 3: { colour = PropertyColour::PINK; break; }
	case 4: { colour = PropertyColour::ORANGE; break; }
	case 5: { colour = PropertyColour::RED; break; }
	case 6: { colour = PropertyColour::YELLOW; break; }
	case 7: { colour = PropertyColour::GREEN; break; }
	case 8: { colour = PropertyColour::DARK_BLUE; break; }
	default:
		colour = PropertyColour::DEFAULT_COLOR;
	}
	//delete buffer;
	is.ignore();

	char buffer2[1024];
	is.getline(buffer2, 1024);
	//std::cout << buffer2;
	name = buffer2;
	//std::cout << "name " << name << std::endl;
	is >> priceToBuy;
	//std::cout << "p " << priceToBuy;
	is.ignore();
	is >> rent;
	is.ignore();
	is >> cottagePrice;
	is.ignore();
	is >> castlePrice;
	is.ignore();
	
   

}

void PropertyField::printFieldInformation() const
{
	std::cout << description << std::endl;
	std::cout << index << std::endl;
	if (colour == PropertyColour::BROWN)
	{
		std::cout << "Brown" << std::endl;

	}
	else if (colour == PropertyColour::DARK_BLUE)
	{
		std::cout << "Dark Blue" << std::endl;
	}
	else if (colour == PropertyColour::GREEN)
	{
		std::cout << "Green" << std::endl;

	}
	else if (colour == PropertyColour::LIGHT_BLUE)
	{
		std::cout << "Light Blue" << std::endl;

	}
	else if (colour == PropertyColour::ORANGE)
	{
		std::cout << "Orange" << std::endl;
	}
	else if (colour == PropertyColour::PINK)
	{
		std::cout << "Pink" << std::endl;
	}
	else if (colour == PropertyColour::RED)
	{
		std::cout << "Red" << std::endl;
	}
	else if (colour == PropertyColour::YELLOW)
	{
		std::cout << "Yellow" << std::endl;
	}
	else {
		std::cout << "No colour!" << std::endl;
	}
	std::cout << name << std::endl;
	std::cout << "Buy for: " << priceToBuy << std::endl;
	std::cout << "Rent for: " << rent << std::endl;
	std::cout << "Buy cottage for: " << cottagePrice << std::endl;
	std::cout << "Buy castle for: " << castlePrice << std::endl;
}


void PropertyField::applyEffect(Player& player)
{
	Monopoly& monopoly = Monopoly::getInstance();
	Player* owner = monopoly.getPlayerByName(ownerName);
	
	if (owner == nullptr)
	{
		again:
		std::cout << "This property does not have an owner. Do you want to buy it? Yes/No [y/n]" << std::endl;
		std::cout << "Answer: ";
char answer;
		std::cin >> answer;

		switch (answer) {
		case 'y':
		case 'Y': { ownerName = player.getName(); player.setPlayerMoney(player.getPlayersMoney() - priceToBuy);
			break; }
		case 'n':
		case 'N': std::cout << "You did not buy this property."; break;
		default:
			//throws exception
			std::cout << "Invalid answer. Try again.";
			system("pause");
			goto again;
		}
	}
	else {
		std::cout << "This property has an owner. You must pay rent to: "<< ownerName << std::endl;
		
		player.setPlayerMoney(player.getPlayersMoney() - rent);
		owner->setPlayerMoney(owner->getPlayersMoney() + rent);
	}
}


