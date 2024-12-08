#ifndef GAME_ENGINE_HEADER
#define GAME_ENGINE_HEADER
#include "WindowRendering.h"
#include <string>
#include <vector>

#define VAR_TILESIZE 50
#define TreeTileWidth 2
#define TreeTileHeight 2

class GameEngine
{
private:
	// objects
	SDL_Event event;
	WindowRendering *windowRenderer;

	// variables
	int columnCount;
	int rowCount;
	
	// all arrays that will be used
	std::vector<std::vector<SDL_Rect>> rectTiles; //a 2d array of all the posible tiles
	std::vector<std::vector<bool>> tileHasChanged; // holds whether or not a tile has changed since last buffering
	std::vector<std::vector<int>> tileContains; // holds what object a tile contains

	//functions
	void genTiles(); //initiate all 60X30 tiles
	bool roomForTree(int x, int y); //makes sure there is room for a tree
	void genTree(int x, int y); //generates a tree at given spot
	std::string getImagePath( int tileContains); //takes in what the tile contains using enum and returns png path


	enum GameObjects {
		EMPTY_OBJ,
		PLAYER_OBJ,
		TREE_OBJ,
		WATER_OBJ
	};

public:
	GameEngine();
	bool processEvent(); //reads input and does stuff - returns 1 if command was to quit, 0 otherwise
	void genRects();
	void printChangedRects(); //loops through tileHasChanged to print the proper object from the tileContains[][] matrix
	SDL_Rect *getMatrixRect(int x, int y) {return &rectTiles[x][y]; } //returns the memory location of the rectangle at x/y in rectTile matrix
	int getColumnCount() { return columnCount; }
	int getRowCount() { return rowCount; }
	bool tileIsFree(int x, int y); //returns true if the tile is free
};



#endif 
