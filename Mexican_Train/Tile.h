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
	
	bool IsDouble();
	bool operator==(const Tile);


private:
	int left;
	int right;

};

inline std::ostream &operator<< (std::ostream &os, Tile& a_tile) {
	return os << a_tile.GetTileLeft() << " | " << a_tile.GetTileRight();
}

