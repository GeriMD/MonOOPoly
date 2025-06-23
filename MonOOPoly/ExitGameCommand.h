#pragma once
#include "Command.h"

class ExitGameCommand : public Command
{
public:
	ExitGameCommand() = default;
	virtual void executeCommand() override;
};

