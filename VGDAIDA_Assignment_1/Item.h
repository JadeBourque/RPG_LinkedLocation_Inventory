#pragma once
#include <string>

class Item {

private:
	int mCost;
	std::string mName;
	bool mIsInteresting;

public:
	Item();
	Item(std::string name, int cost, bool interesting);
	~Item();

	void SetProperties(std::string name, int cost, bool interesting) {
		mName = name;
		mCost = cost;
		mIsInteresting = interesting;
	}
	bool GetIsInteresting() { return mIsInteresting; }

	int GetCost() { return mCost; }

	const std::string GetName() { return mName;  }
};