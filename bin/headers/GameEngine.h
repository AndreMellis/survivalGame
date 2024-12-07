#ifndef GAME_ENGINE_HEADER
#define GAME_ENGINE_HEADER
#include "WindowRendering.h"

//#define VAR_COLUMNCOUNT 60
//#define VAR_ROWCOUNT 30
#define VAR_TILESIZE 30

#define VAR_COLUMNCOUNT 2
#define VAR_ROWCOUNT 2

class GameEngine
{
private:
	SDL_Event event;
	WindowRendering *windowRenderer;
	SDL_Rect rectTiles[60][30]; //a 2d array of all the posible tiles

	void genTiles(); //initiate all 60X30 tiles

public:
	GameEngine();
	bool processEvent(); //reads input and does stuff - returns 1 if command was to quit, 0 otherwise
	void genRects();
	SDL_Rect *getMatrixRect(int x, int y) {return &rectTiles[x][y]; } //returns the memory location of the rectangle at x/y in rectTile matrix
};



#endif 
