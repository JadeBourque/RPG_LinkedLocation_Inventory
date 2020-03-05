#include "Game.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include "ConsoleUtils.h"

Game::Game() {
	pTown = new Town;
	pPlayer = new Player;
	pMerchant = new Merchant;

	std::vector<Location*> locationList = pTown->GetLocationList();
	pPlayer->SetLocation(locationList[0]);

	wimpyCry = new Item("Wimpy Cry", 1, false);

	pPlayer->GetInventory()->AddToSpellBook(wimpyCry);
}

Game::~Game() {
	delete pTown;
	pTown = nullptr;

	delete pPlayer;
	pPlayer = nullptr;

	delete pMerchant;
	pMerchant = nullptr;
}

void Game::GoToLocation() {
	Location* currentLocation = pPlayer->GetLocation();
	std::vector<Location*> * locationList = currentLocation->GetExits();

	int choice;
	do {

		std::cout << "\nWhere do you want to go?\n\n";

		currentLocation->DisplayExits();

		std::cout << ">> ";
		std::cin >> choice;

	} while (choice < 0 || choice >= currentLocation->GetExits()->size());

		pPlayer->SetLocation((*locationList)[choice]);

		std::cout << "You walk to the " << pPlayer->GetLocation()->GetName() << std::endl << std::endl;
		std::cout << pPlayer->GetLocation()->GetDescription() << std::endl;

	std::set<Item*>::iterator it;
	if (pPlayer->GetLocation()->GetHasSpellBook()) {

		std::set<Item*> tempSet;

		std::set_union(
			pPlayer->GetLocation()->GetSpells()->begin(),	//Location's spells.begin()
			pPlayer->GetLocation()->GetSpells()->end(),		// Location's spells.end()
			pPlayer->GetInventory()->GetSpells()->begin(),	// Player's spells.begin()
			pPlayer->GetInventory()->GetSpells()->end(),	//Player's spells.end()

			std::inserter( tempSet, tempSet.begin()) ); //Insert into tempSet

		pPlayer->GetInventory()->GetSpells()->swap(tempSet); //swap contents of player's spells with tempSet.

		//Player's spells should now have location's spells

		std::cout << "This place has a spell book. Your spell book now contains:\n\n";
		pPlayer->GetInventory()->ShowSpellBook();
	}
}

void Game::LookForMerchant() {
	Location* currentLocation = pPlayer->GetLocation();
	Location* lastLocation = pPlayer->GetLastLocaiton();
	std::vector<Location*> locationList = pTown->GetLocationList();
	int choice;

		if (currentLocation->GetHasMerchant()) {
			std::cout << "You find a merchant and approach him,\n he greets you by obnoxiously shouting 'TOP OF THE MORNING TO YA'\n what do you want to do?\n";
			do {
				std::cout << "\n  0. Walk away\n  1. Sell from your inventory\n  2. Buy items\n";

				std::cout << ">> ";
				std::cin >> choice;
				switch (choice) {
				case 0:
					break;
				case 1:
					if (!pPlayer->GetInventory()->GetItems()->empty()) {
						Sell();
					}
					else {
						std::cout << "!!!! You don't have anything to sell.. !!!!\n";
					}
					break;
				case 2:
					if (!pMerchant->GetInventory()->GetItems()->empty()) {
						Buy();
					}
					else {
						std::cout << "!!!! The merchant doesn't have anything to sell.. !!!!\n";
					}
					break;
				default:
					std::cout << "!!!! That isn't a valid option.. !!!!\n";
					break;
				}
			} while (choice != 0);
		}
	else {
			std::cout << "\n!!!! Doesn't seem like there are any merchants here !!!!\n\n";
	}
}

void Game::ViewPlayerInventory() {
	std::cout << "\n- Your inventory: -\n\n";
	pPlayer->GetInventory()->ShowItemInventory();
	std::cout << std::endl;
}

void Game::ViewPlayerSpells() {
	std::cout << "\n- Your spells: -\n\n";

	pPlayer->GetInventory()->ShowSpellBook();
	std::cout << std::endl;
}

void Game::Buy() {
	int choice;
	std::vector<Item*>* merchInv = pMerchant->GetInventory()->GetItems();
	std::vector<Item*>* playerInv = pPlayer->GetInventory()->GetItems();
	std::vector<Item*>::iterator it;

	do {

		std::cout << "Buy which item? \n\n";
		pMerchant->GetInventory()->ShowItemInventory();

		std::cout << ">> ";
		std::cin >> choice;

	} while (choice < 0 || choice > pMerchant->GetInventory()->GetItems()->size());

//BUY
// Needs to remove from merchant inventory and add to player inventory
// Remove gold from player's funds, add gold to merchant's funds

	//Check if player has enough gold for the item
	if (pPlayer->GetInventory()->GetGold() >= (*merchInv)[choice]->GetCost()) { 

		//Adjust funds accordingly
		pMerchant->GetInventory()->SetGold((pMerchant->GetInventory()->GetGold()) + ((*merchInv)[choice]->GetCost()));
		pPlayer->GetInventory()->SetGold((pPlayer->GetInventory()->GetGold()) - ((*merchInv)[choice]->GetCost()));

		//Add the item to player's inventory
		pPlayer->GetInventory()->AddToItemsList((*merchInv)[choice]);

		std::cout << "!!!! You successfully purchased the " << (*merchInv)[choice]->GetName() << " !!!!\n\n";

		//Erase the item from the merchant's inventory
		it = merchInv->begin() + choice;
		merchInv->erase(it);

		//Display new funds
		std::cout << "Player's new gold: " << pPlayer->GetInventory()->GetGold() << std::endl;
		std::cout << "Merchant's new gold: " << pMerchant->GetInventory()->GetGold() << std::endl;

		std::cout << "Your inventory now contains:\n\n";
	
		pPlayer->GetInventory()->ShowItemInventory();
	}
	else {
		std::cout << "!!!! You can't afford that. !!!!\n\n";
	}

}

void Game::Sell() {
	int choice;
	std::vector<Item*>* merchInv = pMerchant->GetInventory()->GetItems();
	std::vector<Item*>* playerInv = pPlayer->GetInventory()->GetItems();
	std::vector<Item*>::iterator it;

	do {

		std::cout << "Sell which item? " << std::endl << std::endl;
		//Display items with appropraite value reduction
		pPlayer->GetInventory()->ShowItemInventorySelling();

		std::cout << ">> ";
		std::cin >> choice;

	} while (choice < 0 || choice > pPlayer->GetInventory()->GetItems()->size());

	// SELL
	// Needs to remove from player inventory and add to merchant inventory
	// Remove gold from merchant's funds, add gold to player's funds

	//Check if item is of value to the merchant
	if ((*pPlayer->GetInventory()->GetItems())[choice]->GetIsInteresting()) {

		//Check if merchant has enough gold
		if (pMerchant->GetInventory()->GetGold() >= (*playerInv)[choice]->GetCost()) {

			//Adjust funds accordingly
			pMerchant->GetInventory()->SetGold((pMerchant->GetInventory()->GetGold()) - ((*playerInv)[choice]->GetCost()*0.5));
			pPlayer->GetInventory()->SetGold((pPlayer->GetInventory()->GetGold()) + ((*playerInv)[choice]->GetCost()*0.5));


			it = std::find((*playerInv).begin(), (*playerInv).end(), (*playerInv)[choice]);
			Item* tempItem = *it;

			//Add item to merchant inventory
			pMerchant->GetInventory()->AddToItemsList(tempItem);

			std::cout << "!!!! You successfully sold the " << (*playerInv)[choice]->GetName() << " !!!!\n\n";

			//Remove item from player inventory
			(*playerInv).erase(it);

			//Display new funds
			std::cout << "Player's new gold: " << pPlayer->GetInventory()->GetGold() << std::endl;
			std::cout << "Merchant's new gold: " << pMerchant->GetInventory()->GetGold() << std::endl << std::endl;

			std::cout << "Your inventory now contains:\n\n";

			pPlayer->GetInventory()->ShowItemInventory();
		}
		else {
			std::cout << "!!!! The merchant can't afford that !!!!\n\n";
		}
	}
	else { //If item isn't of value
		std::cout << "!!!! 'You think I'd buy that?' The merchant snaps. !!!!\n\n";
	}
}