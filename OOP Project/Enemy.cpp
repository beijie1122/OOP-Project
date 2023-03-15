#include "Enemy.h"
#include <algorithm>


Enemy::Enemy()
{

}

Enemy::Enemy(string PlayerName)
{
	InitEnemyStats();
}


void Enemy::InitEnemyStats()
{
	//Pawn Stats 
	PawnName= { "Goblin", "Thief", "Ranger" };
	PawnLvl = { 1, 2, 3, 4, 5, 6 };
	PawnHealth= { 10, 20, 30, 40, 50, 60 };
	PawnSpeed = { 1, 5, 10, 15, 20, 25 };
	PawnAttack= { 5, 10, 15, 20, 25, 30 };
	PawnEXP= { 5, 10, 15, 20, 25, 30 };
	PawnUniquePtrName = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	PawnUniquePtrNameRecycleVec = {};
	
	//Nemsis Stats
	NemesisName = { "Thorok", "Kassadin", "Blitz", "Crush", "Vlad"};
	NemesisLvl = { 1, 2, 3, 4, 5, 6 };
	NemesisHealth = { 20, 40, 60, 80, 100, 120 };
	NemesisSpeed = { 5, 10, 15, 20, 25, 30 };
	NemesisAttack = { 10, 20, 30, 40, 50, 60 };
	NemesisEXP = { 10, 20, 30, 40, 50, 60 };
	NemesisUniquePtrName = { 100, 101, 102, 103, 104 };
	NemesisUniquePtrNameRecycleVec = {};
}

void Enemy::SpawnTable()
{
	unique_ptr <Enemy> T1 = make_unique <Enemy>();
	unique_ptr <Enemy> T2 = make_unique <Enemy>();
	unique_ptr <Enemy> T3 = make_unique <Enemy>();
	unique_ptr <Enemy> T4 = make_unique <Enemy>();
	unique_ptr <Enemy> T5 = make_unique <Enemy>();

	EnemyList.emplace_back(*T1);
	EnemyList.emplace_back(*T2);
	EnemyList.emplace_back(*T3);
	EnemyList.emplace_back(*T4);
	EnemyList.emplace_back(*T5);

	vector<Enemy>::iterator place;

	for (place = EnemyList.begin(); place < EnemyList.end(); place++)
	{
		int NameRoll{};
		int LvlRoll{};

		NameRoll = rand() % 2 + 0;
		LvlRoll = rand() % 4 + 0;

		place->PlayerName = PawnName.at(NameRoll);
		place->PlayerLevel = PawnLvl.at(LvlRoll);
		place->PlayerAtt = PawnAttack.at(LvlRoll);
		place->PlayerHP = PawnHealth.at(LvlRoll);
		place->PlayerSpeed = PawnSpeed.at(LvlRoll);
		place->PlayerEXP = PawnEXP.at(LvlRoll);
		place->EnemyRecycleIdentifier = PawnUniquePtrName.at(0);
		PawnUniquePtrName.erase(PawnUniquePtrName.begin());

		//for (size_t i = 0; i < PawnUniquePtrName.size(); i++)
		//{
		//	cout << PawnUniquePtrName.at(i);
		//}
	}
}

void Enemy::DisplaySpawnTable()
{
	printf("=====================\n");
	printf("Pawn List: \n");
	printf("=====================\n");
	for (size_t i = 0; i < EnemyList.size(); i++)
	{
		cout << EnemyList.at(i) << endl;
	}
	printf("=====================\n");

	printf("Nemesis List: \n");
	for (size_t j = 0; j < NemesisList.size(); j++)
	{
		cout << NemesisList.at(j) << endl;
	}
	printf("=====================\n");
}

void Enemy::CheckAndRegenSpawnTable()
{
	if (EnemyList.size() < 5)
	{
		
		CheckAndRecyclePawnUniquePtrNameVector();

		UniquePtrName = PawnUniquePtrName.at(0);
		cout << UniquePtrName << endl;

		unique_ptr <Enemy> UniquePtrName = make_unique <Enemy> ();

		NameRoll = rand() % 2 + 0;
		LvlRoll = rand() % 4 + 0;

		UniquePtrName->PlayerName = PawnName.at(NameRoll);
		UniquePtrName->PlayerLevel = PawnLvl.at(LvlRoll);
		UniquePtrName->PlayerAtt = PawnAttack.at(LvlRoll);
		UniquePtrName->PlayerHP = PawnHealth.at(LvlRoll);
		UniquePtrName->PlayerSpeed = PawnSpeed.at(LvlRoll);
		UniquePtrName->PlayerEXP = PawnEXP.at(LvlRoll);
		UniquePtrName->EnemyRecycleIdentifier = PawnUniquePtrName.at(0);
		PawnUniquePtrName.erase(PawnUniquePtrName.begin());

		EnemyList.emplace_back(*UniquePtrName);

		printf("New Enemy Spawned!\n");
	}
}

void Enemy::SpawnNemesisViaCombatEnemyDeath(int NemesisLevelCarryOverVar)
{

	CheckAndRecycleNemesisUniquePtrNameVector();

	UniquePtrName = NemesisUniquePtrName.at(0);
	

	unique_ptr <Enemy> UniquePtrName = make_unique <Enemy>();

	NameRoll = rand() % 4 + 0;

	UniquePtrName->PlayerName = NemesisName.at(NameRoll);
	UniquePtrName->PlayerLevel = NemesisLvl.at(NemesisLevelCarryOverVar);
	UniquePtrName->PlayerAtt = NemesisAttack.at(NemesisLevelCarryOverVar);
	UniquePtrName->PlayerHP = NemesisHealth.at(NemesisLevelCarryOverVar);
	UniquePtrName->PlayerSpeed = NemesisSpeed.at(NemesisLevelCarryOverVar);
	UniquePtrName->PlayerEXP = NemesisEXP.at(NemesisLevelCarryOverVar);
	UniquePtrName->NemesisRecycleIdentifier = NemesisUniquePtrName.at(0);
	NemesisUniquePtrName.erase(NemesisUniquePtrName.begin());

	NemesisList.emplace_back(*UniquePtrName);

	printf("A new Nemesis has appeared!\n");


}

void Enemy::CheckAndRecyclePawnUniquePtrNameVector()
{
	if (PawnUniquePtrName.size() < 5)
	{
		for (size_t i = 0; i < PawnUniquePtrNameRecycleVec.size(); i++)
		{
			PawnUniquePtrName.emplace_back(PawnUniquePtrNameRecycleVec.at(i));
			PawnUniquePtrNameRecycleVec.erase(PawnUniquePtrNameRecycleVec.begin());
		}
		printf("Recycle Successful!\n");
	}
	else
	{

	}
}

void Enemy::CheckAndRecycleNemesisUniquePtrNameVector()
{
	if (NemesisUniquePtrName.size() < 5)
	{
		for (size_t i = 0; i < NemesisUniquePtrNameRecycleVec.size(); i++)
		{
			NemesisUniquePtrName.emplace_back(NemesisUniquePtrNameRecycleVec.at(i));
			NemesisUniquePtrNameRecycleVec.erase(NemesisUniquePtrNameRecycleVec.begin());
		}
		printf("Nemesis Recycle Successful!");
	}
	else
	{

	}
}

Enemy::~Enemy()
{

}