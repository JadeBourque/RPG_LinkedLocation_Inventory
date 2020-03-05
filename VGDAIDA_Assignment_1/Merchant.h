#pragma once
#include "Inventory.h"
class Merchant {
private:
	
	Inventory* mInventory;

	Item bamboo;
	Item club;
	Item sword;
	Item shield;
	Item clothArmor;
	Item leatherArmor;
	Item healing;
	Item antidote;

public:

	Merchant();
	~Merchant();

	Inventory* GetInventory() { return mInventory; }
};