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
#include "QuestBase.h"


using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	
	unique_ptr <CharacterPlayer> Character = make_unique <CharacterPlayer>();
	Character->PlayerName = "Austin"; //DELETE FOR IMPLEMENTING NAME YOUR CHARACTER FUNCTION!

	unique_ptr <Enemy> PP = make_unique<Enemy>("PP");
	PP->SpawnTable();

	unique_ptr <TurnBasedCombat> TBC = make_unique <TurnBasedCombat>();

	unique_ptr<Maps> Map1 = make_unique<Maps>();

	unique_ptr<QuestBase> QuestOverview = make_unique<QuestBase>();
	QuestOverview->InitializeQuests();
	QuestOverview->DisplayQuestDetails();
	
	//PP->DisplaySpawnTable();
	
	Map1->HomeTownMenu(Map1, Character, PP, TBC);

	return 1;
}

