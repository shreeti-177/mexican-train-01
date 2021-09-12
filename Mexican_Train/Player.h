#pragma once
#include<vector>
#include<iostream>
#include<list>

#include"Round.h"


class Player
{
public:
	Player();
	~Player() {};

	inline int GetRoundScore() { return currRoundScore; };
	inline void SetRoundScore(int a_currRoundScore) { this->currRoundScore = a_currRoundScore; };

	int GetTotalScore();
	void SetTotalScore(int);

	int GetTotalWins();
	void AddWin();

	bool IsTurn();

	virtual void AddToHand(Tile a_tile)=0;
	virtual int GetHandSize() = 0;
	virtual void PrintHand() = 0;
	void AssignHand(std::vector<Tile> &);

	virtual void Play()=0;

	inline bool isEmptyMexicanTrain() { return m_mexicanTrain.size() == 0; }

	inline std::list<Tile>& GetMexicanTrain() { return m_mexicanTrain; }


private:
	//vector: random access, insert/delete at end at O(1)
	//list: no random access, insert/delete at O(1)
	std::vector<Tile> hand;
	std::list<Tile> m_mexicanTrain;
	int currRoundScore;
	int totalScore;
	int totalWins;
	bool turn;
};

