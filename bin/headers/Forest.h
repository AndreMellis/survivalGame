#pragma one
#include "Tree.h"
#include <utility>

#define VAR_MAXFORESTSIZE 100 //100 trees per forest

class Forest
{
private:
	Tree *forest[VAR_MAXFORESTSIZE]; //an array of pointers to trees
	int treeCount; //how many trees are actually in the array
	std::pair <int, int> centralCords;
public:
	Forest(); //construct
	Forest(std::pair<int,int> cords); //construct
	Tree **getTrees(); //returns pointer the first item in the array
	int getTreeCount();
	std::pair <int, int> getCords();
	int harvest(); //harvest a random tree
	void step(); //progresses one day
};
