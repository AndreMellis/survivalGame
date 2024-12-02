#include <utility>
#include "Actions.h"

Actions::Actions()
{
	pMap = MainMap::getInstance();
	pInv = Inventory::getInstance();;
}

bool Actions::contains(char checkFor, char *arr, int arrSize)
{//checks if a char array contains char
	int arrContains = 0;
	int i = 0;
	do
	{
		if (checkFor == arr[i]) {arrContains = 1;}
		i++;
	} while ( i < arrSize && !arrContains);

	return arrContains;
}

void Actions::harvestWood(Forest *pForest)
{//takes in forest pointer to harvest, then adds to inv
 
	char *standingNextTo = pMap->standingNextTo();

	if(contains(VAR_FORESTASCII, standingNextTo, 8))
	{//you are standing next to a forest
		int harvestSize = pForest->harvest();
		pInv->addRemoveWood(harvestSize);

	}
}
