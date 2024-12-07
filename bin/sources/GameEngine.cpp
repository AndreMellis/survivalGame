#include "GameEngine.h"
#include <stdio.h>

GameEngine::GameEngine()
{
	windowRenderer = WindowRendering::getInstance();
}

bool GameEngine::processEvent()
{ //processes events and will return 1 if event was quit
	while (SDL_PollEvent(&event))
	{//process event queue
		if (event.type == SDL_QUIT)
		{// user pressed the red X
			windowRenderer->close();
			return 1;
		} else if (event.type == SDL_KEYDOWN)
		{ // user pressed a keyboard key
			switch(event.key.keysym.sym)
			{ // what key did they press?
				case SDLK_ESCAPE:
					windowRenderer->close();
					return 1;
					break;
			}
		}
	}
	return 0;
}

void GameEngine::genRects()
{
	int x = 0;
	int y = 0;

	for(int RowY = 0; RowY < VAR_ROWCOUNT; RowY++)
	{
		for(int RowX = 0; RowX  < VAR_COLUMNCOUNT; RowX ++)
		{
			rectTiles[RowX][RowY].x = x;
			rectTiles[RowX][RowY].y = y;
			rectTiles[RowX][RowY].w = x + VAR_TILESIZE;
			rectTiles[RowX][RowY].h = y + VAR_TILESIZE;
			printf("rectiles[%d][%d] is X: %d Y: %d W: %d H: %d\n", RowX, RowY, rectTiles[RowX][RowY].x, rectTiles[RowX][RowY].y, rectTiles[RowX][RowY].w, rectTiles[RowX][RowY].h );
			
			x += VAR_TILESIZE;
		} 
		x = 0; //x would reset for every row
		y = y + VAR_TILESIZE;
	}
}
