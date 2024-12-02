#include "Engine.h"
#include "MainMap.h"
#include "Menus.h"
#include "Inventory.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main() {
	srand(time(0));


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

	return 0;

}
