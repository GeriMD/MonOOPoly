#pragma once

class Command
{
public:
	Command() = default;
	virtual void executeCommand() = 0;
	virtual ~Command() = default;
};

