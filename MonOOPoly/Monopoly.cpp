#include "Monopoly.h"


int Monopoly::getCurrPlayerIndex() const
{
    return currentPlayerIndex;
}

bool Monopoly::isGameOver() const
{
    return gameOver;
}

Player& Monopoly::getPlayer(int index)
{
    return players[index];
}

int Monopoly::getPlayersCount() const
{
    return players.size();
}

void Monopoly::addPlayer(const Player& player)
{
    players.push_back(player);
}



