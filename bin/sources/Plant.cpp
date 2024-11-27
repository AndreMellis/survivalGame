#include "Plant.h"
#include <cstdlib>
#include <ctime>

Plant::Plant(int maxSizeInput)
{
	maxSize = maxSizeInput;
	srand(time(0));
	size = 1 + (rand() % 10); //size is a random num between 1 - 10
}

int Plant::step()
{
	if (size < maxSize && size > 0)
	{ //plant has room to grow
		size++; //just grow by one for now
		return 1;
	} else if (size == 0)
	{ //plant is completely harvested
		return 0;
	} else
	{ //plant at max size
		return 1;
	}
}

int Plant::harvest()
{
	int harvestSize = 0;
	if (size > 5)
	{ //randomly decided that plants bigger than 5 should only return half size as max
		harvestSize = 1 + (rand() % (size/2) ); 
	} else
	{
		harvestSize = 1 + (rand() % size); //harvest between one and all of the tree
	}
	size = size - harvestSize;
	return harvestSize;
}

int Plant::getSize()
{
	return size;
}
