#pragma once
#include "Command.h"
#include "BuyPropertyCommand.h"
#include "DrawCardCommand.h"
#include "ExitGameCommand.h"
#include "ResumeOldGameCommand.h"
#include "RollDiceCommand.h"
#include "SaveGameCommand.h"
#include "SellPropertyCommand.h"
#include "StartNewGameCommand.h"
#include "BuyCastleCommand.h"
#include "BuyCottageCommand.h"
#include "SellPropertyToTheBankCommand.h"
#include "BuyPropertyFromTheBankBackCommand.h"
#include "MyString.h"

class CommandFactory
{
public:
	Command* readCommand(const MyString& command) const;
	static CommandFactory& getInstance();
};

