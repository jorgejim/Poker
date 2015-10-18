// Hand.h - Handles cards in the current players possesion (declaration)
// Written by Jorge Jimenez
// 54 Lines

#ifndef _HAND_
#define _HAND_

#include "Card.h"
#include <algorithm>

#pragma once

class Hand
{
public:
	Hand() {}

	enum
	{
		HighestCard = 0,
		Pair = 1,
		Triple = 2,
		Straight = 3,
		Flush = 4,
		FullHouse = 5,
		FourOfAKind = 6,
		StraightFlush = 7,
		RoyalFlush = 8
	};

	void displayHand();

	vector<Card>& getCards();

	void insertCard(Card& card); 

	int getValue();

	string getHandName(int handValue);

private:
	vector<Card> cards;

	int flush();
	int straight();
	int pair();
	int triple();
	int fullHouse();
	int fourOfAKind();
	int straightFlush();
	int royalFlush();
};

#endif // !_HAND_