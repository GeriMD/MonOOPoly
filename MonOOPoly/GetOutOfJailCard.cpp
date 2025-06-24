#include "GetOutOfJailCard.h"

GetOutOfJailCard::GetOutOfJailCard() : Card()
{
}

GetOutOfJailCard::GetOutOfJailCard(const MyString& description) : Card(description)
{
}

Card* GetOutOfJailCard::clone() const
{
    return new GetOutOfJailCard(*this);
}

void GetOutOfJailCard::readFromFile(std::ifstream& is)
{
	char buffer[1024];
	is.ignore();
	is.getline(buffer, 1024);

	description = buffer;
	

}

void GetOutOfJailCard::printCardInformation() const
{
	std::cout << description << std::endl;
}

bool GetOutOfJailCard::isGetOutOfJail()
{
	return true;
}

void GetOutOfJailCard::applyCard(Player& player)
{
	//TODO: Ask if it wants to get or sell it!
	printDescription();
	player.setHasGetOOJCard();
}
