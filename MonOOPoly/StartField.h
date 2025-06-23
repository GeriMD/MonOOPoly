#pragma once
#include "Field.h"

class StartField : public Field
{
public:
	StartField();
	StartField(int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
};

