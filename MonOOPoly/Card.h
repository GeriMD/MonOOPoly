#pragma once
#include "MyString.h"
#include <fstream>


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
	virtual void readFromFile(std::ifstream& is) = 0;
	virtual void printCardInformation() const = 0;
	virtual bool isGetOutOfJail() = 0;
	//TODO: add interact with player function
};

