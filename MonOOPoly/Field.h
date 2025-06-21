#pragma once
#include "MyString.h"
#include <iostream>
#include <fstream>

class Field
{
protected:
	int index; // TODO: maybe make indexes unsigned?
	MyString description;

public:
	Field();
	Field(int index, const MyString& description);
	virtual ~Field() = default;

	void printDescription() const;
	int getFieldIndex() const;
	virtual Field* clone() const = 0;
	virtual void readFromFile(std::ifstream& is) = 0;
};

