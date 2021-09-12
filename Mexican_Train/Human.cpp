#include "Human.h"

using namespace std;

void Human::AddToHand(Tile a_tile) {
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

	Tile engine = Round::GetEngine();

	//check if it's a new round
	if (m_personalTrain.empty()) {
		m_personalTrain.push_back(engine);
	}


	//check if player has a marker
	if (m_personalTrain.back().IsMarker()) {
		//check if mexican train is open

		//check if the opponent's personal train has a marker

		//if none, then simply
	}

	//Fetch all eligible tiles from the hand
	//NextMove(eligibleTiles, originalIndexes);
	//HasPlayableTiles(eligibleTiles, originalIndexes);

	//If there are no eligible tiles, check for
	// opponent's open train
	// mexican train opportunity
	Tile prevTile = m_personalTrain.back();

	if (!(HasPlayableTiles(prevTile))) {
		cout << "No eligible tiles in your hand. Drawing one from the boneyard..." << endl;
		
		//if(isEmptyMexicanTrain() )
		Tile tile = DrawFromBoneyard();
		cout << "Tile drawn from boneyard: " << tile << endl;
		
		if (!IsValidMove(tile, m_personalTrain.back())) {
			//put a marker at the end of the personal train
			m_personalTrain.push_back(Tile(-1, -1));
			PrintPersonalTrain();
			m_eligibleTiles.clear();
			m_originalIndexes.clear();
			return;
		}
		cout << "This tile allows for a valid move." << endl;
		m_personalTrain.push_back(tile);
		PrintPersonalTrain();
	}

	cout << endl;
	cout << "All eligible tiles for your turn are listed above " << endl;
	cout << endl;

	int index;
	do {
		cout << "Select a number before the tile to choose your specified tile: ";
		cin >> index;

		if (index >= 1 && index <= m_eligibleTiles.size()) {
			break;
		}
		cout << "Invalid entry. Please try again." << endl;

	} while (index<1 || index>m_eligibleTiles.size());

	Tile selectedTile = m_eligibleTiles.at(index - 1);
	cout << "Your selected tile: " << selectedTile << endl;
	cout << endl;

	m_personalTrain.push_back(selectedTile);
	RemoveFromHand(m_originalIndexes.at(index - 1));
	
	PrintPersonalTrain();
	PrintHand();	
	m_eligibleTiles.clear();
	m_originalIndexes.clear();
	cout << "=============================================" << endl;

}

void Human::RemoveFromHand(int a_index) {
	m_hand.erase(m_hand.begin() + a_index);
}

bool Human::HasPlayableTiles(Tile& a_tile) {
	for (int i = 0; i < GetHandSize(); i++) {
		Tile tile = GetHumanHand().at(i);
		if (!IsValidMove(tile, a_tile)) {
			continue;
		}
		cout << "(" << m_eligibleTiles.size() + 1 << ") " << tile << "      ";
		m_eligibleTiles.push_back(tile);
		m_originalIndexes.push_back(i);
	}
	if (!m_eligibleTiles.empty()) {
		return true;
	}
	return false;
}




//can be implemented in the Player class
// check if boneyard is empty()
// if so, pass turn to another player, maybe?!
Tile Human::DrawFromBoneyard() {
	if (Round::GetBoneyardSize() == 0) {
		//do something
		//put a marker at the end of the personal train
	}
	Tile tile = Round::GetBoneyard().front();
	Round::GetBoneyard().pop_front();
	return tile;
}

bool Human::IsValidMove(Tile& a_tile, Tile& a_prevTile) {
	if (!(a_tile.Contains(a_prevTile.GetTileRight()))) {
		return false;
	}

	if (a_prevTile.GetTileRight() != a_tile.GetTileLeft()) {
		a_tile.Flip();
	}
	return true;
}

void Human::PrintPersonalTrain() {
	list<Tile>::iterator it;
	cout << "Personal Train: ";
	for (it = m_personalTrain.begin(); it != m_personalTrain.end(); ++it) {
		cout << *it << "\t\t";
	}
	cout << endl;
}