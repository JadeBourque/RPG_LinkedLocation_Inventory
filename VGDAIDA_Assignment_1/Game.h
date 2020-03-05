#pragma once

#include <string>

#include "player.h"
#include "merchant.h"

class Game {

private:
	Player* pPlayer;
	Merchant* pMerchant;
	Town* pTown;
	Item * wimpyCry;

public:
	Game();
	~Game();

	//bool CompareNames(Item* obj, std::string name);

	//void TalkToMerchant();
	//void Buy(std::string item, int ammount);
	//void Sell(std::string item, int ammount);

	Player* GetPlayer() { return pPlayer; };
	Merchant* GetMerchant() { return pMerchant; }
	Town* GetTown() { return pTown; }

	void GoToLocation();
	void LookForMerchant();

	void ViewPlayerInventory();
	void ViewPlayerSpells();

	void Buy();
	void Sell();

};

/*
struct NameIs {
	NameIs(std::string s) : toFind(s) { }
	bool operator() (Item* n)
	{
		return n->GetName() == toFind;
	}
	std::string toFind;
};
*/