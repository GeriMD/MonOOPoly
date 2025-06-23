#pragma once
#include "Field.h"

class JailField : public Field
{
public:
	JailField();
	JailField(int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
};

