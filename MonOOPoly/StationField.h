#pragma once
#include "Field.h"
#include "MyString.h"

class StationField : public Field
{
private:
	MyString name;
	//TODO: add player*

public:
	StationField();
	StationField(const MyString& name, int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
};

