#pragma once
#include "Field.h"
#include "ServiceType.h"
#include "Monopoly.h"
class ServiceField : public Field
{
private:
	ServiceType type;
	MyString ownerName;

public:
	ServiceField();
	ServiceField(ServiceType& type, int index, const MyString& description);

	void setOwner(MyString& ownerName);
	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

