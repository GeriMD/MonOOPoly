#include "CommandFactory.h"
#include "RollDiceCommand.h"
Command* CommandFactory::readCommand(const MyString& command) const
{
	
	if (command == "roll")
	{
		return new RollDiceCommand();
	}
	
	
}

CommandFactory& CommandFactory::getInstance()
{
	 static CommandFactory instance;
	 return instance;
}
