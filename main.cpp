#include "Forest.h"
#include "Tree.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main() {
	srand(time(0));
	
	Forest forestObj = Forest(std::make_pair(1,4));

	int i = 0;

	while (i < 100)
	{
		printf("day %d\n", i);
		int harvestSize = forestObj.harvest();
		i++;
	}

	return 0;

}
