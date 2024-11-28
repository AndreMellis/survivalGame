#include "Forest.h"
#include "Tree.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <utility>

Forest::Forest()
{
	treeCount = 10 + (rand() % 25); //the amount of starting trees is between 10 and 25
	
	for (int i = 0; i < treeCount; i++)
	{
		forest[i] = Tree( 1 + (rand() % 10) );
	}

}

Forest::Forest(std::pair<int,int> cords)
{
	treeCount = 10 + (rand() % 25); //the amount of starting trees is between 10 and 25
	centralCords = cords;
	
	for (int i = 0; i < treeCount; i++)
	{
		forest[i] = Tree( 1 + (rand() % 10) );
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

std::pair <int, int> Forest::getCords()
{
	return centralCords; 
}
