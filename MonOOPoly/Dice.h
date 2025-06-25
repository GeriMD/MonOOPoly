#pragma once
#include <ctime>
#include <random>
#include <iostream>
class Dice
{

private:
	int sumOfTheDice;
	bool isPair;
Dice() = default;
public:
	Dice(const Dice& other) = delete;
	
	Dice& operator=(const Dice& other) = delete;
	void rollDice();
	static Dice& getInstance();
	int getSumOfTheDice() const;
	bool getIsPair() const;
};

