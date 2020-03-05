#include "Town.h"
#include <iostream>
Town::Town() {

	square = new Location("Town Square", 
		" A sizable chunk of land surrounded by run down buildings. It would surprise even ghosts if there were life.\n Circled in a walkway of gravel was a moss coverd fountain barely shooting water in a trickle into the air.\n The water green with life.\n Is this their drinking water?\n\n",
		false,
		false);

	shop = new Location("Merchant's Shop",
		" The shop has many holes in the roof and the walls don't leave much for prying eyes unseen. The counter,\n where a lonely skinny merchant sits with a smile, was bearly held together by rotting wood... \n what have i gotten myself into? \n\n",
		true,
		false);

	guild = new Location("Wizard's Guild",
		" The exterior of this building is confusing due to the interior belonging to a palace. Almost as if every cent this\n town makes is poured into this facility. Many cloaked figures stand on balconies overlooking the entrance...\n Masks dawn their faces that can be felt staring into your very soul.\n\n ",
		false,
		true);

	temple = new Location("Priest's Temple",
		" People praying, people in beds dying and one man standing upfront preaching. Nothing out of the ordinary here. \n\n",
		false,
		true);

	square->AddExit(shop);
	square->AddExit(guild);
	square->AddExit(temple);

	shop->AddExit(square);
	guild->AddExit(square);
	temple->AddExit(square);

	mLocations.push_back(square); //0
	mLocations.push_back(shop); //1
	mLocations.push_back(guild); //2
	mLocations.push_back(temple); //3

	wimpyCry = new Item("Wimpy Cry", 1, false);
	magicMissile = new Item("Magic Missile", 1, false);
	fireBlast = new Item("Fire Blast", 1, false);
	thunderBolt = new Item("Thunder Bolt", 1, false);
	nuke = new Item("Nuka Yo Face", 1, false);
	regenMana = new Item("Regenerate Mana", 1, false);
	heal = new Item("Heal Yo Hurts", 1, false);
	cure = new Item("Cure STDs", 1, false);
	protect = new Item("Condom Protection", 1, false);
	bless = new Item("Shot Gun Wedding", 1, false);
	light = new Item("Light Switch", 1, false);

	guild->GetSpells()->insert(magicMissile);
	guild->GetSpells()->insert(fireBlast);
	guild->GetSpells()->insert(thunderBolt);
	guild->GetSpells()->insert(nuke);
	guild->GetSpells()->insert(regenMana);

	temple->GetSpells()->insert(heal);
	temple->GetSpells()->insert(protect);
	temple->GetSpells()->insert(cure);
	temple->GetSpells()->insert(bless);
	temple->GetSpells()->insert(light);
	temple->GetSpells()->insert(regenMana);

}

Town::~Town() {
	mLocations.clear();
}


void Town::DisplayLocations() {

		std::vector<Location*>::iterator it;

		std::cout << "LOCATIONS: " << std::endl;


		int i = 0;
		for (it = mLocations.begin(); it != mLocations.end(); it++) {
			std::cout << i << ". ";
			std::cout << (*it)->GetName() << std::endl;
			i++;

		}

}