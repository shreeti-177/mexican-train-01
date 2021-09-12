#include "Round.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int Round::m_roundNumber = 0;
Tile Round::m_engine;
list<Tile> Round::m_boneyard;
//vector<Tile> Round::m_boneyard;


void Round::SetRoundNumber(int a_roundNumber) {
	m_roundNumber = a_roundNumber;
}

int Round::GetRoundNumber() {
	return m_roundNumber;
}

void Round::SetEngine() {

	// The game starts with 9-9 decreasing to 0-0 across 10 rounds
	// Then, it again starts from 9-9, 8-8, 7-7.....0-0, 9-9, 8-8...
	int engineNum = 10 - m_roundNumber;
	if (engineNum < 0) {
		engineNum = 10 + engineNum;
	}
	m_engine = Tile(engineNum, engineNum);
	cout << "Engine Tile: " << m_engine << endl;
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
}

Tile Round::GetEngine() {
	return m_engine;
}


void Round::SetBoneyard(vector<Tile>& a_deck) {
	for (int i = 0; i < a_deck.size(); i++) {
		m_boneyard.push_back(a_deck.at(i));
	}

	cout << "Boneyard Size: " << m_boneyard.size() << endl;

	list<Tile>::iterator it;

	for (it = m_boneyard.begin(); it != m_boneyard.end();++it) {
		cout << *it << "\t\t";
	}
	cout << endl;
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
}
