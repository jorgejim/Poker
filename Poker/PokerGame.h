// PokerGame.h - Contains all class declarations that run the poker game
// Written by Jorge Jimenez
// 94 Lines

#include <array>
#include "Hand.h"
#include "Deck.h"
#include "Players.h"
#include <Windows.h>
#include <ctime>
#include <algorithm>
#include <vector>

#pragma once

#define MAX_PLAYERS		4
#define CARDSONTABLE	5

class PokerGame
{
public:

	PokerGame(){}

	void Game();

	void confirmUser();

	void removePlayer(int index);

	void displayTable();

	void dealCards();

	void userNames();

	void menu();

	void winner();

	void rules();

	void preGame();

	void Poker();

	int currentPlayer();

	void gotoMenu();

	void gotoRules();

	void gotoPreGame();

	void gotoGame();

	void gotoconfirmUser();

	void gotouserNames();

	void gotowinner();

	void setBlind();

	int findWinner();

	void nextGame();

	void passRound();

	private:
		bool playing = true;
		bool menuScreen = true;
		bool rulesScreen = false;
		bool preGameScreen = false;
		bool gameScreen = false;
		bool confirmID = false;
		bool inputName = false;
		bool winnerScreen = false;

		vector<Player> users;
		vector<string> history;
		vector<int> individualChips;
		vector<Card> usedCards;
		vector<int> handValues;


		Hand table;
		Deck deck;
		
		int tableStash = 0;
		int jackpot = 0;
		int round = 0;
};