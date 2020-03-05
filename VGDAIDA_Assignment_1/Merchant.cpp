#include "Merchant.h"

Merchant::Merchant() {

	mInventory = new Inventory(1000);

	bamboo.SetProperties("Bamboo Stick", 10, true);
	club.SetProperties("Wooden Club", 30, true);
	sword.SetProperties("Copper Sword", 180, true);
	shield.SetProperties("Small Shield", 90, true);
	clothArmor.SetProperties("Cloth Armor", 10, true);
	leatherArmor.SetProperties("Leather Armor", 50, true);

	healing.SetProperties("Healing Potion", 10, true);
	antidote.SetProperties("Antidote", 20, true);

	mInventory->AddToItemsList(&bamboo);
	mInventory->AddToItemsList(&club);
	mInventory->AddToItemsList(&sword);
	mInventory->AddToItemsList(&shield);
	mInventory->AddToItemsList(&clothArmor);
	mInventory->AddToItemsList(&leatherArmor);

	for (int i = 0; i <= 10; i++) {
		mInventory->AddToItemsList(&healing);
		mInventory->AddToItemsList(&antidote);
	}
}

Merchant::~Merchant() {
	delete mInventory;
	mInventory = nullptr;
}
