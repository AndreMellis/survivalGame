#pragma once
#include <string>

#define VAR_MENUHEIGHT 20
#define VAR_MENUWIDTH 20


class Menus
{
private:
	char menu[VAR_MENUHEIGHT][VAR_MENUWIDTH] = {
		"*******************",
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*                 *", 
		"*******************"
	};
	void replaceRow(char *pRow, std::string newLine);
public:
	void printLegend(); //prints out the menu legend
	void printControls(); //prints out the controls
};
