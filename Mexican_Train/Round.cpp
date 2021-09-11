#include "Round.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int Round::m_roundNumber = 0;
Tile Round::m_engine;
vector<Tile> Round::m_boneyard;


void Round::SetRoundNumber(int a_roundNumber) {
	m_roundNumber = a_roundNumber;
}

int Round::GetRoundNumber() {
	return m_roundNumber;
}

void Round::SetEngine() {

	// The game starts with 9-9 decreasing to 0-0 across 10 rounds
	// Then, it again starts from 9-9, 8-8, 7-7.....0-0, 9-9, 8-8...
	int engineNum = 10 - m_roundNumber;
	if (engineNum < 0) {
		engineNum = 10 + engineNum;
	}
	m_engine = Tile(engineNum, engineNum);
	cout << "Engine Tile: " << m_engine << endl;
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
}

Tile Round::GetEngine() {
	return m_engine;
}


//void Round::AssignHand(Player* a_player, vector<Tile>& a_deck) {
//	//Assign 16 tiles to a player's hand from the deck
//
//	srand(time(NULL));
//	//cout << "Starting size: " << a_deck.size() << endl;
//	for (int i = 0; i < 16; i++) {
//		int randomIndex = rand() % (a_deck.size());
//		//cout << "Random Index: " << randomIndex << endl;
//		Tile tile = a_deck.at(randomIndex);
//		a_player->AddToHand(tile);
//		a_deck.erase(a_deck.begin() + randomIndex);
//		//cout << "Erased size: " << a_deck.size() << endl;
//	}
//	a_player->PrintHand();
//}

void Round::SetBoneyard(vector<Tile>& a_deck) {
	m_boneyard = a_deck;
	cout << "Boneyard Size: " << m_boneyard.size() << endl;
	for (int i = 0; i < m_boneyard.size(); i++) {
		cout << m_boneyard.at(i)<<"      ";
	}
	cout << endl;
}
