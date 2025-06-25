#include "MovePositionCard.h"
#include "Board.h"
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

void MovePositionCard::printCardInformation() const
{
	std::cout << description << std::endl;
	if (positionsCount > 0)
	{
		std::cout << "You have to go to: " << positionsCount << std::endl;
	}
	else {
		std::cout << "You have to go " << positionsCount * (-1) << " positions backwords." << std::endl;
	}
}

bool MovePositionCard::isGetOutOfJail()
{
	return false;
}

void MovePositionCard::applyCard(Player& player)
{
	printDescription();
	player.movePlayerTo(positionsCount);
	Board& board = Board::getInstance();

	board.getField(positionsCount).applyEffect(player);
}
