#include "Player.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

Player::Player() {
	this->currRoundScore = 0;
	this->totalScore = 0;
	this->totalWins = 0;
}

void Player::AssignHand(vector<Tile>& a_deck) {
	//Assign 16 tiles to a player's hand from the deck

	srand(time(NULL));
	//cout << "Starting size: " << a_deck.size() << endl;
	for (int i = 0; i < 16; i++) {
		int randomIndex = rand() % (a_deck.size());
		//cout << "Random Index: " << randomIndex << endl;
		Tile tile = a_deck.at(randomIndex);
		this->AddToHand(tile);
		a_deck.erase(a_deck.begin() + randomIndex);
		//cout << "Erased size: " << a_deck.size() << endl;
	}
	this->PrintHand();
}
//void Player::Play() {
//	cout << "Here" << endl;
//}
