#include "MainMap.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <iostream>

int main() {
	srand(time(0));
	MainMap map = MainMap(1,1);
	

	map.drawMap();
	for (int i = 0; i < 100; i++)
	{
		printf("day %d:\n", i);
		std::pair<int,int> freeCords = map.getFreeNeighbor(std::make_pair(1,1));
		printf("free neighbor is X: %d Y: %d\n", freeCords.first, freeCords.second); 
	}


	return 0;

}
