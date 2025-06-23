#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include "Board.h"

int main()
{
    std::cout << "Program started." << std::endl;

	Player player;
	player.setPlayerMoney(1500);
	player.setCurrentPosition(0);
	player.setPlayerName("Ivan");

	Player stationOwner;
	stationOwner.setPlayerMoney(100);
	stationOwner.setPlayerName("Pesho");
	stationOwner.addStation();

	Board& board = Board::getInstance();
	
	board.getField(5)->applyEffect(player);
	player.printPlayerInfo();
	stationOwner.printPlayerInfo();
	return 0;

}

