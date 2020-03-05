#pragma once
#include "Inventory.h"
#include "Town.h"



class Player {
private:


	Inventory* mInvent;


	Location* mCurrentLocation;
	Location* mLastLocation;

	Item shirt;
	Item pantaloons;
	Item medallion;

public:

	Player();
	~Player();

	Inventory* GetInventory() { return mInvent; }

	void SetLocation(Location* loc) { 
		mCurrentLocation = loc; }
	Location* GetLocation() { return mCurrentLocation; }
	void SetLastLocation(Location* loc) {
		mLastLocation = loc; }
	Location* GetLastLocaiton() { return mLastLocation; }

	//void GoToLocation(Town* town);
	//void GoBack();

};