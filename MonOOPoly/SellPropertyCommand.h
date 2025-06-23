#pragma once
#include "Command.h"

class SellPropertyCommand : public Command
{
public:
	SellPropertyCommand() = default;
	virtual void executeCommand() override;
};

