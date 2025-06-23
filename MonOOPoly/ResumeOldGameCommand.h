#pragma once
#include "Command.h"

class ResumeOldGameCommand : public Command
{
public:
	ResumeOldGameCommand() = default;
	virtual void executeCommand() override;
};

