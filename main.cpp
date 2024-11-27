#include "MainMap.cpp"
#include <stdio.h>
//#include <stdlib.h>

int main() {

	MainMap gameMap = MainMap(1,1);
	gameMap.drawMap();

	while(1)
	{
		gameMap.movePlayer();
		gameMap.drawMap();
		printf("\n\nplayer is located at X: %d and Y: %d\n", gameMap.getPlayerCords().first, gameMap.getPlayerCords().second);
	}

	return 0;

}
