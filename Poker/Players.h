// Players.h - Class that deals with all the players information (declaration)
// Written by Jorge Jimenez
// 12 Lines

#include "Hand.h"
#include <string>

#pragma once

using namespace std;

class Player
{
public:

	Player(){}

	void call();

	bool activePlayer();

	bool hasBlind();

	void toggleCheck(bool on);

	void allIn();

	void setBiddingAmount(const int& bid);

	int& getBiddingAmount();

	vector<int> getChipsLeft();

	Hand& getHand();

	void setHand(Hand& hand);

	string& getName();

	void setName(string& name);

	int& getId();

	void setId(int id);

	int& getChips();

	void setChips(const int& chips);

	void Fold();

	bool folded();

	void setFoldState(bool state);

private:
	Hand hand;
	string name;
	int id;
	int chips;
	int bettingAmount = 0;

	bool fold = false;
	bool check = false;
	bool blindChip = true;
};