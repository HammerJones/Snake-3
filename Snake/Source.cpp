//Libraries
#include <iostream>
#include <windows.h>
#include <string>
//Header Files
#include "Source.h"
#include "Board.h"
#include "Snake.h"
#include "Cursor.h"
/*--------------------------------------------------------------------*/
using namespace std;


void set_cursor(bool visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main()
{
	Board brd;
	brd.composeBoard();
	while (true)
	{
		set_cursor(false);
		brd.refreshFrame();
	}
}