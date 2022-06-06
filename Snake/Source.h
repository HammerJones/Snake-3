#pragma once
//Libraries
#include <string>

#ifndef SOURCE_H
#define SOURCE_H
//Header Files
#include "Location.h"


namespace Source
{
	using namespace std;
	/*----------Symbols---------*/
	static const string border = "#";
	static const string spot = " "; //Char for spots snake can move to
	static const string space = " "; //Empty Char to put 1 space between each spot
									 //Makes Board square
	static const string snakeHead = "O"; //Char for Snake Head
	static const string snakeBody = "o"; //Char for Snake Body
	static const string fruit = "F"; //Char for Fruit
	static const string poison = "P"; //Char for Poison
	/*----------Integers--------*/
	static constexpr int size = 3; //Size of snake
	static constexpr int maxSize = 99;
	static constexpr int score = 0; //Player Score
	
	static constexpr int width = 30; //Board dimmensions
	static constexpr int height = 20; //"              "

	static constexpr int refresh = 250; //Time period between frames
	/*----------Booleans--------*/
	static const bool gameOver = false; //GameOver boolean
	static const bool gameIsPaused = false; //True when player pauses game
	/*----------Strings---------*/
	static const string scoreMes = "Score: "; //Formatted Score 
	static const string info = "[W][A][S][D] to move\n[Q] to quit to menu\n[P] to pause game\n[R] to restart after gameover"; //Movement and controls info
	/*----------Misc Objects----*/
	//Location initLoc = { 3,3 }; //Starting location of Snake
}
#endif