#pragma once
#include"Player.h"


class Human:public Player
{
public:
	Human() {};
	~Human() {};
	void AddToHand(Tile);
	void RemoveFromHand(int);
	inline std::vector<Tile>& GetHumanHand() { return this->m_hand; }
	inline int GetHandSize() { return this->m_hand.size(); }

	void PrintHand();

	void Play();
	void NextMove(std::vector<Tile>&, std::vector<int>&);

private:
	std::vector<Tile> m_hand;
	std::list<Tile> m_personalTrain;
	
};

