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
#include "Cursor.h"


using namespace std;


class Board
{
public:
	Cursor cur; //Used to 
	Location deltaLoc = { 1,0 };
	Snake snake;
	Fruit fruit[Source::maxSize];

	bool gameOver = false;
	bool gamePaused = false;
	bool gameIsStarted = false;
	bool drawn = false;

	int size = Source::size;
	int score = (size - Source::size) * 10;
	int refresh = Source::refresh;
	int fCount = 0;

	static constexpr int width = Source::width + 1;
	static constexpr int height = Source::height;
	static constexpr int lLim = 1;
	static constexpr int rLim = width - 1;
	static constexpr int tLim = 1;
	static constexpr int bLim = height;

	string brd[width][height];
	string scoreMes = Source::scoreMes;
	string gameOverMessage = "GAME OVER!";
	string finalScore = "Final Score: ";

	void composeBoard();
	void getUserInput();
	void updateScore();
	void drawToBoard(Location loc, string str);
	void drawToBoard(Location loc, char str);
	void moveSnake();
	void refreshFrame();
	void testBoarders();
	void initFruit();
	void drawFruit();
	void testFruit();
	void growSnake();
	void drawGameOverMessage();
	void menu();
	void restart();
};