#include "Human.h"

using namespace std;

void Human::AddToHand(Tile a_tile) {
	//cout << "Adding: "<<a_tile.GetTileLeft() << " | " << a_tile.GetTileRight() << endl;
	GetHumanHand().push_back(a_tile);
}


void Human::PrintHand() {
	vector<Tile>& vec = GetHumanHand();
	cout << "Human Hand Size: " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i)<<"\t\t";
	}
	cout << endl;
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;

}

void Human::Play() {
	vector<Tile> eligibleTiles;
	vector<int> originalIndexes;
	Tile engine = Round::GetEngine();

	if (m_personalTrain.empty()) {
		m_personalTrain.push_back(engine);
	}

	//Fetch all eligible tiles from the hand
	NextMove(eligibleTiles, originalIndexes);

	//If there are no eligible tiles, draw one from boneyard
	if (eligibleTiles.empty()) {
		DrawFromBoneyard();
	}

	cout << endl;
	cout << "All eligible tiles for your turn are listed above " << endl;
	cout << endl;

	int index;
	do {
		cout << "Select a number before the tile to choose your specified tile: ";
		cin >> index;

		if (index >= 1 && index <= eligibleTiles.size()) {
			break;
		}
		cout << "Invalid entry. Please try again." << endl;

	} while (index<1 || index>eligibleTiles.size());

	Tile selectedTile = eligibleTiles.at(index - 1);
	cout << "Your selected tile: " << selectedTile << endl;
	cout << endl;

	m_personalTrain.push_back(selectedTile);
	RemoveFromHand(originalIndexes.at(index - 1));

	PrintHand();	
}

void Human::RemoveFromHand(int a_index) {
	m_hand.erase(m_hand.begin() + a_index);
}

void Human::NextMove(vector<Tile>& a_eligibleTiles, vector<int>& originalIndexes) {
	Tile prevTile = m_personalTrain.back();
	for (int i = 0; i < GetHandSize(); i++) {
		Tile a_tile = GetHumanHand().at(i);
		if (!(a_tile.Contains(prevTile.GetTileRight()))) {
			continue;
		}

		if (prevTile.GetTileRight() != a_tile.GetTileLeft()) {
			a_tile.Flip();
		}
		cout << "(" << a_eligibleTiles.size() + 1<< ") " << a_tile << "      ";
		a_eligibleTiles.push_back(a_tile);
		originalIndexes.push_back(i);
	}

}


//can be implemented in the Player class
// check if boneyard is empty()
// if so, pass turn to another player, maybe?!
void Human::DrawFromBoneyard() {
	
}