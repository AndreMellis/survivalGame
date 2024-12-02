#include "MainMap.h" //CMake should handle directory...hopefully
#include <stdio.h>
#include <stdlib.h>
#include <utility>

MainMap *MainMap::mapInst = 0;


MainMap::MainMap()
{ //initializer
	standingOn = VAR_EMPTYFIELDASCII;
}


MainMap *MainMap::getInstance()
{
	if (mapInst == 0)
	{
		mapInst = new MainMap();
	}

	return mapInst;
}

void MainMap::drawMap()
{
	std::system("clear");//clear the screen. Change 'clear' to 'cls' for Windows

	for (int i = 0; i < VAR_MAPHEIGHT; i++)
	{
		printf("%s\n", playerMap[i]); //for each line, print the string of line i
	}
}

std::pair<int,int> MainMap::getPlayerCords()
{	//pair.first is x and pair.second is y
	return std::make_pair(playerX, playerY);
}

void MainMap::movePlayer(char inputChar)
{
	if (inputChar == 'w' && notCollidable(playerMap[playerX-1][playerY]))
	{//if i want to move up and won't hit a freaking wall
		playerMap[playerX][playerY] = standingOn;//replace what I am with what I was
		playerX--; //counter-intuitive, but decrese x to move up
	 	standingOn = playerMap[playerX][playerY]; //remember what I'm standing on
		playerMap[playerX][playerY] = VAR_PLAYERASCII;
	} else if (inputChar == 's' && notCollidable(playerMap[playerX+1][playerY]))
	{//if i want to move down and won't hit a wall
		playerMap[playerX][playerY] = standingOn;//replace what I am with what I was
		playerX++; 
	 	standingOn = playerMap[playerX][playerY]; //remember what I'm standing on
		playerMap[playerX][playerY] = VAR_PLAYERASCII;
	} else if (inputChar == 'a' && notCollidable(playerMap[playerX][playerY-1]))
	{//if i want to move left and won't hit a wall
		playerMap[playerX][playerY] = standingOn;//replace what I am with what I was
		playerY--; 
	 	standingOn = playerMap[playerX][playerY]; //remember what I'm standing on
		playerMap[playerX][playerY] = VAR_PLAYERASCII;
	} else if (inputChar == 'd' && notCollidable(playerMap[playerX][playerY+1]))
	{//if i want to move right and won't hit a wall
		playerMap[playerX][playerY] = standingOn;//replace what I am with what I was
		playerY++; 
	 	standingOn = playerMap[playerX][playerY]; //remember what I'm standing on
		playerMap[playerX][playerY] = VAR_PLAYERASCII;
	}
}

void MainMap::insertObj(char newObject, std::pair<int,int> cords)
{//insert a new object into the map, like ^, P or #
	playerMap[cords.first][cords.second] = newObject;
}

void MainMap::insertPlayer(std::pair<int,int> cords)
{
	playerMap[cords.first][cords.second] = VAR_PLAYERASCII;
	playerX = cords.first;
	playerY = cords.second;
}

char MainMap::getObj(std::pair<int,int> cords)
{//takes in cords, and returns the char that is there
	return playerMap[cords.first][cords.second];
}

std::pair<int,int> MainMap::getFreeCords()
{
	//height and width are minus too because a 50x100 2d array is actuall 48x98
	std::pair<int,int> newCords = std::make_pair( (1 + (rand() % (VAR_MAPHEIGHT-2)) ), (1 + (rand() % (VAR_MAPWIDTH - 2)))  );
	getObj(newCords);

	while(getObj(newCords) != VAR_EMPTYFIELDASCII)
	{ //generate new cords
		newCords = std::make_pair( (1 + (rand() % (VAR_MAPHEIGHT-2)) ), (1 + (rand() % (VAR_MAPWIDTH - 2)))  );
	}
	
	return newCords;
}

std::pair<int,int> MainMap::getFreeNeighbor(std::pair<int,int> inputCords)
{ //take in cords and return one of the free neighbors
  //0,0 will mean there are no free neighbors

	std::pair<int,int> freeNeighbors[8]; //six potential free neighbors
	int freeNeighborCount = 0; //number of neighbors actually free

 	if (getObj( std::make_pair((inputCords.first - 1), (inputCords.second-1)) ) == VAR_EMPTYFIELDASCII)
	{ //top left would be minusX minusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first-1), (inputCords.second-1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first), (inputCords.second-1)) ) == VAR_EMPTYFIELDASCII)
	{ //left would be X minusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first), (inputCords.second-1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first + 1), (inputCords.second-1)) ) == VAR_EMPTYFIELDASCII)
	{ //bottom left would be plusX minusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first+1), (inputCords.second-1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first + 1), (inputCords.second)) ) == VAR_EMPTYFIELDASCII)
	{ //bottom would be plusX Y 
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first+1), (inputCords.second));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first + 1), (inputCords.second+1)) ) == VAR_EMPTYFIELDASCII)
	{ //bottom right would be plusX plusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first+1), (inputCords.second+1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first), (inputCords.second+1)) ) == VAR_EMPTYFIELDASCII)
	{ //right would be X plusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first), (inputCords.second+1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first - 1), (inputCords.second+1)) ) == VAR_EMPTYFIELDASCII)
	{ //top right would be minusX plusY
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first-1), (inputCords.second+1));
		freeNeighborCount++;
	}

 	if (getObj( std::make_pair((inputCords.first - 1), (inputCords.second)) ) == VAR_EMPTYFIELDASCII)
	{ //top would be minusX Y
		freeNeighbors[freeNeighborCount] = std::make_pair( (inputCords.first-1), (inputCords.second));
		freeNeighborCount++;
	}

	if (freeNeighborCount > 0)
	{
		return freeNeighbors[ rand() % (freeNeighborCount) ]; //return one of the neighbors between 0 and free-1
	} else
	{
		return std::make_pair(0,0);
	}
}

bool MainMap::notCollidable(char inputChar)
{ //returns true of object cannot be collided with
	bool returnMe = 1; //assume it's not collidable by default
	int i = 0;

	while(i < sizeof(collidableChars) && returnMe)
	{
		if(collidableChars[i] == inputChar) {returnMe = 0;}
		i++;
	}

	return returnMe;
}

char *MainMap::standingNextTo()
{
	thingsImNextTo[0] = playerMap[playerX-1][playerY-1];
	thingsImNextTo[1] = playerMap[playerX][playerY-1];
	thingsImNextTo[2] = playerMap[playerX+1][playerY-1];
	thingsImNextTo[3] = playerMap[playerX+1][playerY];
	thingsImNextTo[4] = playerMap[playerX+1][playerY+1];
	thingsImNextTo[5] = playerMap[playerX][playerY+1];
	thingsImNextTo[6] = playerMap[playerX-1][playerY+1];
	thingsImNextTo[7] = playerMap[playerX-1][playerY];
	return thingsImNextTo;
}
