#pragma once
#include <iostream>
#include <string>
#include <windows.h>
//-----------------//
#include "Location.h"


using namespace std;


class Cursor
{
	Location curLoc = { 0,0 };
public:
	void printChar(Location loc, string str);
};