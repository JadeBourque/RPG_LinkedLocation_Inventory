#include "Player.h"
#include <iostream>

Player::Player() {
	mInvent = new Inventory(100);
	mLastLocation = nullptr;
	mCurrentLocation = nullptr;

	shirt.SetProperties("Tattered Shirt", 0, false);
	pantaloons.SetProperties("Crusty Pantaloons", 0, false);
	medallion.SetProperties("Medallion Heirloom", 500, true);

	mInvent->AddToItemsList(&shirt);
	mInvent->AddToItemsList(&pantaloons);
	mInvent->AddToItemsList(&medallion);

}


Player::~Player() {

}
