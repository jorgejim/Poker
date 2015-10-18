// PokerGame.cpp - Poker game 
// Written by Jorge Jimenez
// 600 Lines

#include "PokerGame.h"

#pragma once

using namespace std;

void PokerGame::Game()
{
// Set blind
	while (playing)
	{
		system("cls");

		if (menuScreen)
		{
			menu();
		}

		else if (rulesScreen)
		{
			rules();
		}

		else if (preGameScreen)
		{
			preGame();
		}

		else if (gameScreen)
		{
			Poker();
		}

		else if (confirmID)
		{
			confirmUser();
		}

		else if (inputName)
		{
			userNames();
		}
			
		else if (winnerScreen)
		{
			winner();
		}
	}
}

void PokerGame::confirmUser()
{
	string confirm;
	Player status;

	passRound();

	int current = currentPlayer();

	if (users[current].folded() == false)
	{
		cout << "--------------------------------------------------------------------------------" << endl << endl <<
			"                               Player Confirmation" << endl << endl <<
			"--------------------------------------------------------------------------------" << endl << endl;

		cout << "If you are " << users[current].getName() << " type 'yes' to continue" << endl;
		cin >> confirm;

		if (confirm == "yes")
		{
			gotoGame();
		}
	}
	else
	{
		history.push_back("Folded");
		gotoconfirmUser();
	}
}

void PokerGame::removePlayer(int index)
{
	users.erase(users.begin() + index);
}

void PokerGame::displayTable()
{
	table.displayHand();
}

void PokerGame::dealCards()
{
srand(time(NULL));
vector<Card> tempDeck = deck.getFullDeck();
int cardQuantity = ((users.size() * 2) + CARDSONTABLE);

usedCards.push_back(tempDeck[rand() % MAX_CARDS]);

while (usedCards.size() < cardQuantity)
{
	int randIndex = rand() % MAX_CARDS;
	bool exist = false;
	for (int i = 0; i < usedCards.size(); i++)
	{
		if (usedCards[i].equal(tempDeck[randIndex])) exist = true;
	}
	if (exist == false) usedCards.push_back(tempDeck[randIndex]);
}

for (int i = 0; i < CARDSONTABLE; i++)
{
	table.insertCard(usedCards[i]);
	table.getCards()[i].setVisibility(false);
}
for (int i = 0; i < users.size(); i++)
{
	users[i].getHand().insertCard(usedCards[CARDSONTABLE + (i * 2)]);
	users[i].getHand().insertCard(usedCards[CARDSONTABLE + (i * 2) + 1]);
}
}

void PokerGame::userNames()
{
	cout << "--------------------------------------------------------------------------------" << endl << endl <<
		"                                    Poker" << endl << endl <<
		"--------------------------------------------------------------------------------" << endl << endl <<
		"                      Input desired name for each player" << endl << endl;

	for (int i = 0; i < users.size(); i++)
	{
		string name;
		cout << "Player " << i + 1 << endl;
		cin >> name;
		users[i].setName(name);
		users[i].setId(currentPlayer());
		history.push_back("dummy");
	}

	dealCards();
	gotoconfirmUser();
}

void PokerGame::menu()
{
	int option;

	cout << "--------------------------------------------------------------------------------" << endl << endl <<
		"                                    Poker" << endl << endl <<
		"--------------------------------------------------------------------------------" << endl << endl <<
		"                                    Menu" << endl << endl << "********************************************************************************" << endl << endl;

	cout << "1. Play Poker" << endl <<
		"2. View Rules" << endl <<
		"3. Exit" << endl;

	cin >> option;

	switch (option)
	{

	case 1:
		gotoPreGame();
		break;

	case 2:
		gotoRules();
		break;

	case 3:
		playing = false;
		break;

	default:
		system("cls");

		cout << " Please input a valid option" << endl;

		gotoMenu();
		break;

	}

}

void PokerGame::rules()
{
	int op;

	cout << "--------------------------------------------------------------------------------" << endl << endl <<
		"                              Poker Rules" << endl << endl <<
		"--------------------------------------------------------------------------------" << endl << endl << endl <<
		"A round of betting occurs. Three community cards are dealt face up in the middle" <<
		"of the table. Another round of betting occurs. A fourth community card is dealt " <<
		"face up on the table. Another round of betting occurs. A fifth and final " << endl <<
		"community card is dealt face up on the table. A final round of better occurs. " << endl <<
		"The player's hole cards are revealed and the player with the best five-card " << endl <<
		"poker hand wins the pot. Your five card hand can consist of none, one, or both " << endl <<
		"of your hole cards along with five, four, or three of the community cards. If " << endl <<
		"two or more players share the same best hand, the pot is divided equally " << endl <<
		"among the winners." << endl;

	cout << endl << "Press 1 to go back to the menu" << endl <<
		"Press 2 to start the game" << endl;
	cin >> op;

	switch (op)
	{
	case 1:
		gotoMenu();
		break;

	case 2:
		gotoPreGame();
		break;

	default:
		break;
	}
}

void PokerGame::preGame()
{
	int playerQuantity;
	int chips;

	cout << "--------------------------------------------------------------------------------" << endl << endl <<
		"Enter the amount of players" << endl;
	cin >> playerQuantity;
	users.resize(playerQuantity);

	cout << endl << endl << "Enter desired amount of chips per player" << endl;
	cin >> chips;
	for (int i = 0; i < playerQuantity; i++)
	{
		users[i].setChips(chips);
	}

	gotouserNames();
}

void PokerGame::Poker()
{
	int move;
	int current = currentPlayer();
	cout << "Chips Left" << "\t \t \t \t \t" << users[current].getName() << endl << "10 \t 20 \t 50 \t 100" << endl;

	individualChips = users[current].getChipsLeft();

	for (int i = 0; i < individualChips.size(); i++)
	{
		cout << " ";
		cout << individualChips[i] << " \t ";
	}

	cout << "\t  You have " << users[current].getChips() << " in chips" << endl << "The current amount in play is:" << tableStash << endl << endl;
	displayTable();
	cout << endl << "1. Check \t 2. Call \t 3. Raise \t 4. All in \t 5. Fold" << endl;
	users[current].getHand().displayHand();
	cin >> move;

	switch (move)
	{

	case 1:
		if (users[current].getBiddingAmount() < tableStash)
		{
			system("cls");
			cout << endl << endl << endl << "You cannot Check if you have not yet met the table's chip amount. Please Call, Raise, or Fold." << endl;
			Sleep(1700);
			gotoGame();
		}
		else
		{
			users[current].toggleCheck(true);
			system("cls");

			cout << endl << endl << endl << endl << "Please Pass the computer to the next player" << endl;

			Sleep(2000);
			history.push_back("Checked");
			gotoconfirmUser();
		}
		break;

	case 2:

		users[current].setBiddingAmount(tableStash - users[current].getBiddingAmount());
		jackpot += users[current].getBiddingAmount();
		users[current].call();
		users[current].toggleCheck(true);


		system("cls");

		cout << endl << endl << endl << endl << "Please Pass the computer to the next player" << endl;

		Sleep(1000);
		history.push_back("Called");
		gotoconfirmUser();
		break;

	case 3:

		int raise;

		for (int i = 0; i < users.size(); i++)
		{
			if (i == current) users[i].toggleCheck(true);
			else if (users[i].getChips() != 0)
			{
				users[i].toggleCheck(false);
			}
		}

		system("cls");

		cout << endl << endl << endl << "Input desired amount to be raised" << endl << endl << "Current chips on table are worth: " << tableStash << endl;
		cin >> raise;

		users[current].setChips(users[current].getChips() - (raise+tableStash));//.getChipsLeft();
		tableStash += raise;
		users[current].setBiddingAmount(raise + users[current].getBiddingAmount());
		history.push_back("Raise");
		gotoconfirmUser();
		break;

	case 4:

		system("cls");
		int confirm;
		cout << endl << "\t  Are you sure you want to bet all your remaining chips?" << endl << endl << "1. To confirm" << endl << "2. To go back" << endl;
		cin >> confirm;

		switch (confirm)
		{
		case 1:
			tableStash += users[current].getChips();
			users[current].allIn();
			users[current].toggleCheck(true);
			users[current].setBiddingAmount(users[current].getChips() + users[current].getBiddingAmount());

			system("cls");

			cout << endl << endl << endl << endl << "\t\t Please pass the computer to the next player" << endl;

			Sleep(1000);
			history.push_back("All in");
			gotoconfirmUser();
			break;

		case 2:
			gotoGame();
			break;

		default:
			break;

		}
		break;

	case 5:
		users[current].Fold();
		users[current].toggleCheck(true);
		system("cls");

		cout << endl << endl << endl << endl << "Please pass the computer to the next player" << endl;

		Sleep(1500);
		history.push_back("Folded");
		gotoconfirmUser();
		break;

	default:
		cout << "Please input a valid option";
		gotoGame();
		break;
	}
}

void PokerGame::winner()
{
	system("cls");
	cout << endl << endl << "\t \t \t \t" << users[0].getName() << " Has won!" << endl;
	playing = false;
}

int PokerGame::currentPlayer()
{
	int actualSize = history.size() % users.size();
	return actualSize;
}

void PokerGame::gotoMenu()
{
	menuScreen = true;
	rulesScreen = false;
	preGameScreen = false;
	gameScreen = false;
	confirmID = false;
	inputName = false;
	winnerScreen = false;
}

void PokerGame::gotoRules()
{
	menuScreen = false;
	rulesScreen = true;
	preGameScreen = false;
	gameScreen = false;
	confirmID = false;
	inputName = false;
	winnerScreen = false;
}

void PokerGame::gotoPreGame()
{
	menuScreen = false;
	rulesScreen = false;
	preGameScreen = true;
	gameScreen = false;
	confirmID = false;
	inputName = false;
	winnerScreen = false;
}

void PokerGame::gotoGame()
{
	menuScreen = false;
	rulesScreen = false;
	preGameScreen = false;
	gameScreen = true;
	confirmID = false;
	inputName = false;
	winnerScreen = false;
}

void PokerGame::gotoconfirmUser()
{
	menuScreen = false;
	rulesScreen = false;
	preGameScreen = false;
	gameScreen = false;
	confirmID = true;
	inputName = false;
	winnerScreen = false;
}

void PokerGame::gotowinner()
{
	
menuScreen = false;
rulesScreen = false;
preGameScreen = false;
gameScreen = false;
confirmID = false;
inputName = false;
winnerScreen = true;
	
}

void PokerGame::gotouserNames()
{
	menuScreen = false;
	rulesScreen = false;
	preGameScreen = false;
	gameScreen = false;
	confirmID = false;
	inputName = true;
	winnerScreen = false;
}

int PokerGame::findWinner()
{
	int actualWinner = 0;

	handValues._Pop_back_n(handValues.size());

	for (int i = 0; i < users.size(); i++)
	{
		Hand temp;

		for (int k = 0; k < CARDSONTABLE; k++)
		{
			temp.insertCard(usedCards[k]);
		}

		temp.insertCard(usedCards[CARDSONTABLE + (i * 2)]);
		temp.insertCard(usedCards[CARDSONTABLE + ((i * 2) + 1)]);

		handValues.push_back(temp.getValue());
	}

	int winner = handValues[0];
	for (int i = 0; i < handValues.size(); i++)
	{
		if (handValues[i] > handValues[winner]) winner = i;
	}
	return winner;
}

void PokerGame::setBlind()
{ 
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].folded() == false)
		{
			jackpot += 10;
			users[i].setChips(users[i].getChips() - 10);
		}
	}
}

void PokerGame::nextGame()
{
	int winner = findWinner();

	vector<int> cntDraw; // index of tied players

	for (int i = 0; i < handValues.size(); i++)
	{
		if (handValues[winner] == handValues[i]) cntDraw.push_back(i);
	}

	if (cntDraw.size() > 1) // If players are tied in winning hand priority
	{
		vector<pair<Card, int> > realWinner; // HighestCard of tied players, index of tied player

		for (int i = 0; i < cntDraw.size(); i++)
		{// to break a draw

			Hand playerHand = users[cntDraw[i]].getHand();

			if (playerHand.getCards()[0] > playerHand.getCards()[1]) realWinner.push_back(make_pair(Card(playerHand.getCards()[0]), cntDraw[i])); // If the first hand has higher priority add its index and card to realWinner
			else realWinner.push_back(make_pair(Card(playerHand.getCards()[1]), cntDraw[i] )); // If not, add the second card

		}

		for (int i = 0; i < realWinner.size(); i++)
		{
			for (int j = i + 1; j < realWinner.size(); j++)
			{
				if (realWinner[j].first > realWinner[i].first) swap(realWinner[j], realWinner[i]);
			}
		}

//		sort(realWinner.rbegin(), realWinner.rend()); // sorting from largest card to smallest (because of the 'r' in front of begin() and end()

		if (realWinner[realWinner.size() - 1].first.getValue() == 1) winner = realWinner[realWinner.size() - 1].second;
		else winner = realWinner[0].second;

	}

	int currentStash = users[winner].getChips();
	users[winner].setChips(jackpot + currentStash + tableStash);

	tableStash = 0;
	jackpot = 0;

	system("cls");
	cout << endl << endl << endl << "\t \t \t " << users[winner].getName() << " has won this round with " << users[winner].getHand().getHandName(handValues[winner]) <<  endl;
		
	while (currentPlayer() != 0)
	{
		history.push_back("Next Game");
	}

	usedCards._Pop_back_n(usedCards.size());

	table.getCards()._Pop_back_n(table.getCards().size());

	for (int i = 0; i < users.size(); i++)
	{
		users[i].setFoldState(false);
		users[i].toggleCheck(false);
		users[i].getHand().getCards()._Pop_back_n(users[i].getHand().getCards().size());
	}

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getChips() <= 0) removePlayer(i);
	}

	if (users.size() == 1)
	{
		gotowinner();
	}

	else 
	{
		dealCards();

		gotoconfirmUser();
	}
}

void PokerGame::passRound()
{

	bool allActive = true;

	for (int i = 0; i < users.size(); i++)
	{
		if (!users[i].activePlayer()) allActive = false;
	}

	if (allActive)
	{
		while (currentPlayer() != 0)
		{
			history.push_back("Pass Round");
		}

		int cntFolded = 0;
		
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].folded() == true) cntFolded++;
		}
		
		if (cntFolded == users.size() - 1) nextGame();

		if (round > 0)
		{
			for (int i = 0; i < CARDSONTABLE; i++)
			{
				if (table.getCards()[i].getVisibility() == false)
				{
					table.getCards()[i].flipCard();
					break;
				}
			}
		}
		else
		{
			setBlind();
			for (int i = 0; i < 3; i++)
			{
				table.getCards()[i].flipCard();
			}
		}

		jackpot += tableStash;
		tableStash = 0;
		for (int i = 0; i < users.size(); i++)
		{
			if(users[i].folded() == false) users[i].toggleCheck(false);
		}

		round++;
	}

	if (round > 3)
	{
		round = 0;
		dealCards();
		nextGame();
		return;
	}

	system("cls");
	cout << endl << endl << endl << " \t \t \t \t  ROUND " << round << endl;

}