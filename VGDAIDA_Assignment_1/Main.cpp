
//Node-based movement
// Merchant / Inventory
// Wizard's Guild
// Priest's Temple

#include "game.h"
#include <iostream>

void DisplayChoices();

int main() {
	Game game;
	std::cout << " -- DATA STRUCTURES SHIT SHOW -- " << std::endl << std::endl;

	int choice;
	do {
		std::cout << " -- " << game.GetPlayer()->GetLocation()->GetName() << " -- " << std::endl << std::endl;
		DisplayChoices();

		std::cout << ">> ";

		std::cin >> choice;

		switch (choice) {
		case 0:
			break;
		case 1:
			game.GoToLocation();
			break;
		case 2:
			game.LookForMerchant();
			break;
		case 3:
			game.ViewPlayerInventory();
			break;
		case 4:
			game.ViewPlayerSpells();
			break;
		default:
			std::cout << "Not a valid selection, please try again" << std::endl;

			break;
		}
	} while (choice != 0); {
		std::cout << "You killed yourself. " << std::endl;
	}
	return 0;
}


void DisplayChoices() {
	std::cout << "What do you want to do? " << std::endl << std::endl;
	std::cout << "  0. Explode \n" << "  1. Go somewhere else \n" << "  2. Look for a merchant \n  3. View your inventory\n  4. View your known spells\n";
}