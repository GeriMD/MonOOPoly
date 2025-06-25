#include "RollDiceCommand.h"

void RollDiceCommand::executeCommand()
{
	int playerIndex = monopoly.getCurrentPlayerIndex();

	Player& player = monopoly.getPlayer(playerIndex);

	

	dice.rollDice();
	if (player.getCurrentPosition() == 10 && player.getIsInJail() && dice.getIsPair())
	{
		std::cout << "You rolled pair so you can go out of the prison in the next turn!" << std::endl;
		player.getOutOfJail();
	}
	else if(player.getCurrentPosition() == 10 && player.getIsInJail()){
		std::cout << "You didn't roll a pair so you must pay 100 BGN to get out of jail or stay in for the next move. Pay/Not[p/n]" << std::endl;

		char answer;
		std::cin >> answer;

		switch (answer)
		{
		case 'y': { player.setPlayerMoney(player.getPlayersMoney() - 100); monopoly.playTurn(playerIndex + 1); return; }
		case 'n': monopoly.playTurn(playerIndex + 1); return;
			//TODO: check if the player has enough money
		}
	}

	player.movePlayerWith(dice.getSumOfTheDice());
	Field* field = board.getField(player.getCurrentPosition());
	field->applyEffect(player); // TODO: may cause a problem!

	monopoly.playTurn(playerIndex + 1);
}
