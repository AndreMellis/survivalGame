#include "Engine.h"
#include "MainMap.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <iostream>

int main() {
	srand(time(0));

	Engine engine;
	MainMap *pMap = MainMap::getInstance();

	engine.populateMap();
	do
	{
		engine.drawMap();
		pMap->movePlayer();
	} while(1);

	return 0;

}
