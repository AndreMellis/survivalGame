#pragma once
#include <utility>

#define VAR_MAPHEIGHT 10
#define VAR_MAPWIDTH 20
#define VAR_EMPTYFIELDASCII '.'
#define VAR_WALLASCII '#'

class MainMap
{
private:
	char playerMap[VAR_MAPHEIGHT][VAR_MAPWIDTH] = {
		"###################",
		"#.................#",
		"#...........^.....#",
		"#.................#",
		"#.................#",
		"#.................#",
		"#.................#",
		"#.................#",
		"#.................#",
		"###################"

	};

	int playerX;
	int playerY;
public:
	MainMap(); //initializer that sets the starting point of Player
	MainMap(int startX, int startY); //initializer that sets the starting point of Player, but grabs as vars
	void drawMap(); //draws map to console
	std::pair<int,int> getPlayerCords(); //returns the coordinates of the player
	void movePlayer(); //move player using wasd
};
