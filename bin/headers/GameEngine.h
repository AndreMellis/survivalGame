#ifndef GAME_ENGINE_HEADER
#define GAME_ENGINE_HEADER
#include "WindowRendering.h"

class GameEngine
{
private:
	SDL_Event event;
	WindowRendering *windowRenderer;

public:
	GameEngine();
	bool processEvent(); //reads input and does stuff - returns 1 if command was to quit, 0 otherwise
	void worldGen(); //does the initial world generation

};



#endif 
