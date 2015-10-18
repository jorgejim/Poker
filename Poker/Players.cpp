// Players.cpp - Class that deals with all the players information (implementation)
// Written by Jorge Jimenez
// 126 Lines

#include "Players.h"

using namespace std;

void Player::call()
{
	chips -= bettingAmount;
}

bool Player::activePlayer()
{
	return check;
}

bool Player::hasBlind()
{
	if (chips < 10) blindChip = false;
	return blindChip;
}

void Player::toggleCheck(bool on)
{
	check = on;
}

void Player::allIn()
{
	chips = 0;
	hasBlind();
}

void Player::setBiddingAmount(const int& bid)
{
	this->bettingAmount = bid;
}

int& Player::getBiddingAmount()
{
	return bettingAmount;
}

vector<int> Player::getChipsLeft()
{// chipsLeft[0] -> $10 // chipsLeft[1] -> $20 // chipsLeft[2] -> $50 // chipsLeft[3] -> $100 // 
	vector<int> chipsLeft(4);
	int tempChips = getChips();
	while (tempChips - 100 >= tempChips * 0.80) // >= chips * (1 - (_percentage_ / 100) )
	{
		tempChips -= 100;
		chipsLeft[3]++;
	}
	while (tempChips - 50 >= tempChips * 0.60) // >= chips * (1 - (_percentage_ / 100) )
	{
		tempChips -= 50;
		chipsLeft[2]++;
	}
	while (tempChips - 20 >= tempChips * 0.50) // >= chips * (1 - (_percentage_ / 100) )
	{
		tempChips -= 20;
		chipsLeft[1]++;
	}
	while (tempChips > 0)
	{
		tempChips -= 10;
		chipsLeft[0]++;
	}
	return chipsLeft;
}

Hand& Player::getHand()
{
	return hand;
}

void Player::setHand(Hand& hand)
{
	this->hand = hand;
}

string& Player::getName()
{
	return name;
}

void Player::setName(string& name)
{
	this->name = name;
}

int& Player::getId()
{
	return id;
}

void Player::setId(int id)
{
	this->id = id;
}

int& Player::getChips()
{
	return chips;
}

void Player::setChips(const int& chips)
{
	this->chips = chips;
}

void Player::Fold()
{
	fold = true;
}

bool Player::folded()
{
	return fold;
}

void Player::setFoldState(bool state)
{
	fold = state;
}