#include "MovePositionCard.h"

MovePositionCard::MovePositionCard() : Card()
{
    positionsCount = 1;
}

MovePositionCard::MovePositionCard(int positionsCount, const MyString& description) : Card(description)
{
    this->positionsCount = positionsCount;
}

Card* MovePositionCard::clone() const
{
    return new MovePositionCard(*this);
}

int MovePositionCard::getPositionCount() const
{
    return this->positionsCount;
}

void MovePositionCard::readFromFile(std::ifstream& is)
{
	char buffer[1024];
	
	is.getline(buffer, 1024);

	description = buffer;
	is >> positionsCount;
is.ignore();
}
