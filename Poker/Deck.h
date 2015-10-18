// Deck.h - Manages the movements of the cards in play and their suits (declaration)
// Written by Jorge Jimenez
// 32 Lines

#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <vector>
#include <string>

#pragma once

#define	MAX_SUITS	4
#define MAX_CARDS	52

using namespace std;

class Deck
{
public:

	Deck();

	void fulfillDeck();
	
	vector<Card>& getFullDeck();
	
private:
	vector<Card> fullDeck;
};

#endif // !_DECK_
