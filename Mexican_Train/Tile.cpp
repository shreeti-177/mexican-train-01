#include "Tile.h"
#include<iostream>

using namespace std;




Tile::Tile(int a_left, int a_right) {
	this->left = a_left;
	this->right = a_right;
	//std::cout << this->left << " | " << this->right << std::endl;
}

bool Tile::IsMarker() {
	return this->left == -1 && this->right == -1;
}
bool Tile::IsDouble() {
	return this->left == this->right;
}

bool Tile::operator==(const Tile a_tile) {
	return (this->left == a_tile.left && this->right == a_tile.right);
}

bool Tile::Contains(const int a_side) {
	return a_side == this->left || a_side == this->right;
}

bool Tile::Matches(Tile a_tile) {
	return a_tile.Contains(this->left) || a_tile.Contains(this->right);
}

void Tile::Flip() {
	int tmp = this->right;
	this->right = this->left;
	this->left = tmp;
}
