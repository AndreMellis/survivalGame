#include "Forest.h"
#include "Tree.h"
#include <cstdlib>
#include <ctime>

Forest::Forest()
{
	srand(0);
	treeCount = 10 + (rand() % 25); //the amount of starting trees is between 10 and 25

	int i = 0;
	while (i < treeCount)
	{
		forest[i] = *(new Tree());
		i++;
	}
}

Tree* Forest::getTrees()
{ //returns pointer to the forest array
	return forest;
}

int Forest::getTreeCount()
{
	return treeCount;
}
