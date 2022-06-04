#include "Board.h"
using std::string;
using std::to_string;


void Board::composeBoard()
{
	//This function serves to initialize the game,
	//Filling the brd array with characters that are then
	//Drawn to the console with drawToBoard()
	snake.initSnake();
	initFruit();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			brd[x][y] = Source::spot;

			
			if(y == 0 || y == height - 1
				|| x == 0 || x == width - 1)
			{
				brd[x][y] = Source::border;
			}
			drawToBoard({ x,y }, brd[x][y]);
		}
	}
}
void Board::menu()
{
	if (!gameIsStarted)
	{
		drawToBoard({ width / 2 - 3, height / 2 - 4}, "S N A K E");
		drawToBoard({ width / 2 - 5, height / 2 - 2}, "[ 1 ] S t a r t");
		drawToBoard({ width / 2 - 5, height / 2  - 1}, "[ 2 ] S e t t i n g s");
	}
}
void Board::initFruit()
{
	srand(time(NULL));

	for (int i = 0; i <= Source::maxSize - 1; i++)
	{
		
		int fWidth = width - 3;
		int fHeight = height - 3;
		int ix = rand() % fWidth + 1;
		int iy = rand() % fHeight + 1;

		Location testFLoc = { ix,iy };

		fruit[i].fLoc.set({ ix, iy });
	}
}
void Board::drawFruit()
{
	drawToBoard(fruit[fCount].fLoc, Source::fruit);
}

//Function that composes every frame and updates position,
//Movement etc.
void Board::refreshFrame()
{
	if (gameIsStarted)
	{
		if (!gameOver && !gamePaused)
		{
			testFruit();
			getUserInput();
			testBoarders();
			moveSnake();
			updateScore();
			Sleep(refresh);
		}
		if (gamePaused)
		{
			getUserInput();
		}
		if (gameOver)
		{
			if (!drawn)
			{
			drawGameOverMessage();
			}
			getUserInput();
		}
	}
	else
	{
		menu();
		getUserInput();
	}
}

//Functions used every frame
void Board::updateScore()
{
	string scoreStr = to_string(score);
	//Creates int representing score string's length
	int scoreLength = scoreMes.length();
	//Prints the standard score message
	cur.printChar({ 0,height }, scoreMes);
	//Prints score after score messagee
	cur.printChar({ scoreLength,height}, scoreStr);
	//Prints basic controls info
	cur.printChar({ 0,height + 1 }, Source::info);
}
void Board::getUserInput()
{
	Location curDLoc = deltaLoc;
	//This if statement only takes user input if the user hits the keyboard
	//Finds what said input is and processes it accordingly
	if (_kbhit())
	{
		char ch = _getch();
		switch (ch)
		{
		case 'W':
		case 'w':
			deltaLoc = { 0,-1 };
			break;
		case 'A':
		case 'a':
			deltaLoc = { -1,0 };
			break;
		case 'S':
		case 's':
			deltaLoc = { 0,1 };
			break;
		case 'D':
		case 'd':
			deltaLoc = { 1,0 };
			break;
		case 'P':
		case 'p':
			gamePaused = !gamePaused;
			//These statements print a pause message to the console if paused
			//And draws over it with spaces so it disappears once started again
			drawToBoard({ width / 2 - 3, height / 2 - 4 }, "P A U S E D");
			if (!gamePaused)
			{
				drawToBoard({ width / 2 - 3, height / 2 - 4 }, "           ");
			}
			break;
		case 'Q':
		case 'q':
			gameOver = true;
			break;
		case '1':
			//This is the main menu input, this might be better used in the 
			//Settings class I want to create to modify game settings
			composeBoard();
			gameIsStarted = true;
			break;
		case 'R':
		case 'r':
			if (gameOver) { restart(); }

		}
	}
	//This Block tests the users input and the current direction 
	//Of the snake, if the snake is moving right this prevents
	//The user from going left immedietly
	Location tLoc = curDLoc;
	tLoc.add(deltaLoc);
	if (tLoc.equals({ 0,0 }))
	{
		deltaLoc = curDLoc;
	}
}
void Board::testBoarders()
{
	Location testLoc = snake.getCellLocation(0);
	testLoc.add(deltaLoc);

	if (testLoc.x >= rLim) //Right Border
	{
		snake.cells[0].cellLoc.x = 0;
	}
	if (testLoc.x <= 0) //Left Border
	{
		snake.cells[0].cellLoc.x = rLim;
	}
	if (testLoc.y >= bLim - 1) //Bottom Border
	{
		snake.cells[0].cellLoc.y = 0;
	}
	if (testLoc.y < 1) //Top Border
	{
		snake.cells[0].cellLoc.y = bLim - 1;
	}
}
void Board::testFruit()
{
	drawFruit();

	if (snake.getCellLocation(0).equals(fruit[fCount].fLoc))
	{
		fCount++;
		score += 10;
		if (refresh - size * 2 >= 50)
		{
			refresh -= 10;
		}
		growSnake();
	}
}
void Board::moveSnake()
{
	snake.cells[0].cellLoc.add(deltaLoc);
	drawToBoard(snake.getCellLocation(size), Source::spot);
	for (int i = size; i > 0; i--)
	{
		if (snake.getCellLocation(0).equals(snake.getCellLocation(i)) && score >= 10)
		{
			gameOver = true;
		}
		snake.cells[i].cellLoc.set(snake.cells[i - 1].cellLoc);
		drawToBoard(snake.getCellLocation(i), Source::snakeBody);
	}
	drawToBoard(snake.getCellLocation(0), Source::snakeHead);
}
void Board::growSnake()
{
	size++;
	for (int i = 0; i < size; i++)
	{
		if (fruit[fCount].fLoc.equals(snake.getCellLocation(i)))
		{
			fruit[fCount].fLoc.add({ 1,1 });
		}
	}
}

//Draws game over message
void Board::drawGameOverMessage()
{
	int gameOverX = (width - finalScore.length()) / 2;
	int gameOverY = height / 2;
	int len = finalScore.length();
	for (int i = 0; i < gameOverMessage.length(); i++)
	{
		char ch = gameOverMessage[i];

		drawToBoard({ gameOverX + 2 + i, gameOverY - 1 }, ch);
		Sleep(100);
	}
	drawToBoard({ gameOverX, gameOverY }, "          ");
	for (int j = 0; j < len; j++)
	{
		drawToBoard({ gameOverX + j, gameOverY + 1 }, finalScore[j]);
		Sleep(100);
	}
	string scoreStr = to_string(score);
	for (int x = 0; x < scoreStr.length(); x++)
	{
		drawToBoard({ gameOverX + x + len, gameOverY + 1}, scoreStr[x]);
		Sleep(100);
	}
	drawn = true;
}
//Handles restarting the game
void Board::restart()
{
		refresh = Source::refresh;
		gameIsStarted = false;
		gameOver = false;
		size = Source::size;
		score = 0;
		finalScore = "Final Score: ";
		cur.printChar({ 0,height }, "              ");
		drawn = false;
		updateScore();
		composeBoard();
}
//Function used to move cursor and draw character
void Board::drawToBoard(Location loc, string str)
{
	//Draws a string to given Location, x is 
	//Multiplied by 2 so board is more square
	//And movement feels more significant
	cur.printChar({ loc.x * 2, loc.y }, str);
}
void Board::drawToBoard(Location loc, char str)
{
	//Overload of previous function, takes char
	//Instead of string, needed for gameover animation
	cur.printChar({ loc.x * 2, loc.y }, str);
}