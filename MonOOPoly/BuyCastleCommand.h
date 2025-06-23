#pragma once
#include "Command.h"

class BuyCastleCommand : public Command
{
public:
	BuyCastleCommand() = default;
	virtual void executeCommand() override;
};

