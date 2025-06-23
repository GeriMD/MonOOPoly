#pragma once
#include "Command.h"

class BuyPropertyCommand : public Command
{
public:
	BuyPropertyCommand() = default;
	virtual void executeCommand() override;
};

