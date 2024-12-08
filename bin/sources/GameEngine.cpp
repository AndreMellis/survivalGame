#include "GameEngine.h"
#include <stdio.h>
#include <string>

GameEngine::GameEngine()
{
	windowRenderer = WindowRendering::getInstance();
	columnCount = windowRenderer->getWindowW() / VAR_TILESIZE;
	rowCount = windowRenderer->getWindowH() / VAR_TILESIZE;

	rectTiles.resize(columnCount); //resize rect tiles to be rectTiles[columnCount][]
	for(int i = 0; i < columnCount; i++)
	{ // resize rect tiles to be rectTiles[columnCount][rowCount]
		rectTiles[i].resize(rowCount);
	}

	tileHasChanged.resize(columnCount); //resize rect tiles to be rectTiles[columnCount][]
	for(int i = 0; i < columnCount; i++)
	{ // resize rect tiles to be rectTiles[columnCount][rowCount]
		tileHasChanged[i].resize(rowCount);
	}

	tileContains.resize(columnCount); //resize rect tiles to be rectTiles[columnCount][]
	for(int i = 0; i < columnCount; i++)
	{ // resize rect tiles to be rectTiles[columnCount][rowCount]
		tileContains[i].resize(rowCount);
	}

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

	for(int RowY = 0; RowY < rowCount; RowY++)
	{
		for(int RowX = 0; RowX  < columnCount; RowX ++)
		{
			rectTiles[RowX][RowY].x = x;
			rectTiles[RowX][RowY].y = y;
			rectTiles[RowX][RowY].w = VAR_TILESIZE; //it willl always be a 30x30 square. only offset the x/y
			rectTiles[RowX][RowY].h = VAR_TILESIZE; //it willl always be a 30x30 square. only offset the x/y
			//printf("rectiles[%d][%d] is X: %d Y: %d W: %d H: %d\n", RowX, RowY, rectTiles[RowX][RowY].x, rectTiles[RowX][RowY].y, rectTiles[RowX][RowY].w, rectTiles[RowX][RowY].h );
			
			x += VAR_TILESIZE;
		} 
		x = 0; //x would reset for every row
		y = y + VAR_TILESIZE;
	}
}


void GameEngine::printChangedRects()
{ //loops through tileHasChanged to print the proper object from the tileContains[][] matrix
	for(int y = 0; y < rowCount; y++)
	{
		for(int x = 0; x < columnCount; x++)
		{
			if(tileHasChanged[x][y])
			{ //the tile has changed
				tileHasChanged[x][y] = 0; //reset it
				windowRenderer->renderToBuffer( getImagePath(tileContains[x][y]), &rectTiles[x][y] ); 
			}
		}
	}
}

std::string GameEngine::getImagePath( int tileContains)
{ //takes in what the tile contains using enum and returns png path
	switch (tileContains)
	{
		case EMPTY_OBJ:
			return ""; //print an empty png to clear
		case PLAYER_OBJ:
			return "assets/sprites/player.png";
		case TREE_OBJ:
			return "assets/objects/tree.png";
		case WATER_OBJ:
			return "assets/textures/water.png";
	}
	return "";
}

bool GameEngine::tileIsFree(int x, int y)
{ //returns true if the tile is free
	return tileContains[x][y] == EMPTY_OBJ;
}

bool GameEngine::roomForTree(int x, int y)
{//makes sure there is room for a tree
	if ( y  > 1 && tileIsFree(x, y-1) )
	{ // top is free
		if ( x > 1 && tileIsFree(x-1, y) )
		{ // left is free
			if ( tileIsFree(x-1,y-1) )
			{ //topleft is free
				return 1;
			}
		}
		if ( x < (columnCount-1) && tileIsFree(x+1, y))
		{ // right is free
			if (tileIsFree(x+1,y-1))
			{ //top right is free
				return 1;
			}
		}
	} 
	if ( y < (rowCount-1) && tileIsFree(x,y+1))
	{ //bottom is free
		if ( x > 1 && tileIsFree(x-1, y) )
		{ // left is free
			if( tileIsFree( x-1, y+1) )
			{ //bottom left is free
				return 1;
			}
		}
		if ( x < (columnCount-1) && tileIsFree(x+1, y))
		{ // right is free
			if( tileIsFree(x+1,y+1) )
			{ // bottom right is free
				return 1;
			}
		}
	}
	return 0;
}

void GameEngine::genTree(int x, int y)
{ // generates a tree at given spot
	// need to find where to put the tree
	// set all four tileContains[][] to TREE_OBJ
	// set all four tileHasChanged to true
	if ( y  > 1 && tileIsFree(x, y-1) )
	{ // top is free
		if ( x > 1 && tileIsFree(x-1, y) )
		{ // left is free
			if ( tileIsFree(x-1,y-1) )
			{ //topleft is free
				return 1;
			}
		}
		if ( x < (columnCount-1) && tileIsFree(x+1, y))
		{ // right is free
			if (tileIsFree(x+1,y-1))
			{ //top right is free
				return 1;
			}
		}
	} 
	if ( y < (rowCount-1) && tileIsFree(x,y+1))
	{ //bottom is free
		if ( x > 1 && tileIsFree(x-1, y) )
		{ // left is free
			if( tileIsFree( x-1, y+1) )
			{ //bottom left is free
				return 1;
			}
		}
		if ( x < (columnCount-1) && tileIsFree(x+1, y))
		{ // right is free
			if( tileIsFree(x+1,y+1) )
			{ // bottom right is free
				return 1;
			}
		}
	}
}
