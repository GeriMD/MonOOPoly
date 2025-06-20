#pragma once
#include "Queue.hpp"
#include "Card.h"
#include "PolymorphicPtr.hpp"

class CardDeck
{
private:
	Queue<PolymorphicPtr<Card>> deck; 
	CardDeck();

public:
	CardDeck(const CardDeck& other) = delete;
	CardDeck& operator=(const CardDeck& other) = delete;
	Card* createCard(int type);
	PolymorphicPtr<Card> drawCard();
	static CardDeck& getInstance();
};

