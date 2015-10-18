// Main.cpp - Poker game
// Written by Jorge Jimenez
// 24 Lines
// Total lines: 1346

#include <iostream>
#include "PokerGame.h"

#define DECK_SIZE	52

using namespace std;

void main()
{
	system("color 27");

	PokerGame game;
	game.Game();

	system("pause > NULL");
}

/* 
Goals: All have been completed and implemented in the class PokerGame.

1. I would like to be able to place a static card dealer, instead of dynamic.

2. Display jackpot for chips on the table after each round

3. Display individual player chips each round

4. Successfully remove a player from the game when the amount of chips remaining is below the amount required as the blind.

5. Be able to use more than two players excluding the dealer.

6. Ask for player number input ("2" when its player two's turn) to play more than one person in one computer.

*/