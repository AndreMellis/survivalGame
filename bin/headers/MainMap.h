#pragma once
#include <utility>

#define VAR_MAPHEIGHT 50
#define VAR_MAPWIDTH 100
#define VAR_EMPTYFIELDASCII '.'
#define VAR_WALLASCII '#'
#define VAR_FORESTASCII '^'
#define VAR_PLAYERASCII 'P'
#define VAR_WATERASCII '~'

class MainMap
{
private:
	char playerMap[VAR_MAPHEIGHT][VAR_MAPWIDTH] = {
		"###################################################################################################",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"#.................................................................................................#",
		"###################################################################################################"

	};

	int playerX;
	int playerY;
	char standingOn; //need to remember what I'm standing on to replace it
	static MainMap *mapInst;
	MainMap(); //initializer that sets the starting point of Player
	~MainMap(); 
	const char collidableChars[2] = {VAR_WALLASCII, VAR_FORESTASCII};
	char thingsImNextTo[8];
public:
	static MainMap *getInstance(); //call constuctor through here to have one shared map instance globally
	void drawMap(); //draws map to console
	std::pair<int,int> getPlayerCords(); //returns the coordinates of the player
	void movePlayer(char inputChar); //move player using wasd
	void insertObj(char newObject, std::pair<int,int> cords); //insert a new object into the map, like ^, P or #
	void insertPlayer(std::pair<int,int> cords); //a special player insert to set player cords
	char getObj(std::pair<int,int> cords); //takes in cords, and returns the char that is there
	std::pair<int,int> getFreeCords(); //returns random cords of a free spot on the map
	std::pair<int,int> getFreeNeighbor(std::pair<int,int> inputCords); //takes an a set of cords and returns a free neighbor
	bool notCollidable(char inputChar); //returns true if the input is NOT collidable
	char *standingNextTo(); //returns array of what you are standing next to. Size of 8
};
