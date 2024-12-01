#include "Engine.h"
#include <utility>
#include <cstdio>

MainMap *pMap = MainMap::getInstance();

void Engine::populateForests(Forest *pforest)
{
	int amountOfTreeObjects = pforest->getTreeCount() / 5; //we will place one tree on the pMap for every 5 trees in forest
	
	std::pair<int,int> lastPlacedAt = pMap->getFreeCords();
	do
	{
		pMap->insertObj(VAR_FORESTASCII, lastPlacedAt);
		lastPlacedAt = pMap->getFreeNeighbor( lastPlacedAt ); //get free cords next to the last tree you placed
		amountOfTreeObjects--;
	} while (amountOfTreeObjects > 0 && lastPlacedAt != std::make_pair(0,0) );
}

void Engine::populateMap()
{
	populateForests(&forest);
	
	std::pair<int,int> playerCords = pMap->getFreeCords();
	pMap->insertPlayer( playerCords ); //place the player at the very end
}

void Engine::drawMap()
{
	pMap->drawMap();
}

void Engine::movePlayer()
{
	pMap->movePlayer();
}


