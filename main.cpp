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

	for(int RowY = 0; RowY < VAR_ROWCOUNT; RowY++)
	{
		for(int RowX = 0; RowX  < VAR_COLUMNCOUNT; RowX ++)
		{
			printf("Rendering X %d Y %d\n", RowX, RowY);
			windowRenderer->renderToBuffer( "square.png", engine.getMatrixRect(RowX, RowY) );
		}
	}

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
