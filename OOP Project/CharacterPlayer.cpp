#include "CharacterPlayer.h"


CharacterPlayer::CharacterPlayer()
{
	//Initiates the Values from vectors when the pawn is created
	InitCharacterPlayerStats();
	PlayerLevel = CharacterPlayerLvl.at(0);
	PlayerHP = CharacterPlayerHP.at(0);
	PlayerAtt = CharacterPlayerAtt.at(0);
	PlayerSpeed = CharacterPlayerSpd.at(0);
	PlayerEXP = CharacterPlayerExp;

}

void CharacterPlayer::InitCharacterPlayerStats()
{
	printf("Init succes!\n");
	CharacterPlayerName = { "Austin" };
	CharacterPlayerHP = { 100, 200, 300, 400, 500 };
	CharacterPlayerAtt = { 20, 40, 60, 80, 100 };
	CharacterPlayerSpd = { 10, 20, 30, 40, 50 };
	CharacterPlayerLvl = { 1, 2, 3, 4, 5 };
	CharacterPlayerExp = { 1 };
}

void CharacterPlayer::CheckIfLvlUp(int PlayerExp, int &PlayerLevel, int LevelIdentifier)
{
	vector <int> ExpRange{ 1, 10, 20, 30, 40, 50, 60 };
	

	if (PlayerExp >= ExpRange.at(1) && PlayerExp < ExpRange.at(2))
	{
		LevelIdentifier = 1;
		LevelUpFunction(LevelIdentifier);
	}
	else if (PlayerExp >= ExpRange.at(2) && PlayerExp < ExpRange.at(3))
	{
		LevelIdentifier = 2;
		LevelUpFunction(LevelIdentifier);
	}
	else if (PlayerExp >= ExpRange.at(3) && PlayerExp < ExpRange.at(4))
	{
		LevelIdentifier = 3;
		LevelUpFunction(LevelIdentifier);
	}
	else if (PlayerExp >= ExpRange.at(4) && PlayerExp < ExpRange.at(5))
	{
		LevelIdentifier = 4;
		LevelUpFunction(LevelIdentifier);
	}
	else
	{
		
	}

}

void CharacterPlayer::LevelUpFunction(int LevelIdentifier)
{
	PlayerLevel = CharacterPlayerLvl.at(LevelIdentifier);
	PlayerHP = CharacterPlayerHP.at(LevelIdentifier);
	PlayerAtt = CharacterPlayerAtt.at(LevelIdentifier);
	PlayerSpeed = CharacterPlayerSpd.at(LevelIdentifier);
}

CharacterPlayer::~CharacterPlayer()
{

}