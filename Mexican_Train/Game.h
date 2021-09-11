#pragma once
#include <iostream>
#include<string>

#include "Round.h"
#include "Tile.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Deck.h"


class Game
{
public:
	Game() {};
	~Game() {};

	void StartGame();
	Round SetUpRound();
	void PromptCoinToss();

	inline Player* GetHumanPlayer() { return human; }
	inline Player* GetHumanSubPlayer() { return humanSub; }

	//inline Player* GetComputerPlayer() { return computer; }

	Player* GetPlayers();

private:
	Player* players[2];
	Human humanPlayer;
	Human humanPlayerSub;
	//Computer computerPlayer;
	Player* human = &humanPlayer;
	Player* humanSub = &humanPlayerSub;
	//Player* computer = &computerPlayer;
	Round round;
};

