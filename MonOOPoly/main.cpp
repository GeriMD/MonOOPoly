#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include "Board.h"
#include "Monopoly.h"
#include "Dice.h"
int main(){
    std::cout << "Program started." << std::endl;
/*
	Player player;
	player.setPlayerMoney(1500);
	player.setCurrentPosition(0);
	player.setPlayerName("Ivan");
	player.printPlayerInfo();
	Player stationOwner;
	stationOwner.setPlayerMoney(100);
	stationOwner.setPlayerName("Pesho");
	stationOwner.addStation();
	stationOwner.printPlayerInfo();
	Board& board = Board::getInstance();
	std::cout << "Board";
	board.getField(5)->applyEffect(player);
	player.printPlayerInfo();
	stationOwner.printPlayerInfo();
	*/

	/*
	Dice& dice = Dice::getInstance();

	dice.rollDice();

	std::cout << "Sum: " << dice.getSumOfTheDice() << std::endl;
	std::cout << dice.getIsPair() << std::endl;
	*/

	/*
	Player player;
	player.setPlayerMoney(100);
	player.setCurrentPosition(20);

	player.movePlayerTo(23);
	std::cout << "First move: " << player.getCurrentPosition() << std::endl;
	player.movePlayerTo(4);
	std::cout << "Second move: " << player.getCurrentPosition() << std::endl;
	player.movePlayerWith(17);
	std::cout << "Third move: " << player.getCurrentPosition() << std::endl;
	player.movePlayerWith(27);
	std::cout << "Fourth move: " << player.getCurrentPosition() << std::endl;

	std::cout << "Total money earned: " << player.getPlayersMoney() - 100;
	*/


	Monopoly& monopoly = Monopoly::getInstance();
	monopoly.startGame();

	//monopoly.test();
	
	return 0;

}

