#include "Item.h"

Item::Item() {
	mName = "_name";
	mCost = 1;
	mIsInteresting = false;
}

Item::Item(std::string name, int cost, bool interesting) {
	mName = name;
	mCost = cost;
	mIsInteresting = interesting;
}

Item::~Item() {

}