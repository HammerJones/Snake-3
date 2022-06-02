#include "Snake.h"

Location Snake::getCellLocation(int curCell)
{
	return cells[curCell].cellLoc;
}

void Snake::initSnake()
{
	for (int i = Source::size; i >= 0; i--)
	{
		cells[i].cellLoc.set({ 10, 10 });
	}
}
