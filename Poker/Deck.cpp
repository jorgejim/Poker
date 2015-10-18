// Deck.cpp - Manages the movements of the cards in play and their suits (implementation)
// Written by Jorge Jimenez
// 36 Lines

#include "Deck.h"

#pragma once

Deck::Deck()
{
	fulfillDeck();
}

void Deck::fulfillDeck()
{
	vector <string> suits(MAX_SUITS);// = {Spade, Heart, Diamond, Club};
	suits[Card::Spades] = "Spades";
	suits[Card::Clubs] = "Clubs";
	suits[Card::Diamonds] = "Diamonds";
	suits[Card::Hearts] = "Hearts";
	// Populate vector with suits

	int j = 0;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (i % 13 == 0) j++;

		int value = (i % 13) + 1;

		string suit = suits[j - 1];
		Card card(value, suit);
		fullDeck.push_back(card);
	}
}

vector<Card>& Deck::getFullDeck()
{
	return fullDeck;
}