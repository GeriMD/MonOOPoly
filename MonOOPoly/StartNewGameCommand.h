#pragma once
#include "Command.h"

class StartNewGameCommand : public Command
{
public:
	StartNewGameCommand() = default;
	virtual void executeCommand() override;
};

