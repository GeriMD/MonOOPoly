#include "GetOutOfJailCard.h"

Card* GetOutOfJailCard::clone() const
{
    return new GetOutOfJailCard(*this);
}
