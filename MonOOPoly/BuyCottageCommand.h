#pragma once
#include "Command.h"

class BuyCottageCommand : public Command
{
public:
	BuyCottageCommand() = default;
	virtual void executeCommand() override;
};

