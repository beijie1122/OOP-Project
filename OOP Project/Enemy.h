#pragma once
#include "Player.h"
#include <vector>


class Enemy :
    public Player
{
public:

    int EXPEarned{};

    int NameRoll{};
    int LvlRoll{};
 


    vector <string> NemesisName{};
    vector<int> NemesisLvl{};
    vector<int> NemesisHealth{};
    vector<int> NemesisSpeed{};
    vector<int> NemesisAttack{};
    vector<int> NemesisEXP{};
    vector<int> NemesisUniquePtrName{};
    vector<int> NemesisUniquePtrNameRecycleVec;

    vector<string> PawnName;
    vector<int> PawnLvl;
    vector<int> PawnHealth;
    vector<int> PawnSpeed;
    vector<int> PawnAttack;
    vector<int> PawnEXP;
    vector<int> PawnUniquePtrName;
    vector<int> PawnUniquePtrNameRecycleVec;

    int UniquePtrName{};

    vector<Enemy> EnemyList{};

    vector<Enemy> NemesisList{};

    Enemy();

    Enemy(string PlayerName);

    void InitEnemyStats();

    void SpawnTable();

    void DisplaySpawnTable();

    void CheckAndRegenSpawnTable();

    void SpawnNemesisViaCombatEnemyDeath(int v);

    void CheckAndRecyclePawnUniquePtrNameVector();

    void CheckAndRecycleNemesisUniquePtrNameVector();

    ~Enemy();

};

