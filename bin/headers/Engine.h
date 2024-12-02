#pragma once
#include "MainMap.h"
#include "Menus.h"
#include "Actions.h"

class Engine
{
private:
	MainMap *map;
	Menus menu;
	Actions actions;
	void populateForests(Forest *pforest); //populate forests to the map
					       //takes in the forest to populate
	Forest forest;
public:
	void populateMap(); //populates the map
	void getInput(); //get Player input
};
