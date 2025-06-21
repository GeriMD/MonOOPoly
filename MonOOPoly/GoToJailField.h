#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField();
	GoToJailField(int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;

};

