#pragma once
//Libraries
#ifdef _WIN32
#include <Windows.h>
#endif
#include <string>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <vector>
//Header files
#include "Source.h"
#include "Snake.h"
#include "Fruit.h"

using namespace std;


class Board
{
public:
//Integerss
	static constexpr int height = Source::height;
	static constexpr int width = Source::width;
	int goHeight = Source::height / 2;
	int goWidth = (width - Source::gameOverMessage.length()) / 2;
//Chars
	char border = Source::border;
	char blank = Source::blank;
//Strings
	std::string message = Source::gameOverMessage2;
	std::string brd[height][width];
//Booleanss
	bool gameOver = Source::gameOver;
//Objects
	Snake snake;
	Fruit fruit[Source::maxSize];
//functions
	void getUserInput();
	void composeBoard();
	void drawBoard();
	void initFruits();
};