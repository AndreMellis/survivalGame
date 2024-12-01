#include <Menus.h>
#include <MainMap.h> //I want all the defines in there
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

void Menus::replaceRow(char *pRow, std::string newLine)
{
	int i = 0;
	for (char c : newLine)
	{
		pRow[i] = c;
		i++;
	}
}

void Menus::printControls()
{
	printf("wasd to move\n");
	printf("L to display the legend\n");
	printf("Enter to confirm choice\n");
}

void Menus::printLegend()
{
	char legend[VAR_MENUHEIGHT][VAR_MENUWIDTH]; //copy menu template to legend
	std::copy(&menu[0][0], &menu[0][0] + VAR_MENUHEIGHT * VAR_MENUWIDTH, &legend[0][0]);//copy i guess

	replaceRow(legend[1], "*  is a wall      *");
	legend[1][1] = VAR_WALLASCII;

	replaceRow(legend[2], "*  is empty field *");
	legend[2][1] = VAR_EMPTYFIELDASCII;

	replaceRow(legend[3], "*  is a tree      *"); 
	legend[3][1] = VAR_FORESTASCII;

	replaceRow(legend[4], "*  is water       *"); 
	legend[4][1] = VAR_WATERASCII;


	std::system("clear");//clear the screen. Change 'clear' to 'cls' for Windows

	for (int i = 0; i < VAR_MENUHEIGHT; i++)
	{
		printf("%s\n", legend[i]); //for each line, print the string of line i
	}
	printf("press X to exit\n");

	char inputChar = ' ';
	while (inputChar != 'x' and inputChar != 'X')
	{//hold Legend open until closed by player
		scanf(" %c", &inputChar);
	}
}
