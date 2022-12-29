#include <iostream>
#include <string>
#include <ctime>
#include <memory>
#include <random>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "CharacterPlayer.h"
#include "TurnBasedCombat.h"
#include "Maps.h"


using namespace std;

void WorldMap();

//Global Variables

//Selection variable (Used everywhere where Cin is used)
int Selection{};



int main()
{
	srand((unsigned int)time(NULL));
	
	unique_ptr <CharacterPlayer> Character = make_unique <CharacterPlayer>();
	Character->PlayerName = "Austin"; //DELETE FOR IMPLEMENTING NAME YOUR CHARACTER FUNCTION!

	unique_ptr <Enemy> PP = make_unique<Enemy>("PP");
	PP->SpawnTable();
	PP->DisplaySpawnTable();

	unique_ptr <TurnBasedCombat> TBC = make_unique <TurnBasedCombat>();
	
	do
	{
		Character->CheckIfLvlUp(Character->PlayerEXP, Character->PlayerLevel, Character->LevelIdentifier);
		printf("==========\n");
		printf("Welcome to the Main Menu\n");
		printf("Press 1 to start an encounter\n");
		printf("Press 2 to see stats\n");
		printf("Press 3 to see the enemy roster\n");
		printf("Press 4 to view world map\n");
		printf("==========\n");

		cin >> Selection;

		if (Selection == 1)
		{
			TBC->CheckSpeed(Character, PP);

			PP->DisplaySpawnTable();
		}

		if (Selection == 2)
		{
			Character->HUD();
		}

		if (Selection == 4)
		{
			unique_ptr<Maps> Map1 = make_unique <Maps>();
			Map1->InitMap2(Character, PP, TBC);
			Map1->InitCombat(Character, PP, TBC);
		}
		
	} while (Selection != 9);


	return 1;
}

