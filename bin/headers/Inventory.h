#pragma once

class Inventory
{
private:
	int woodCount;
	int foodCount;
	int waterCount;
	Inventory();
	~Inventory();
	static Inventory *invInst;
public:
	static Inventory *getInstance(); //returns the only instance
	int addRemoveWood(int modNum); //can take in a pos or neg number
	int addRemoveFood(int modNum); //can take in a pos or neg number
	int addRemoveWater(int modNum); //can take in a pos or neg number
	void printInv(); //prints inventory to screen

};
