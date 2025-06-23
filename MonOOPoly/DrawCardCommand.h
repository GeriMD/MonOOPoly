#pragma once
#include "Command.h"

class DrawCardCommand : public Command
{
public:
	DrawCardCommand() = default;
	virtual void executeCommand() override;
};

