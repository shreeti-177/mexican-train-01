#pragma once
#include "Tile.h"
#include "Player.h"
#include<vector>


class Round
{
public:
	Round() {};
	~Round() {};

	static void SetRoundNumber(int);
	static int GetRoundNumber();

	static void SetEngine();
	static Tile GetEngine();

	static void AssignHand(Player*,std::vector<Tile> &);

	static void SetBoneyard(std::vector<Tile>&);
	static inline int GetBoneyardSize() { return m_boneyard.size(); }

private:
	static int m_roundNumber;
	static Tile m_engine;
	static std::vector<Tile> m_boneyard;
};



