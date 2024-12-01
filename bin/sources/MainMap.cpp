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
	
}

char MainMap::getObj(std::pair<int,int> cords)
{//takes in cords, and returns the char that is there
	return playerMap[cords.first][cords.second];
}
