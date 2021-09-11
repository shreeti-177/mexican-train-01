#pragma once
#include "Player.h"

class Computer:public Player
{
public:
	Computer() {};
	~Computer() {};
	void AddToHand(Tile);
	inline std::vector<Tile>& GetComputerHand() { return this->m_hand; }
	inline int GetHandSize() { return this->m_hand.size(); }

	void PrintHand();

	void Play();


private:
	std::vector<Tile> m_hand;
};

