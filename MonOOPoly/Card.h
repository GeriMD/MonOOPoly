#pragma once
#include "MyString.h"

class Card
{
protected:
	MyString description;

public:
	Card();
	Card(const MyString& description);
	virtual ~Card() = default;

	void printDescription() const;
	virtual Card* clone() const = 0;
	//TODO: add interact with player function
};

