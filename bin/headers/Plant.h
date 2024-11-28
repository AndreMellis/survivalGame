#pragma once

#define VAR_MAXSIZE 50

class Plant
{
private:
	int maxSize;
protected:
	int size; //size could be wood amount, berry amount, etc.
public:
	Plant(int maxSizeInput);
	int step(); //proceeds one day. will return 1 if alive or 0 if tree has been completely harvested
	int harvest(); //harvests plant of amount between 1 and size
	int getSize(); //returns size
};
