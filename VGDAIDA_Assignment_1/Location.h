#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include <set>

class Location {
private:
	std::string mName;
	std::string mDescription;

	bool mHasMerchant;
	bool mHasSpellBook;

	//merchant pointer here?
	std::set<Item*> * pSpells = new std::set<Item*>();

	std::vector<Location*> * pExits = new std::vector<Location*>();

public:
	Location();
	Location(std::string name, std::string description, bool isMerchant, bool isSpellGiver);
	~Location();

	bool GetHasSpellBook() { return mHasSpellBook; }
	bool GetHasMerchant() { return mHasMerchant; }

	void SetHasSpellBook(bool b) { mHasSpellBook = b; }
	void SetHasMerchant(bool b) { mHasMerchant = b; }

	std::string GetName() { return mName; }
	void SetName(std::string n) { mName = n; }


	void AddExit(Location* loc);
	void DisplayExits();
	std::vector<Location*> * GetExits() { return pExits; }

	std::string GetDescription() { return mDescription; }
	void SetDescription(std::string desc) { mDescription = desc; };

	std::set<Item*> * GetSpells() {
	
		return pSpells;
	
	}

};