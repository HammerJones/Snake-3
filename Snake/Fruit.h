#pragma once
//Libraries
#include <stdlib.h>
#include <time.h>
//Header files
#include "Location.h"
#include "Source.h"


class Fruit
{
public:
//Integerss
	int buffer = Source::buffer;
	int rlim = Source::width - (2 * buffer);
	int blim = Source::height - (2 * buffer);

	
//Chars
	
//Strings
	
//Booleanss
	bool isEaten = false;
	
//Objects
	Location fLoc;
	
//functions
	void initFruit()
	{
		int x = rand() % rlim + buffer;
		int y = rand() % blim + buffer;
		
		fLoc = { x,y };
	}
};