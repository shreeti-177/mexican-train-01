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
		cout << vec.at(i)<<"      ";
	}
	cout << endl;

}

void Human::Play() {
	vector<Tile> eligibleTiles;
	vector<int> originalIndexes;

}
