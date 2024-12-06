#include "GameEngine.h"

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

void GameEngine::worldGen()
{ //generates world 
}
