#include <iostream>
#include "Card.h"
#include "CardDeck.h"

int main()
{
	CardDeck& deck = CardDeck::getInstance();

	for (int i = 0; i < 22; i++)
	{
		deck.drawCard();
	}
	return 0;

}

