#pragma once
//Libraries

//Header files
#include "Location.h"
#include "Source.h"
#include "Fruit.h"

class Snake
{
public:
	class Body
	{
	public:
		Location loc = Source::startingLoc;
		bool onFruit = false;
		char sym = Source::snakeBody;
	};
//Integerss
	int size = Source::size;
	int snakeScore = 0;
	int counter = 0;

//Chars
//Strings
//Booleanss
	bool snakeDead = false;
//Objects
	Body cells[Source::maxSize];
	Location deltaLoc = { 1,0 };
//functions
	void growSnake();
	void moveSnake(Fruit fruit);
	bool testFruit(Location fruit);
};