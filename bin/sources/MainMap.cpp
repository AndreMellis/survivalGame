#include "MainMap.h" //CMake should handle directory...hopefully
#include <stdio.h>
#include <stdlib.h>
#include <utility>

MainMap::MainMap()
{ //initializer
	playerX = 2;
	playerY = 3;
	playerMap[playerX][playerY] = 'P';
}

MainMap::MainMap(int startX, int startY)
{
	playerX = startX;
	playerY = startY;
	playerMap[startX][startY] = 'P';
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

void MainMap::movePlayer()
{
	char inputChar;
	scanf(" %c", &inputChar); //" %c" ignores newline, but "%c" would read newline
	printf("you entered: %c\n", inputChar);

	if (inputChar == 'w' && playerMap[playerX-1][playerY] != VAR_WALLASCII)
	{//if i want to move up and won't hit a freaking wall
		playerMap[playerX][playerY] = VAR_EMPTYFIELDASCII;
		playerX--; //counter-intuitive, but decrese x to move up
		playerMap[playerX][playerY] = 'P';
	} else if (inputChar == 's' && playerMap[playerX+1][playerY] != VAR_WALLASCII)
	{//if i want to move down and won't hit a wall
		playerMap[playerX][playerY] = VAR_EMPTYFIELDASCII;
		playerX++; //counter-intuitive, but increase x to move down
		playerMap[playerX][playerY] = 'P';
	} else if (inputChar == 'a' && playerMap[playerX][playerY-1] != VAR_WALLASCII)
	{//if i want to move left and won't hit a wall
		playerMap[playerX][playerY] = VAR_EMPTYFIELDASCII;
		playerY--; //counter-intuitive, but increase x to move down
		playerMap[playerX][playerY] = 'P';
	} else if (inputChar == 'd' && playerMap[playerX][playerY+1] != VAR_WALLASCII)
	{//if i want to move right and won't hit a wall
		playerMap[playerX][playerY] = VAR_EMPTYFIELDASCII;
		playerY++; //counter-intuitive, but increase x to move down
		playerMap[playerX][playerY] = 'P';
	}
}

void MainMap::insertObj(char newObject, std::pair<int,int> cords)
{//insert a new object into the map, like ^, P or #
	playerMap[cords.first][cords.second] = newObject;
}

char MainMap::getObj(std::pair<int,int> cords)
{//takes in cords, and returns the char that is there
	return playerMap[cords.first][cords.second];
}

std::pair<int,int> MainMap::getFreeCords()
{
	//height and width are minus too because a 50x100 2d array is actuall 48x98
	std::pair<int,int> newCords = std::make_pair( (1 + (rand() % (VAR_MAPHEIGHT-2)) ), (1 + (rand() % (VAR_MAPWIDTH - 2)))  );

	while(getObj(newCords) != VAR_EMPTYFIELDASCII)
	{ //generate new cords
		newCords = std::make_pair( (1 + (rand() % (VAR_MAPHEIGHT-2)) ), (1 + (rand() % (VAR_MAPWIDTH - 2)))  );
	}
	
	return newCords;
}

std::pair<int,int> MainMap::getFreeNeighbor(std::pair<int,int> inputCords)
{ //take in cords and return one of the free neighbors
  //0,0 will mean there are no free neighbors
	std::pair<int,int> freeNeighbors[6]; //six potential free neighbors
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
