#include "GameEngine.h"
#include "WindowRendering.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main(int argc, char *argv[]) {
	srand(time(0));

	WindowRendering *windowRenderer = WindowRendering::getInstance();
	GameEngine engine;
	engine.genRects();

	windowRenderer->clearBuffer();

	for(int column = 0; column < engine.getColumnCount(); column++)
	{
		for(int row = 0; row < engine.getRowCount(); row++)
		{
			windowRenderer->renderToBuffer("assets/textures/grass.png", engine.getMatrixRect(column,row));
		}
	}

	windowRenderer->renderToBuffer("assets/textures/dirt.png", engine.getMatrixRect(15,15));

	windowRenderer->renderPresent();

	bool eventWasQuit = 0;
	do 
	{
		eventWasQuit = engine.processEvent(); //process event queue and save exit as 1
	} while ( !eventWasQuit );


	/*

	//splash screen

	SDL_Rect fullWindow;
	fullWindow.x = 0;
	fullWindow.y = 0;
	fullWindow.h = windowRenderer->getWindowH();
	fullWindow.w = windowRenderer->getWindowW();
	
	windowRenderer->renderToBuffer("splashscreen.png", &fullWindow);

	*/




	/*
	Menus menu;
	MainMap *pMap = MainMap::getInstance();
	Inventory *inv = Inventory::getInstance();
	Engine engine;

	engine.populateMap();
	do
	{
		pMap->drawMap();
		menu.printControls();
		inv->printInv();
		engine.getInput();

	} while(1);
	*/

	return 0;

}
