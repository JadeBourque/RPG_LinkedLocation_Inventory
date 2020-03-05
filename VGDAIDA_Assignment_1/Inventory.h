#pragma once
#include <vector>
#include "Item.h"
#include <algorithm>
#include <iterator>
#include <set>


class Inventory {
private:
	std::vector<Item*> * pItems = new std::vector<Item *>();
	std::set<Item*> * pSpells = new std::set<Item*>();

	int mGold;

public:
	Inventory(int gold);
	~Inventory();

	void ShowItemInventorySelling();

	int GetGold() { return mGold; }
	void SetGold(int i) { mGold = i; }

	void AddToItemsList(Item* item);


	void ShowItemInventory();
	void ShowSpellBook();

	std::vector<Item*> * GetItems() { return pItems; }
	std::set<Item*> * GetSpells() { return pSpells; }

	void AddToSpellBook(Item* item);
};