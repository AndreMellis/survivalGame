#pragma one
#include "Tree.h"

#define VAR_MAXFORESTSIZE 100 //100 trees per forest

class Forest
{
private:
	Tree forest[VAR_MAXFORESTSIZE]; //an array of the most amount of trees possible
	int treeCount; //how many trees are actually in the array
public:
	Forest(); //construct
	Tree* getTrees(); //returns pointer the first item in the array
	int getTreeCount();
};
