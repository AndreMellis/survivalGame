#pragma once
#include "Plant.h"

#define VAR_MAXTREESIZE 50

class Tree : public Plant
{//a Tree is a type of plant
public:
	Tree(int initialSize); //I'm now declaring size at init to make Forest actually random
	Tree() : Plant(VAR_MAXTREESIZE) {} //empty constructor for array building
};
