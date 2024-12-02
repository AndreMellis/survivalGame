#include "Inventory.h"

Inventory *Inventory::invInst = 0;

Inventory *Inventory::getInstance()
{
	if (invInst == 0)
	{
		invInst = new Inventory();
	}
	return invInst;
}

Inventory::Inventory()
{
	woodCount = 0;
	foodCount = 0;
	waterCount = 0;
}

int Inventory::addRemoveWood(int modNum)
{
	woodCount += modNum;
	return woodCount;
}

int Inventory::addRemoveFood(int modNum)
{
	foodCount += modNum;
	return foodCount;
}
int Inventory::addRemoveWater(int modNum)
{
	waterCount += modNum;
	return waterCount;
}
