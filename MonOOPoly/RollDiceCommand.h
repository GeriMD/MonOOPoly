#pragma once
#include "Command.h"
#include "Dice.h"
#include "Monopoly.h"
class RollDiceCommand : public Command
{
private:
	Dice& dice = Dice::getInstance();
	Monopoly& monopoly = Monopoly::getInstance();
	Board& board = Board::getInstance();
public:
	RollDiceCommand() = default;
	virtual void executeCommand() override;
};

