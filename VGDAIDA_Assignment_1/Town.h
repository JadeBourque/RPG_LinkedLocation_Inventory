#pragma once
#include "Location.h"
#include <vector>

class Town {
private:
	Location * square;
	Location * shop;
	Location * guild;
	Location * temple;


	Item * wimpyCry;
	Item * magicMissile;
	Item * fireBlast;
	Item * thunderBolt;
	Item * nuke;
	Item * regenMana;
	Item * heal;
	Item * cure;
	Item * protect;
	Item * bless;
	Item * light;


	std::vector<Location*> mLocations;

public:

	Town();
	~Town();

	std::vector<Location*> GetLocationList() { return mLocations; }

	void DisplayLocations();
};