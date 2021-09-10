#include "Tile.h"
#include<iostream>

using namespace std;




Tile::Tile(int a_left, int a_right) {
	this->left = a_left;
	this->right = a_right;
	//std::cout << this->left << " | " << this->right << std::endl;
}

bool Tile::IsDouble() {
	return this->left == this->right;
}

bool Tile::operator==(const Tile a_tile) {
	return (this->left == a_tile.left && this->right == a_tile.right);
}



