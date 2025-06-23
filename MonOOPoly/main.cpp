#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include "Board.h"

int main()
{
    std::cout << "Program started." << std::endl;

    CardDeck& deck = CardDeck::getInstance();

    std::cout << "Card deck initialized." << std::endl;

    for (int i = 0; i < 27; i++)
    {
        std::cout << i << " ";
        deck.drawCard().get()->printCardInformation();
    }
	return 0;

}

