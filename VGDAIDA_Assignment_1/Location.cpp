#include "Location.h"
#include <iostream>
Location::Location() {
	mName = "_name";
	mHasSpellBook = false;
	mHasMerchant = false;
}

Location::Location(std::string name, std::string description, bool isMerchant, bool isSpellGiver) {
	mName = name;
	mDescription = description;
	mHasSpellBook = isSpellGiver;
	mHasMerchant = isMerchant;
}

Location::~Location() {
	pSpells->clear();
}

void Location::AddExit(Location* loc) {
	pExits->push_back(loc);
}

void Location::DisplayExits() {

	std::cout << "AVAILABLE EXITS: " << std::endl;

	std::vector<Location*>::iterator iter;

	int i = 0;
	for (iter = pExits->begin(); iter != pExits->end(); iter++) {
		std::cout << "  " << i << ". ";
		std::cout << (*iter)->GetName() << std::endl;
		i++;
	}
}