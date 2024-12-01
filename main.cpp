#include "MainMap.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main() {
	srand(time(0));
	
	MainMap playerMap;
	playerMap.drawMap();
	
	while(1)
	{
		playerMap.movePlayer();
		playerMap.drawMap();
		printf("The player is now at X:%d Y:%d\n", playerMap.getPlayerCords().first, playerMap.getPlayerCords().second );
	}

	return 0;

}
