#pragma once
#include "Command.h"

class RollDiceCommand : public Command
{
public:
	RollDiceCommand() = default;
	virtual void executeCommand() override;
};

