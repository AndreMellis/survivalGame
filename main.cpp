#include "Forest.h"
#include "Tree.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(0));
	
	Forest forestObj;
	Tree* forest = forestObj.getTrees();

	for (int i = 0; i < forestObj.getTreeCount(); i++)
	{
		printf("tree number %d is of size %d\n", i, forest[i].getSize());
	}

	return 0;

}
