#pragma once
#include "MainMap.h"
#include "Forest.h"

class Engine
{
private:
	MainMap *map;
	void populateForests(Forest *pforest); //populate forests to the map
					       //takes in the forest to populate
	Forest forest;
public:
	void populateMap(); //populates the map
	void drawMap(); //draw the map
};
