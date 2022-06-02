#include "Cursor.h"

void Cursor::printChar(Location loc, string str)
{
	curLoc.equals(loc);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {loc.x, loc.y};
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << str;
}
