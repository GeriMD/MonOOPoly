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
