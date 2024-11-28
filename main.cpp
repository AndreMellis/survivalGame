#include "Forest.h"
#include "Tree.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main() {
	srand(time(0));
	
	Forest forestObj = Forest(std::make_pair(1,4));
	Tree* forest = forestObj.getTrees();

	printf("the forest is located at %d %d\n", forestObj.getCords().first, forestObj.getCords().second);

	for (int i = 0; i < forestObj.getTreeCount(); i++)
	{
		printf("tree number %d is of size %d\n", i, forest[i].getSize());
	}

	return 0;

}
