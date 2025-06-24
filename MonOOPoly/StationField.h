#pragma once
#include "Field.h"
#include "MyString.h"
#include "Player.h"
#include "Monopoly.h"
class StationField : public Field
{
private:
	MyString name;
	MyString ownerName;
	Monopoly& monopoly = Monopoly::getInstance();
public:
	StationField();
	StationField(const MyString& name, int index, const MyString& description);
	
	void setOwner(MyString& ownerName);
	

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

