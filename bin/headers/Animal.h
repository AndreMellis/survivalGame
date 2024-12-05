#pragma once

#define VAR_MAXHARMEDBYITEMS 4 //how big can the harmedBy array be

enum HArmingMethods{
	FISHING,
	HUNTING
};

class Animal {
private:
	int health;
	int meat;
	int harmedBy[VAR_MAXHARMEDBYITEMS];//this will be a weapon system, but idk how yet
	
	char livesOn; //what char it lives on for map
protected:
	Animal(int healthInput, int meatInput, char livesOnInput); //we don't want to create Animals directly
	void setHarmedBy(int damageItems[], int itemCount);//what items damage them and how many items
public:
	int harvest();//returns meat
	void takeDamage(int damage);
	char getLivesOn();
};
