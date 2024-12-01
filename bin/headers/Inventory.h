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

}
