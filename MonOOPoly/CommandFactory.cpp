#include "CommandFactory.h"

Command* CommandFactory::readCommand(const MyString& command) const
{
	if (command == "buy_property")
	{
		return new BuyPropertyCommand();
	}
	else if (command == "exit")
	{
		return new ExitGameCommand();
	}
	else if (command == "resume")
	{
		return new ResumeOldGameCommand();
	}
	else if (command == "roll")
	{
		return new RollDiceCommand();
	}
	else if (command == "save")
	{
		return new SaveGameCommand();
	}
	else if (command == "trade")
	{
		return new SellPropertyCommand();
	}
	else if (command == "start")
	{
		return new StartNewGameCommand();
	}
	else if (command == "buy_castle")
	{
		return new BuyCastleCommand();
	}
	else if (command == "buy_cottage")
	{
		return new BuyCottageCommand();
	}
	else if (command == "sell_bank")
	{
		return new SellPropertyToTheBankCommand();
	}
	else if (command == "buy_bank")
	{
		return new BuyPropertyFromTheBankBackCommand();
	}
	else {
		return nullptr;
		//throw std::invalid_argument("Invalid command!");
		//TODO: handle exception 
	}
}

CommandFactory& CommandFactory::getInstance()
{
	 static CommandFactory instance;
	 return instance;
}
