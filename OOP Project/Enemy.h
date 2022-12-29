#pragma once
#include "Player.h"
#include <vector>


class Enemy :
    public Player
{
public:

    int EXPEarned{};


    vector <string> NemesisName{ "Thorok", "Kassadin", "Blitz" };
    vector<int> NemesisLvl{ 1,2,3,4,5 };
    vector<int> NemesisHealth{ 20, 40, 60, 80, 100 };
    vector<int> NemesisSpeed{ 5, 10, 15, 20, 25 };
    vector<int> NemesisAttack{ 10, 20, 30, 40, 50 };
    vector<int> NemesisEXP{ 10, 20, 30, 40, 50 };

    vector<string> PawnName;
    vector<int> PawnLvl;
    vector<int> PawnHealth;
    vector<int> PawnSpeed;
    vector<int> PawnAttack;
    vector<int> PawnEXP;
    vector<int> PawnUniquePtrName;

    int UniquePtrName{};

    vector<Enemy> EnemyList{};

    Enemy();

    Enemy(string PlayerName);

    void InitEnemyStats();

    void SpawnTable();

    void DisplaySpawnTable();

    void CheckAndRegenSpawnTable();



    ~Enemy();

};

