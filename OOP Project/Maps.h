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

	bool IsStartPointBigBillys{};

	int EncounterRoll{};


	//General Map Component Coords and Names 
	char DirectionSelectionInput{};
	string GrassNode{ "Grass " };
	int PlayerXValue{};
	int PlayerYValue{};
	string PlayerNode{ "*YOU* " };
	int VectorColumn{ 5 };
	int VectorRow{ 5 };

	//First Map Component Coords and Names 
	string HomeTown{};
	int HomeTownXValue{};
	int HomeTownYValue{};

	string BillysBigBobbaBungalow{};
	int BBBBXValue{};
	int BBBBYValue{};


	vector<vector<string>> NewMap{VectorColumn, vector<string>(VectorRow)};

	Maps();

	void InitCombat(unique_ptr <CharacterPlayer>& arg1, unique_ptr <Enemy>& arg2, unique_ptr<TurnBasedCombat>& arg3);

	//Integrate New Map Functions

	void GenerateNewMap(vector<vector<string>>&, int, int, string);

	void DisplayNewMap(vector<vector<string>>, int, int);

	void NewMapInit(unique_ptr <CharacterPlayer>& arg1, unique_ptr <Enemy>& arg2, unique_ptr<TurnBasedCombat>& arg3, unique_ptr<Maps>& arg4, int & arg5, int & arg6);

	void DisplayOutofBoundsMessage();

	void GenerateHomeTownBBBBMap(vector <vector<string>> &, string&, int&, int&, string&, int&, int&);

	void DidPlayerArriveAtLocation(int, int, int, int, int, int, unique_ptr<Maps> & arg1, unique_ptr<CharacterPlayer>& arg2, unique_ptr<Enemy>& arg3, unique_ptr<TurnBasedCombat>& arg4);

	//Integrate New Map Functions

	void HomeTownMenu(unique_ptr<Maps> &arg1, unique_ptr<CharacterPlayer> &arg2, unique_ptr<Enemy> &arg3, unique_ptr<TurnBasedCombat> &arg4);

	void BillysBigBobaBungalowMenu(unique_ptr<Maps>& arg1, unique_ptr<CharacterPlayer>& arg2, unique_ptr<Enemy>& arg3, unique_ptr<TurnBasedCombat>& arg4);

	int MapsInputValidation(int &selection);

	char MapsCharInputValidation(char& DirectionSelectionInput);

	~Maps();



};



