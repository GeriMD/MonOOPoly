#pragma once
#include "Field.h"
#include "MyString.h"
#include "Player.h"

class StationField : public Field
{
private:
	MyString name;
	Player* owner = nullptr;

public:
	StationField();
	StationField(const MyString& name, int index, const MyString& description);
	
	void setOwner(Player* owner);
	

	virtual Field* clone() const override;
	virtual void readFromFile(std::ifstream& is) override;
	virtual void printFieldInformation() const override;
	virtual void applyEffect(Player& player) override;
};

