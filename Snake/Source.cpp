//Libraries
#include <iostream>

//Header Files
#include "Source.h"
#include "Board.h"
#include "Snake.h"
/*--------------------------------------------------------------------*/
using namespace std;


bool menu()
{
	bool gameStart = false;
	string howToPlay = "How to play Snake:\nOnce you press start your snake (`O`) will spawn\nas well as a piece of fruit (`F`), Use WASD to navigate\nAnd eat the fruit\nOnce you eat a piece of fruit, \na new piece spawns and 10 is added to your score.\nView your score at the bottom of the screen next to `Score:\n`Press [1][2] to Start";
	string Menu = "\nSNAKE\n\n[1]Start\n[2]How To Play";
	char ch = 0;

	cout << Menu;

	ch = _getch();
	switch (ch)
	{
	case '1':
		return true;
		break;
	case '2':
		cout << howToPlay;
		ch = _getch();
		if (ch == '1')
		{
			return true;
		}
		break;
	}

}

int main()
{
	while (!menu())
	{
		menu();
	}
	Board brd;
	brd.initFruits();
	while (!brd.gameOver)
	{
		brd.drawBoard();
	}
	//brd.drawBoard();
	_getch();
}