#include "Computer.h"

using namespace std;

void Computer::AddToHand(Tile a_tile) {
	//cout << "Adding: "<<a_tile.GetTileLeft() << " | " << a_tile.GetTileRight() << endl;
	GetComputerHand().push_back(a_tile);
}

void Computer::PrintHand() {
	vector<Tile>& vec = GetComputerHand();
	cout << "Computer Hand Size: " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << "      " ;
		/*cout <<vec.at(i).GetTileLeft() << " | " << vec.at(i).GetTileRight() << endl;*/
	}
	cout << endl;
}

void Computer::Play() {
	cout << "Computer" << endl;
}



