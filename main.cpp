#include "Forest.h"
#include "Tree.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <iostream>

int main() {
	srand(time(0));
	
	Forest forestObj = Forest(std::make_pair(12,12));


	for (int i = 0; i < 100; i++)
	{
		printf("day %d:\n", i);
		printf("you got a harvest of size %d\n", forestObj.harvest());
		printf("the forest has %d trees\n", forestObj.getTreeCount());
		forestObj.step();
	}


	return 0;

}
