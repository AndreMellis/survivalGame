#include "Forest.h"
#include "Tree.h"
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iostream>

Forest::Forest()
{
	treeCount = 10 + (rand() % 25); //the amount of starting trees is between 10 and 25
	
	for (int i = 0; i < treeCount; i++)
	{
		forest[i] = new Tree( 1 + (rand() % 10) );

	}
}

Forest::Forest(std::pair<int,int> cords)
{
	treeCount = 10 + (rand() % 25); //the amount of starting trees is between 10 and 25
	centralCords = cords;
	
	for (int i = 0; i < treeCount; i++)
	{
		forest[i] = new Tree( 1 + (rand() % 10) );
	}
}

Tree **Forest::getTrees()
{
	return forest;
}

int Forest::getTreeCount() { return treeCount; }

std::pair<int,int> Forest::getCords(){ return centralCords; }

int Forest::harvest()
{
	if (treeCount < 1) { return 0; } //no trees to harvest
	int treeToHarvest = rand() % treeCount; //gen a number between 0 and treeCount
	//printf("the tree to harvest is num %d\n", treeToHarvest);
	//printf("harvesting tree %d that is of size %d\n", treeToHarvest, forest[treeToHarvest]->getSize());
	int harvestSize = forest[treeToHarvest]->harvest();

	if (forest[treeToHarvest]->getSize() < 1)
	{ //tree is dead
		delete forest[treeToHarvest]; //delete the actual object of the harvested tree
		forest[treeToHarvest]  = forest[treeCount-1]; //point the last obj to the harvested tree
		treeCount--;
	}

	return harvestSize;
}

void Forest::step()
{ //progress a day and birth new trees
	int newTreeCount = 0;
	
	for (int i = 0; i < treeCount; i++)
	{
		forest[i]->step(); //grow all trees no matter what
  		if (forest[i]->getSize() > (int)(VAR_MAXTREESIZE * 0.66))
		{//tree is 2/3 grown
	  		newTreeCount++;
		}
	}

	newTreeCount = newTreeCount/2; //two trees needed for a baby so divide total grown trees by two
	while (newTreeCount > 1 && treeCount < VAR_MAXFORESTSIZE)
	{
		treeCount++;
		newTreeCount--;

		forest[treeCount - 1] = new Tree( 1 + (rand() % 10) );
	}
}
