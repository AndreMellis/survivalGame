#pragma once
#include "Forest.h"
#include "MainMap.h"
#include "Inventory.h"

class Actions
{
private:
	MainMap *pMap;
	Inventory *pInv;
	bool contains(char checkFor, char *arr, int arrSize);//checks if a char array contains char
public:
	Actions();
	void harvestWood(Forest *pForest); //takes in forest pointer to harvest, then adds to inv
};
