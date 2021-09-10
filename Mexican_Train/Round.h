#pragma once
#include "Tile.h"
#include "Player.h"
#include<vector>


class Round
{
public:
	Round() {};
	Round(int);
	~Round() {};

	void SetRoundNumber(int);
	int GetRoundNumber();

	void SetEngine();
	Tile GetEngine();

	void AssignHand(Player*,std::vector<Tile> &);

	void SetBoneyard(std::vector<Tile>&);
	inline int GetBoneyardSize() { return m_boneyard.size(); }

private:
	int m_roundNumber;
	Tile m_engine;
	std::vector<Tile> m_boneyard;
};

