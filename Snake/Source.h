#pragma once
//Libraries
#include <string>

#ifndef SOURCE_H
#define SOURCE_H
//Header Files
#include "Location.h"


namespace Source
{
//Integerss
	const int score = 0;
	const int refresh = 100;
	static constexpr int width = 30;
	static constexpr const int height = 20;
	
	const int buffer = 1;

	const int leftBorder = buffer * 2;
	const int topBorder = buffer * 2;
	const int rightBorder = width - (2 * buffer);
	const int bottomBorder = width - (2 * buffer);

	const int maxSize = 99;
	const int size = 5;

//Chars
	const char snakeHead = 'O';
	const char snakeBody = 'o';
	const char fruit = 'F';
	const char border = '#';
	const char blank = '.';

//Strings
	const std::string gameOverMessage = "Game Over!";
	const std::string gameOverMessage2 = "Final Score: ";
	const std::string cScore = "Score: ";
	const std::string info = "\nPress WASD to move Q to quit";

//Booleanss
	const bool gameOver = false;

//Objects
	const Location startingLoc = { 5,5 };
}
#endif