#include "Board.h"
using std::string;
using std::to_string;

void Board::composeBoard()
{
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

void Board::getUserInput()
{
	Location curDLoc = deltaLoc;

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
			growSnake();
			break;
		case 'Q':
		case 'q':
			fCount++;
			break;
		}
	}
	Location tLoc = curDLoc;
	tLoc.add(deltaLoc);
	if (tLoc.equals({ 0,0 }))
	{
		deltaLoc = curDLoc;
	}
}

void Board::updateScore()
{
	string scoreStr = to_string(score);
	int scoreLength = scoreMes.length();

	cur.printChar({ 0,height }, scoreMes);
	cur.printChar({ scoreLength,height}, scoreStr);
	cur.printChar({ 0,height + 1 }, Source::info);
}

void Board::drawToBoard(Location loc, string str)
{
	cur.printChar({ loc.x * 2, loc.y }, str);
}

void Board::moveSnake()
{
	snake.cells[0].cellLoc.add(deltaLoc);
	drawToBoard(snake.getCellLocation(size), Source::spot);
	for (int i = size; i > 0; i--)
	{
		snake.cells[i].cellLoc.set(snake.cells[i - 1].cellLoc);
		drawToBoard(snake.getCellLocation(i), Source::snakeBody);
	}
	drawToBoard(snake.getCellLocation(0), Source::snakeHead);
}

void Board::refreshFrame()
{
	testFruit();
	getUserInput();
	testBoarders();
	moveSnake();
	updateScore();
	Sleep(refresh);
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

void Board::testFruit()
{
	drawFruit();

	if (snake.getCellLocation(0).equals(fruit[fCount].fLoc))
	{
		fCount++;
		score += 10;
		if (refresh - size * 2 >= 50)
		{
			refresh -= size * 2;
		}
		growSnake();
	}
}

void Board::growSnake()
{
	size++;
}
