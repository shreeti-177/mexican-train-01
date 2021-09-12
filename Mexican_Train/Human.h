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
	void PrintPersonalTrain();

	void Play();
	bool HasPlayableTiles(Tile& );
	//void NextMove(std::vector<Tile>&, std::vector<int>&);
	Tile DrawFromBoneyard();
	bool IsValidMove(Tile&, Tile& );

	//bool IsValidMove(Tile& );

private:

	std::vector<Tile> m_eligibleTiles;
	std::vector<int> m_originalIndexes;

	std::vector<Tile> m_hand;

	std::list<Tile> m_personalTrain;
	std::list<Tile> m_opponentTrain;

};

