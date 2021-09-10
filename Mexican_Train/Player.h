#pragma once
#include<vector>
#include<iostream>
#include "Tile.h"


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

	void Play();


private:
	//vector: random access, insert/delete at end at O(1)
	//list: no random access, insert/delete at O(1)
	std::vector<Tile> hand;
	int currRoundScore;
	int totalScore;
	int totalWins;
	bool turn;
};

