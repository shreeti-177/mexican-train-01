#include "Deck.h"
#include<iostream>

using namespace std;

void Deck::InitializeDeck(Tile a_engine) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j < i) {
				continue;
			}
			Tile tile(i, j);
			if (tile == a_engine) {
				continue;
			}
			AddTileToDeck(tile);
		}
	}
}

void Deck::AddTileToDeck(Tile a_tile) {
	m_startingDeck.push_back(a_tile);
	//cout << m_startingDeck.size() << endl;
}

vector<Tile>& Deck::GetDeck(){
	return m_startingDeck;
}
//
//void Deck::AssignHand(Player* a_player) {
//	//Assign 16 tiles to a player's hand from the deck
//
//	//copy starting deck by reference
//	vector<Tile> & startingDeck = GetDeck();
//	srand(time(NULL));
//	cout << "Starting size: " << startingDeck.size() << endl;
//	for (int i = 0; i < 16; i++) {
//		int randomIndex = rand() % (startingDeck.size());
//		cout << "Random Index: " << randomIndex << endl;
//		Tile tile = startingDeck.at(randomIndex);
//		a_player->AddToHand(tile);
//		startingDeck.erase(startingDeck.begin() + randomIndex);
//		cout << "Erased size: " << startingDeck.size() << endl;
//	}
//	a_player->PrintHand();
//	PrintRemainingDeck();
//}

//void Deck::PrintRemainingDeck() {
//	cout << "Initial deck size: " << m_startingDeck.size() << endl;
//	for (int i = 0; i < m_startingDeck.size(); i++) {
//		cout << m_startingDeck.at(i).GetTileLeft() << " | " << m_startingDeck.at(i).GetTileRight() << endl;
//	}
//}