#pragma once
//Libraries

//Header files
#include "Location.h"
#include "Source.h"
#include "Fruit.h"

class Snake
{
public:
	class Cell
	{
	public:
		Location cellLoc;
	};
	static constexpr int maxSize = Source::maxSize;
	Cell cells[maxSize];
	Location getCellLocation(int curCell);
	void initSnake();
};