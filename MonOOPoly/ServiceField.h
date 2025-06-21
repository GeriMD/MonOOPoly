#pragma once
#include "Field.h"
#include "ServiceType.h"

class ServiceField : public Field
{
private:
	ServiceType type;
	// TODO: add player*
public:
	ServiceField();
	ServiceField(ServiceType& type, int index, const MyString& description);

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
};

