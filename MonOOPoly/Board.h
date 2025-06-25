#pragma once
#include "Field.h"

class Board
{
private:
	Field* fields[40];
	Board();
	~Board();

public:
	Board(const Board& other) = delete;
	Board& operator=(const Board& other) = delete;
	Field* createField(int type);
	Field& getField(int index) const;
	static Board& getInstance();
};

