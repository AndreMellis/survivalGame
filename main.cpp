#include "MainMap.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>

int main() {
	srand(time(0));
	
	MainMap playerMap;
	playerMap.drawMap();

	printf("%c is at 48 98\n", playerMap.getObj( std::make_pair(48,98) ));
	
	/*
	while(1)
	{
		playerMap.movePlayer();
		playerMap.drawMap();
		printf("The player is now at X:%d Y:%d\n", playerMap.getPlayerCords().first, playerMap.getPlayerCords().second );
	}
	*/

	return 0;

}
