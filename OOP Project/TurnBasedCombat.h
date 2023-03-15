#include "CharacterPlayer.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

#pragma once

using namespace std;

class TurnBasedCombat
	:public CharacterPlayer, public Enemy
{
public:

	vector<string> CombatOrder{};

	int EnemyIdentifier{};
	
	int OpponentChoice{};

	int LvlUpEnemySetter{};

	int PostCombatSpawnNemesisOrSpawnRoll{};

	int NemesisLevelCarryOverVar{};

	int CombatSelection{};

	bool PlayerWins{};

	bool EnemyWins{};

	bool CombatOver{};

	void CheckSpeed(unique_ptr<CharacterPlayer> &arg1, unique_ptr<Enemy> &arg2);

	void CombatLoop(unique_ptr<CharacterPlayer>& arg1, unique_ptr<Enemy>& arg2, vector<Enemy>::iterator& obj, int CombatSelection);

	void NemesisCombatLoop(unique_ptr<CharacterPlayer>& arg1, unique_ptr<Enemy>& arg2, vector<Enemy>::iterator& obj, int CombatSelection);

	void DisplayCombatOrder(vector<string> CombatOrder);

	void CheckHealthDuringCombat(unique_ptr<CharacterPlayer>& arg1, unique_ptr<Enemy> &arg2, vector<Enemy>::iterator &obj);

	void LevelUpEnemy(vector<Enemy>::iterator &obj, unique_ptr<Enemy> &arg1);

	int InputValidationCheck(int& arg1);


	//OVERLOADED == OPERATOR
	bool operator==(const TurnBasedCombat& rhs) const
	{
	return (this->CombatOrder == rhs.CombatOrder);
	}


	TurnBasedCombat();

	~TurnBasedCombat();


};

