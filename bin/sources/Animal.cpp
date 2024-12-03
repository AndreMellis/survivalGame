#include "Animal.h"
#include <stdexcept>
#include <string>

Animal::Animal(int healthInput, int meatInput, char livesOnInput)
{
	health=healthInput;
	meat=meatInput;
	livesOn=livesOnInput;
}

void Animal::setHarmedBy(std::string damageItems[], int itemCount) {
	if (itemCount > VAR_MAXHARMEDBYITEMS) {throw std::invalid_argument("setHarmedBy itemCount larger than max array size");}//throw error if array too big

	int i = 0;
	do
	{
		harmedBy[i] = damageItems[i];
		i++;
	} while (i < itemCount && damageItems[i] != "");
}

int Animal::harvest() {return meat;}

void Animal::takeDamage(int damage){health -= damage;}

char Animal::getLivesOn(){return livesOn;}
