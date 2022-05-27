#include "Snake.h"

void Snake::moveSnake(Fruit fruit)
{
	Location new_loc = cells[0].loc;
	new_loc.add(deltaLoc);
	for (int i = size; i >= 0; i--)
	{
		if (new_loc.equals(cells[i - 1].loc) && i != 0 && counter > 0)
		{
			snakeDead = true;
		}
		cells[i].sym = Source::snakeBody;
		cells[i + 1].loc.set(cells[i].loc);
		if (cells[i].loc.equals(fruit.fLoc))
		{
			fruit.initFruit();
		}
		if (i == 0)
		{
			cells[0].sym = Source::snakeHead;
			cells[0].sym = Source::snakeHead;
			cells[0].loc.add(deltaLoc);
		}
	}
	using namespace Source;
	if (new_loc.x < buffer - 1)
	{
		cells[0].loc.x = width - buffer - 1;
	}
	if (new_loc.x > width - buffer)
	{
		cells[0].loc.x = buffer;
	}
	if (new_loc.y < buffer - 1)
	{
		cells[0].loc.y = height - buffer - 1;
	}
	if (new_loc.y > height - buffer)
	{
		cells[0].loc.y = buffer;
	}
}

bool Snake::testFruit(Location iLoc)
{
	return cells[0].loc.equals(iLoc);
}

void Snake::growSnake()
{
	size++;
	counter++;
	snakeScore += 10;
}
