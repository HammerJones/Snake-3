#include "Board.h"
using std::string;
using std::to_string;

void Board::getUserInput()
{
	char ch = 0;

	if (_kbhit()) {
		ch = _getch();
		switch (ch)
		{
		case 'W':
		case 'w':
			snake.deltaLoc = { 0,-1 };
			break;
		case 'A':
		case 'a':
			snake.deltaLoc = { -1,0 };
			break;
		case 's':
		case 'S':
			snake.deltaLoc = { 0,1 };
			break;
		case 'D':
		case 'd':
			snake.deltaLoc = { 1,0 };
			break;
		case 'Q':
		case 'q':
			gameOver = true;
			break;
		case 'P':
		case 'p':
			fruit[snake.counter].initFruit();
			break;
		}
	}
	

}

void Board::composeBoard()
{
	if (gameOver)
	{
		message.append(std::to_string(snake.snakeScore));
	}
	if (snake.testFruit(fruit[snake.counter].fLoc))
	{
		fruit[snake.counter].isEaten = true;
		snake.growSnake();
	}
	getUserInput();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			brd[i][j] = blank;
			if (i == 0)
			{
				brd[i][j] = border;
			}
			if (i == height - 1)
			{
				brd[i][j] = border;
			}
			if (j == 0)
			{
				brd[i][j] = border;
			}
			if (j == width - 1)
			{
				brd[i][j] = border;
			}
			if (gameOver)
			{
				if (j > goWidth - 1 && j < goWidth + Source::gameOverMessage.length())
				{
					brd[goHeight - 1][j] = Source::gameOverMessage[j - goWidth];
				}
				if (j > goWidth - 1 && j < goWidth + message.length())
				{
					brd[goHeight][j] = message[j - goWidth];
				}
			}
		}
	}
	if (!fruit[snake.counter].isEaten)
	{
		brd[fruit[snake.counter].fLoc.y][fruit[snake.counter].fLoc.x] = Source::fruit;
	}

	snake.moveSnake(fruit[snake.counter]);
	
	for (int x = 0; x < snake.size; x++)
	{
		brd[snake.cells[x].loc.y][snake.cells[x].loc.x] = snake.cells[x].sym;
	}
}

void Board::drawBoard()
{
	gameOver = snake.snakeDead;
	composeBoard();
	system("CLS");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << brd[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << Source::cScore << snake.snakeScore << Source::info;
	//std::cout << "\nFruit Location: " << fruit[snake.counter].fLoc.x << fruit[snake.counter].fLoc.y;
	Sleep(Source::refresh);
}

void Board::initFruits()
{
	srand(time(NULL));

	for (int i = 0; i < Source::maxSize; i++)
	{
		fruit[i].initFruit();
	}
}
