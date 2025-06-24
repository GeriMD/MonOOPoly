#pragma once
#include "Command.h"
#include "MyString.h"

class CommandFactory
{
public:
	Command* readCommand(const MyString& command) const;
	static CommandFactory& getInstance();
};

