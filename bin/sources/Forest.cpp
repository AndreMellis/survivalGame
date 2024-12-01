#include "Forest.h"
#include "Tree.h"
#include <cstdlib>
#include <cstdio>
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

int Forest::harvest()
{ //I want this to harvest a random tree from the forest
  //if the tree dies, it should swap the now dead tree with the last tree, then delete last tree
  if (treeCount < 1) { return 0;} //no trees in forest, so don't bother
  int treeToHarvest = rand() % treeCount; //generate a random num between 0 and total tree count
  int harvestSize = forest[treeToHarvest].harvest();

  if (forest[treeToHarvest].getSize() == 0)
  {//tree is dead
   forest[treeToHarvest] = forest[treeCount]; //last tree takes harvested tree's spot
   forest[treeCount] = Tree();//last tree is now a new obj
   treeCount--;
  }

  return harvestSize;
}

void Forest::step()
{
	int newTreeNum = 0;
	double breedableSize = VAR_MAXTREESIZE * .66;

	for (int i = 0; i < treeCount; i++)
	{
		forest[i].step(); //grow the tree at the end/start of day
		printf("tree %d is size %d\n", i, forest[i].getSize());
				  
		if (forest[i].getSize() > (int)(VAR_MAXTREESIZE * 0.66) ) //since 50*.66 is a float, cast it to an int
		{ //tree is 2/3 max size and breedable
		  newTreeNum++;
		}
	}
}
