#include "Enemy.h"


Enemy::Enemy()
{

}

Enemy::Enemy(string PlayerName)
{
	InitEnemyStats();
}


void Enemy::InitEnemyStats()
{
	PawnName= { "Goblin", "Thief", "Ranger" };
	PawnLvl = { 1, 2, 3, 4, 5, 6 };
	PawnHealth= { 10, 20, 30, 40, 50, 60 };
	PawnSpeed = { 1, 5, 10, 15, 20, 25 };
	PawnAttack= { 5, 10, 15, 20, 25, 30 };
	PawnEXP= { 5, 10, 15, 20, 25, 30 };
	PawnUniquePtrName = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
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
	}
}

void Enemy::DisplaySpawnTable()
{
	for (size_t i = 0; i < EnemyList.size(); i++)
	{
		cout << EnemyList.at(i) << endl;
	}
}

void Enemy::CheckAndRegenSpawnTable()
{
	if (EnemyList.size() < 5)
	{
		
		UniquePtrName = PawnUniquePtrName.at(0);
		PawnUniquePtrName.erase(PawnUniquePtrName.begin());
		cout << UniquePtrName << endl;

		unique_ptr <Enemy> UniquePtrName = make_unique <Enemy> ();

		int NameRoll{};
		int LvlRoll{};

		NameRoll = rand() % 2 + 0;
		LvlRoll = rand() % 4 + 0;

		UniquePtrName->PlayerName = PawnName.at(NameRoll);
		UniquePtrName->PlayerLevel = PawnLvl.at(LvlRoll);
		UniquePtrName->PlayerAtt = PawnAttack.at(LvlRoll);
		UniquePtrName->PlayerHP = PawnHealth.at(LvlRoll);
		UniquePtrName->PlayerSpeed = PawnSpeed.at(LvlRoll);
		UniquePtrName->PlayerEXP = PawnEXP.at(LvlRoll);

		EnemyList.emplace_back(*UniquePtrName);

		printf("New Enemy Spawned!\n");
	}
}

Enemy::~Enemy()
{

}