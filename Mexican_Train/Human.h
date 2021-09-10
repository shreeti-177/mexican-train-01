#pragma once
#include"Player.h"

class Human:public Player
{
public:
	Human() {};
	~Human() {};
	void AddToHand(Tile);
	inline std::vector<Tile>& GetHumanHand() { return this->m_hand; }
	inline int GetHandSize() { return this->m_hand.size(); }

	void PrintHand();

private:
	std::vector<Tile> m_hand;
};

