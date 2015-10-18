// Card.h - Class that implements card identifiers
// Written by Jorge Jimenez
// 66 Lines


#include "Card.h"

#pragma once

using namespace std;

Card::Card(const int& value, const string& suit)
{
	setSuit(suit);
	setValue(value);
}

string Card::getSuit() const
{
	return suit;
}
void Card::setSuit(const string& suit)
{
	this->suit = suit;
}

int Card::getValue() const
{
	return value;
}
void Card::setValue(const int& value)
{
	this->value = value;
}

bool Card::equal(const Card& card)
{
	return (this->getSuit() == card.getSuit() && this->getValue() == card.getValue());
}

bool Card::operator == (const Card& card)
{
	return (this->getValue() == card.getValue());
}

bool Card::operator < (const Card& card)
{
	return (this->getValue() < card.getValue());
}

bool Card::operator > (const Card& card)
{
	return (this->getValue() > card.getValue());
}

bool Card::getVisibility()
{
	return visible;
}

void Card::flipCard()
{
	setVisibility(!visible);
}

void Card::setVisibility(bool visible)
{
	this->visible = visible;
}