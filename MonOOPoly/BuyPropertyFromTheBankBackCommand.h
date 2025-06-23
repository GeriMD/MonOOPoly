#pragma once
#include "Command.h"

class BuyPropertyFromTheBankBackCommand : public Command
{
public:
	BuyPropertyFromTheBankBackCommand() = default;
	virtual void executeCommand() override;
};

