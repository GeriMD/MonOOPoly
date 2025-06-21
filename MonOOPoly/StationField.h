#pragma once
#include "Field.h"
#include "MyString.h"

class StationField : public Field
{
private:
	MyString name;

public:
	StationField();
};

