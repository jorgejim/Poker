// Hand.cpp - Handles cards in the current players possesion (implementation)
// Written by Jorge Jimenez
// 241 Lines

#include "Hand.h"

#pragma once

using namespace std;
void Hand::displayHand()
{
	// if(card is not viible) print upside down

	for (int i = 0; i < cards.size(); i++) //First Line
	{
		cout << "##########";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Second Line
	{
		if (cards[i].getVisibility())
		{
			int cardValue = cards[i].getValue();
			if (cardValue < 10) cout << "# " << cardValue << "      #";
			else cout << "# " << cardValue << "     #";
		}
		else cout << "##########";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Third Line
	{
		if (cards[i].getVisibility())
		{
			string shape = cards[i].getSuit();
			if (shape == "Hearts") shape = "\x03"; // Heart
			if (shape == "Diamonds") shape = "\x04"; // Diamonds
			if (shape == "Clubs") shape = "\x05"; // Clubs
			if (shape == "Spades") shape = "\x06"; // Spades
			cout << "# " << shape << "      #";
		}
		else cout << "##  ##  ##";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Fourth Line
	{
		if (cards[i].getVisibility())
		{
			cout << "#        #";
		}
		else cout << "##  ##  ##";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Fifth Line
	{
		if (cards[i].getVisibility())
		{
			string suit = cards[i].getSuit();
			if (suit == "Hearts") suit = " Hearts ";
			if (suit == "Diamonds") suit = "Diamonds";
			if (suit == "Clubs") suit = "  Clubs ";
			if (suit == "Spades") suit = " Spades ";
			cout << "#" << suit << "#";
		}
		else cout << "####  ####";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Sixth Line
	{
		if (cards[i].getVisibility())
		{
			cout << "#        #";
		}
		else cout << "## #### ##";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Seventh Line
	{
		if (cards[i].getVisibility())
		{
			string shape = cards[i].getSuit();
			if (shape == "Hearts") shape = "\x03"; // Heart
			if (shape == "Diamonds") shape = "\x04"; // Diamonds
			if (shape == "Clubs") shape = "\x05"; // Clubs
			if (shape == "Spades") shape = "\x06"; // Spades
			cout << "#      " << shape << " #";
		}
		else cout << "###    ###";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Eight Line
	{
		if (cards[i].getVisibility())
		{
			int cardValue = cards[i].getValue();
			if (cardValue < 10) cout << "#      " << cardValue << " #";
			else cout << "#     " << cardValue << " #";
		}
		else cout << "##########";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;

	for (int i = 0; i < cards.size(); i++) // Ninth Line
	{
		cout << "##########";
		if (i < cards.size() - 1) cout << "\t";
	} cout << endl;
}

vector<Card>& Hand::getCards()
{
	return cards;
}

void Hand::insertCard(Card& card)
{
	cards.push_back(card);
}

int Hand::getValue()
{
	if (royalFlush()) return Hand::RoyalFlush;
	if (straightFlush()) return Hand::StraightFlush;
	if (fourOfAKind()) return Hand::FourOfAKind;
	if (fullHouse()) return Hand::FullHouse;
	if (flush()) return Hand::Flush;
	if (straight()) return Hand::Straight;
	if (triple()) return Hand::Triple;
	if (pair()) return Hand::Pair;
	return Hand::HighestCard;
}

string Hand::getHandName(int handValue)
{
	if (handValue == Hand::RoyalFlush) return "RoyalFlush";
	if (handValue == Hand::StraightFlush) return "StraightFlush";
	if (handValue == Hand::FourOfAKind) return "FourOfAKind";
	if (handValue == Hand::FullHouse) return "FullHouse";
	if (handValue == Hand::Flush) return "Flush";
	if (handValue == Hand::Straight) return "Straight";
	if (handValue == Hand::Triple) return "Triple";
	if (handValue == Hand::Pair) return "Pair";
	if (handValue == Hand::HighestCard) return "HighestCard";

	return "";
}

int Hand::flush()
{
	for (int i = 4; i < cards.size(); i++)
	{// for(int j=i+1; j<cards.size(); j++)
		if (cards[i - 4].getSuit() == cards[i - 3].getSuit() && cards[i - 3].getSuit() == cards[i - 2].getSuit()
			&& cards[i - 2].getSuit() == cards[i - 1].getSuit() && cards[i - 1].getSuit() == cards[i - 0].getSuit())
			return true;
	}
	return false;
}

int Hand::straight()
{
	vector<Card> tempCards = cards;
	sort(tempCards.rbegin(), tempCards.rend());
	for (int i = 4; i < tempCards.size(); i++)
	{ // check when straight starts at 10
		if (tempCards[i - 4].getValue() == tempCards[i - 4].getValue() + 1 && tempCards[i - 3].getValue() == tempCards[i - 2].getValue() + 1
			&& tempCards[i - 2].getValue() == tempCards[i - 1].getValue() + 1
			&& tempCards[tempCards.size() - 1].getValue() == 1 && tempCards[i - 4].getValue() == 13) return 14;

		if (tempCards[i - 4].getValue() == tempCards[i - 4].getValue() + 1 && tempCards[i - 3].getValue() == tempCards[i - 2].getValue() + 1
			&& tempCards[i - 2].getValue() == tempCards[i - 1].getValue() + 1 && tempCards[i - 1].getValue() == tempCards[i - 0].getValue() + 1)
			return tempCards[i - 0].getValue() + 4;
	}
	return false;
}

int Hand::pair()
{
	for (int i = 0; i < cards.size(); i++)
	{
		for (int j = i + 1; j < cards.size(); j++)
		{
			if (cards[i] == cards[j]) return cards[i].getValue();
		}
	}
	return false;
}

int Hand::triple()
{
	for (int i = 0; i < cards.size(); i++)
	{
		for (int j = i + 1; j < cards.size(); j++)
		{
			for (int k = j + 1; k < cards.size(); k++)
			{
				if (cards[i] == cards[j] && cards[j] == cards[k]) return cards[i].getValue();
			}
		}
	}
	return false;
}

int Hand::fullHouse()
{
	int tripleValue = triple();
	if (pair() && tripleValue) return tripleValue;
	return false;
}

int Hand::fourOfAKind()
{
	for (int i = 0; i < cards.size(); i++)
	{
		for (int j = i + 1; j < cards.size(); j++)
		{
			for (int k = j + 1; k < cards.size(); k++)
			{
				for (int m = k + 1; m < cards.size(); m++)
				{
					if (cards[i] == cards[j] && cards[j] == cards[k]) return cards[i].getValue();
				}
			}
		}
	}
	return false;
}

int Hand::straightFlush()
{
	int straightValue = straight();
	if (flush() && straightValue) return straightValue;
	return false;
}

int Hand::royalFlush()
{
	if (straightFlush() && straight() == 14) return true; // ACE 
	return false;
}