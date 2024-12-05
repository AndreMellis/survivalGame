#include "Fish.h"

Fish::Fish() : Animal(1, 1, '~')
{
	int harming[1] = {
		FISHING
	};

	setHarmedBy(harming, 1);
}
