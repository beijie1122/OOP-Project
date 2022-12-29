#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "TurnBasedCombat.h"
#include "CharacterPlayer.h"
#include "Enemy.h"

using namespace std;

class Maps
{
public:

	int selection{};
	string P1{};
	string P2{};

	string EventPoint1{};
	string EventPoint2{};

	int EncounterRoll{};

	vector<vector<string>> Map1{};

	list<string> Map2{};

	void display(list<string> const &Map2);

	Maps();

	void InitCombat(unique_ptr <CharacterPlayer>& arg1, unique_ptr <Enemy>& arg2, unique_ptr<TurnBasedCombat>& arg3);

	void InitMap2(unique_ptr <CharacterPlayer>& arg1, unique_ptr <Enemy>& arg2, unique_ptr<TurnBasedCombat>& arg3);

	~Maps();



};



