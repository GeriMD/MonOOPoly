#include "PaymentCard.h"

PaymentCard::PaymentCard() 
{
    amount = 0;
}

PaymentCard::PaymentCard(int amount) 
{
    this->amount = amount;
}

Card* PaymentCard::clone() const
{
    return new PaymentCard(*this);
}
