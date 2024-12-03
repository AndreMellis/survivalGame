#include "Fish.h"
#include <string>

Fish::Fish() : Animal(1, 1, '~')
{
	std::string harming[1] = {"fishing"};
	setHarmedBy(harming, 1);
}
