#include "Game.h"

#include<stdlib.h>
#include<time.h>

using namespace std;


void Game::StartGame() {

	//Ask if user wants to play from a saved game

	//If user chooses to start a new game, 
	//toss a coin to decide who goes first
	PromptCoinToss();

	//Set up state variables for the round
	//Round currRound = SetUpRound();
	SetUpRound();

	//Once round is set up, alternate player turns
	int counter = 0;
	do{
		//Play for player
		players[counter%2]->Play();
		counter++;

		if (counter == 20) {
			break;
		}
	} while (players[0]->GetHandSize() > 0 && players[1]->GetHandSize() > 0 && Round::GetBoneyardSize() > 0);
}

void Game::SetUpRound() {

	//Assign round number
	int roundNum = 1;
	Round::SetRoundNumber(roundNum);
	cout << "Round: " << roundNum << endl;
	
	
	//If round number != 1, prompt coin toss to decide 
	//who goes first in the next round
	
	//Based on round number, set engine
	Round::SetEngine();
	
	//Initialize the starting deck without the engine tile
	Deck deck;
	deck.InitializeDeck(Round::GetEngine());
		
	//Get starting deck
	vector<Tile>& startingDeck = deck.GetDeck();
	
	//shuffle and distribute 16 each to all players
	Round::AssignHand(GetHumanPlayer(),startingDeck);
	Round::AssignHand(GetHumanSubPlayer(), startingDeck);
	//currRound.AssignHand(GetComputerPlayer(), startingDeck);
	
	//Set Boneyard
	Round::SetBoneyard(startingDeck);
	
}


//Round Game::SetUpRound() {
//
//	//Assign round number
//	int roundNum = 1;
//	Round currRound(roundNum);
//	cout << "Round: " << roundNum << endl;
//
//
//	//If round number != 1, prompt coin toss to decide 
//	//who goes first in the next round
//
//	//Based on round number, set engine
//	currRound.SetEngine();
//
//	//Initialize the starting deck without the engine tile
//	Deck deck;
//	deck.InitializeDeck(currRound.GetEngine());
//	
//	//Get starting deck
//	vector<Tile>& startingDeck = deck.GetDeck();
//
//	//shuffle and distribute 16 each to all players
//	currRound.AssignHand(GetHumanPlayer(),startingDeck);
//	currRound.AssignHand(GetHumanSubPlayer(), startingDeck);
//	//currRound.AssignHand(GetComputerPlayer(), startingDeck);
//
//	//Set Boneyard
//	currRound.SetBoneyard(startingDeck);
//
//	return currRound;
//}


void Game::PromptCoinToss() {

	cout << "Tossing a coin to decide who goes first." << endl;
	char side;
	do {
		cout << "Please pick a side: H for head, T for tail" << endl;
		cin >> side;

		//Validate user input for coin toss
		if (side != 'H' && side != 'T') {
			cout << "Invalid entry. Let's try again." << endl;
		}
	} while (side != 'H' && side != 'T');

	srand(time(NULL));
	int tossValue = rand() % 2;
	//cout << tossValue << endl;

	//1 is for Head and 0 is for Tail
	if (side == 'H' && tossValue == 1) {
		cout << "The dice rolled Heads. You go first!!" << endl;
		players[0] = GetHumanPlayer();
		players[1] = GetHumanSubPlayer();
		//players[1] = GetComputerPlayer();

	}
	else if (side == 'T' && tossValue == 0) {
		cout << "The dice rolled Tails. You go first!!" << endl;
		players[0] = GetHumanPlayer();
		players[1] = GetHumanSubPlayer();

		//players[1] = GetComputerPlayer();

	}
	else {
		cout << "Computer goes first!" << endl;
		//players[0] = GetComputerPlayer();
		players[0] = GetHumanSubPlayer();
		players[1] = GetHumanPlayer();
	}
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
}

Player* Game::GetPlayers() {
	return *players;
}