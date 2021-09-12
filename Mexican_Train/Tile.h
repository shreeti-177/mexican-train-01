#pragma once
#include<iostream>
#include<vector>



class Tile
{
public:
	Tile() {};
	Tile(int, int);
	~Tile() {};

	inline int GetTileLeft() { return this->left; }
	inline int GetTileRight() { return this->right; }
	
	bool IsMarker();
	bool IsDouble();
	bool operator==(const Tile);

	bool Contains(const int);
	bool Matches(Tile);

	void Flip();

private:
	int left;
	int right;

};

inline std::ostream &operator<< (std::ostream &os, Tile& a_tile) {
	return os << a_tile.GetTileLeft() << " | " << a_tile.GetTileRight();
}

