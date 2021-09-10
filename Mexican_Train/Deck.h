#pragma once
#include "Tile.h"
#include "Player.h"
#include<stdlib.h>
#include<time.h>
#include <vector>


class Deck
{
public:
	Deck() {};
	~Deck() {};
	//55 tiles
	//starting deck would be an array of 54 tiles since engine would be removed

	void InitializeDeck(Tile);
	void AddTileToDeck(Tile);

	void AssignHand(Player*);
	std::vector<Tile>& GetDeck();

private:
	std::vector<Tile> m_startingDeck;
};

