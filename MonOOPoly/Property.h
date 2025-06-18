#pragma once
#include "PropertyColour.h"
#include "MyString.h"

class Property
{
protected:
	PropertyColour colour = PropertyColour::DEFAULT;
	MyString name = nullptr;
	unsigned price = 0;

};

