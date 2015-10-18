// Card.h - Class declaring card identifiers
// Written by Jorge Jimenez
// 61 Lines

#ifndef _CARD_
#define _CARD_

#include <string>
#include <iostream>
#include <vector>

#pragma once

using namespace std;

class Card
{

public:

	enum
	{
		Spades = 0,
		Hearts = 1,
		Diamonds = 2,
		Clubs = 3
	};

	Card(){}

	Card(const int& value, const string& suit);

	string getSuit() const;

	void setSuit(const string& suit);

	int getValue() const;

	void setValue(const int& value);

	bool equal(const Card& card);

	bool operator == (const Card& card);

	bool operator < (const Card& card);

	bool operator > (const Card& card);

	bool getVisibility();

	void flipCard();

	void setVisibility(bool visible);

private:
	string suit;
	int value;
	bool visible = true;
};

#endif // !_CARD_
