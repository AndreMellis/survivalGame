#include "Engine.h"
#include <utility>
#include <cstdio>

void Engine::populateForests(Forest *pforest)
{
	int amountOfTreeObjects = pforest->getTreeCount() / 5; //we will place one tree on the map for every 5 trees in forest
	
	//place the first tree
	std::pair<int,int> lastPlacedAt = map.getFreeCords();
	map.insertObj(VAR_FORESTASCII, lastPlacedAt);

	printf("%d trees will be placed\n", amountOfTreeObjects);
	
	for (int i = 0; i < amountOfTreeObjects; i++)
	{
		int xCord = lastPlacedAt.first;
		int yCord = lastPlacedAt.second;
		printf("X: %d Y: %d\n", xCord, yCord);
		lastPlacedAt = map.getFreeNeighbor( std::make_pair(13,90) ); //get free cords next to the last tree you placed, not the first
		map.insertObj(VAR_FORESTASCII, lastPlacedAt);
	}
}

void Engine::populateMap()
{
	populateForests(&forest);
}

void Engine::drawMap() { map.drawMap(); }

