#pragma once
#include "Command.h"

class SellPropertyToTheBankCommand : public Command
{
public:
	SellPropertyToTheBankCommand() = default;
	virtual void executeCommand() override;
};

