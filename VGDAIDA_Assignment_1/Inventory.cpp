#include "Inventory.h"
#include <iostream>
#include <algorithm>
Inventory::Inventory(int gold) {
	mGold = gold;
}

Inventory::~Inventory() {
	mGold = 0;
}

void Inventory::AddToItemsList(Item* item) {
	pItems->push_back(item);
}

void Inventory::ShowItemInventorySelling()  {

	std::vector<Item*>::iterator it;

	int i = 0;
	for (it = pItems->begin(); it != pItems->end(); it++) {
		std::cout << " " << i << ". ";
		std::cout << (*it)->GetName() << " | " << (*it)->GetCost()*0.5 << "gp" << std::endl;
		i++;
	}

}
void Inventory::AddToSpellBook(Item* item) {

	std::set<Item*>::iterator invIter;
	invIter = std::find(pSpells->begin(), pSpells->end(), item);

	if (invIter != pSpells->end()) {
		// Spell already exists, don't add
		std::cout << "This spell already exists, it wasn't added to your SpellBook" << std::endl;
	}
	else {
		pSpells->insert(item);
	}
}

void Inventory::ShowItemInventory() {

	std::vector<Item*>::iterator it;

	int i = 0;
	for (it = pItems->begin(); it != pItems->end(); it++ ) {
		std::cout << " " << i << ". ";
		std::cout << (*it)->GetName() << " | " << (*it)->GetCost() << "gp" << std::endl;
		i++;
	}

}

void Inventory::ShowSpellBook() {
	std::set<Item*>::iterator it;

	int i = 0;
	for (it = pSpells->begin(); it != pSpells->end(); it++) {
		std::cout << " " << i << ". ";
		std::cout << (*it)->GetName() << std::endl;
		i++;
	}

}

