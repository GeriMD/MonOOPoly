#include "CardDeck.h"
#include "MyString.h"
#include <fstream>
#include "Constants.h"
#include <stdexcept>
#include "AllPlayersPaymentCard.h"
#include "PaymentCard.h"
#include "MovePositionCard.h"
#include "GetOutOfJailCard.h"
#include "Board.h"

CardDeck::CardDeck()
{
    std::ifstream file(Constants::CARDS_FILE_NAME);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open Cards file!");

    }

    for (int i = 0; i < 21; i++)
    {
        int type;
        file >> type;
        file.ignore();
        Card* currentCard = createCard(type);
        
        currentCard->readFromFile(file);
        
        deck.push(currentCard);

    }

    file.close();
    // TODO: make constant
}

Card* CardDeck::createCard(int type)
{
    switch (type)
    {
    case 1: return new PaymentCard(); 
    case 2: return new AllPlayersPaymentCard();
    case 3: return new MovePositionCard();
    case 4: return new GetOutOfJailCard();
    }

    return nullptr; // TODO: throw an exception
}

PolymorphicPtr<Card> CardDeck::drawCard()
{
    if (deck.isEmpty())
    {
        throw std::runtime_error("There are no cards in the deck!");

    }
    PolymorphicPtr<Card> currentCard = deck.peek();
    deck.pop();

    if (!currentCard.get()->isGetOutOfJail())
    {
        //TODO: Add logic!
        // only for the test:
deck.push(currentCard);
    }
    

    return currentCard;
}


CardDeck& CardDeck::getInstance()
{
    static CardDeck instance;
    return instance;
}
