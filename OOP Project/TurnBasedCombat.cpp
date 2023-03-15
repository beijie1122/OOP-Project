#include "TurnBasedCombat.h"

TurnBasedCombat::TurnBasedCombat()
{

}

void TurnBasedCombat::CheckSpeed(unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP)
{


	if (PP->NemesisList.size() != 0)
	{
		OpponentChoice = rand() % 7 + 0;
		cout << "Opponent Chosen: " << OpponentChoice << endl;

		if (OpponentChoice > 1) // CHANGE THIS
		{
			vector<Enemy>::iterator cbt = PP->NemesisList.begin();

			NemesisCombatLoop(Character, PP, cbt, CombatSelection);
		}
		else
		{
			vector<Enemy>::iterator cbt = PP->EnemyList.begin();

			advance(cbt, OpponentChoice);

			CombatLoop(Character, PP, cbt, CombatSelection);
		}
	}
	else
	{
		OpponentChoice = rand() % 4 + 0;
		cout << "Opponent Chosen: " << OpponentChoice << endl;

		vector<Enemy>::iterator cbt = PP->EnemyList.begin();

		advance(cbt, OpponentChoice);

		CombatLoop(Character, PP, cbt, CombatSelection);
		
	}
	
}

void TurnBasedCombat::CombatLoop(unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP, vector<Enemy>::iterator& cbt, int CombatSelection)
{
	CombatOver = false;
	PlayerWins = false;

	if (Character->PlayerSpeed >= cbt->PlayerSpeed)
	{
		CombatOrder = { Character->PlayerName, cbt->PlayerName, Character->PlayerName, cbt->PlayerName };

	}
	else
	{
		printf("==========\n");
		CombatOrder = { cbt->PlayerName, Character->PlayerName };
		printf("==========\n");
	}

	do
	{
		//HUD for enemies
		Character->HUD();
		cbt->EnemyCombatHUD();

		if (CombatOver == false)
		{
			DisplayCombatOrder(CombatOrder);
			if (CombatOrder.at(0) == Character->PlayerName)
			{
				printf("Press 1 to Attack");
				cin >> CombatSelection;

				InputValidationCheck(CombatSelection);

				if (CombatSelection == 1)
				{
					cbt->PlayerHP = cbt->PlayerHP - Character->PlayerAtt;
					printf("You have done %d damage\n", Character->PlayerAtt);
					CheckHealthDuringCombat(Character, PP, cbt);
					CombatOrder.erase(CombatOrder.begin());
					CombatOrder.emplace_back(Character->PlayerName);
				}
				else
				{
					printf("Please enter a valid entry!");
				}
			}
			else
			{
				Character->PlayerHP = Character->PlayerHP - cbt->PlayerAtt;
				cout << cbt->PlayerName << " has done " << cbt->PlayerAtt << " damage!\n";
				cout << "You now have " << Character->PlayerHP << " Health" << endl;
				CheckHealthDuringCombat(Character, PP, cbt);
				CombatOrder.erase(CombatOrder.begin());
				CombatOrder.emplace_back(cbt->PlayerName);
			}
		}
		else
		{
			if (PlayerWins == true)
			{
				PostCombatSpawnNemesisOrSpawnRoll = rand() % 10 + 0;
				printf("Nemesis Roll: %d\n", PostCombatSpawnNemesisOrSpawnRoll);
				if (PostCombatSpawnNemesisOrSpawnRoll > 1) //CHANGE THIS
				{
					NemesisLevelCarryOverVar = cbt->PlayerLevel;
					NemesisLevelCarryOverVar = NemesisLevelCarryOverVar;
					PP->SpawnNemesisViaCombatEnemyDeath(NemesisLevelCarryOverVar);
					//printf("Identifier: ");
					//cout << cbt->EnemyRecycleIdentifier;
					PP->PawnUniquePtrNameRecycleVec.push_back(cbt->EnemyRecycleIdentifier);
					PP->EnemyList.erase(cbt);
					PP->CheckAndRegenSpawnTable();
				}
				else
				{
					//printf("Identifier: ");
					//cout << cbt->EnemyRecycleIdentifier;
					PP->PawnUniquePtrNameRecycleVec.push_back(cbt->EnemyRecycleIdentifier);
					PP->EnemyList.erase(cbt);
					PP->CheckAndRegenSpawnTable();
				}
			}
			else if (EnemyWins)
			{
				LevelUpEnemy(cbt, PP);
			}
			break;
		}

	} while (CombatSelection != 9);
}

void TurnBasedCombat::NemesisCombatLoop(unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP, vector<Enemy>::iterator& cbt, int CombatSelection)
{
	CombatOver = false;
	PlayerWins = false;

	if (Character->PlayerSpeed >= cbt->PlayerSpeed)
	{
		CombatOrder = { Character->PlayerName, cbt->PlayerName, Character->PlayerName, cbt->PlayerName };

	}
	else
	{
		printf("==========\n");
		CombatOrder = { cbt->PlayerName, Character->PlayerName };
		printf("==========\n");
	}

	do
	{
		//HUD for enemies
		Character->HUD();
		cbt->EnemyCombatHUD();

		if (CombatOver == false)
		{
			DisplayCombatOrder(CombatOrder);
			if (CombatOrder.at(0) == Character->PlayerName)
			{
				printf("Press 1 to Attack");
				cin >> CombatSelection;

				InputValidationCheck(CombatSelection);

				if (CombatSelection == 1)
				{
					cbt->PlayerHP = cbt->PlayerHP - Character->PlayerAtt;
					printf("You have done %d damage\n", Character->PlayerAtt);
					CheckHealthDuringCombat(Character, PP, cbt);
					CombatOrder.erase(CombatOrder.begin());
					CombatOrder.emplace_back(Character->PlayerName);
				}
				else
				{
					printf("Please enter a valid entry!");
				}
			}
			else
			{
				Character->PlayerHP = Character->PlayerHP - cbt->PlayerAtt;
				cout << cbt->PlayerName << " has done " << cbt->PlayerAtt << " damage!\n";
				cout << "You now have " << Character->PlayerHP << " Health" << endl;
				CheckHealthDuringCombat(Character, PP, cbt);
				CombatOrder.erase(CombatOrder.begin());
				CombatOrder.emplace_back(cbt->PlayerName);
			}
		}
		else
		{
			if (PlayerWins == true)
			{
				PostCombatSpawnNemesisOrSpawnRoll = rand() % 10 + 0;
				printf("Nemesis Roll: %d\n", PostCombatSpawnNemesisOrSpawnRoll);
				if (PostCombatSpawnNemesisOrSpawnRoll > 5) //CHANGE THIS
				{
					//NemesisLevelCarryOverVar = cbt->PlayerLevel;
					//NemesisLevelCarryOverVar = NemesisLevelCarryOverVar;
					//PP->SpawnNemesisViaCombatEnemyDeath(NemesisLevelCarryOverVar);
					PP->NemesisUniquePtrNameRecycleVec.emplace_back(cbt->NemesisRecycleIdentifier);
					PP->NemesisList.erase(cbt);
				}
				else
				{
					PP->NemesisUniquePtrNameRecycleVec.emplace_back(cbt->NemesisRecycleIdentifier);
					PP->NemesisList.erase(cbt);
					PP->CheckAndRegenSpawnTable();
				}
			}
			else if (EnemyWins)
			{
				//LevelUpEnemy(cbt, PP);
				printf("Nemesis Defeated You!\n");
			}
			break;
		}

	} while (CombatSelection != 9);
}

void TurnBasedCombat::DisplayCombatOrder(vector <string> CombatOrder)
{
	for (size_t i = 0; i < CombatOrder.size(); i++)
	{
		printf("==========\n");
		cout << CombatOrder.at(i) <<  endl;
		printf("==========\n");
	}
}

void TurnBasedCombat::CheckHealthDuringCombat(unique_ptr<CharacterPlayer> &Character, unique_ptr<Enemy> &PP, vector<Enemy>::iterator &cbt)
{
	if (Character->PlayerHP <= 0)
	{
		cout << "DEAD";
		CombatOver = true;
		LevelUpEnemy(cbt, PP);
	
	}
	else if (cbt->PlayerHP <= 0)
	{
		cout << "Enemy Dead" << endl;
		Character->PlayerEXP = Character->PlayerEXP + cbt->PlayerEXP;
		CombatOver = true;
		PlayerWins = true;
	}
	else
	{
		//blank, should run the normal program
	}
}

void TurnBasedCombat::LevelUpEnemy(vector<Enemy>::iterator& cbt, unique_ptr<Enemy> &PP)
{
	LvlUpEnemySetter = (cbt->PlayerLevel);
	cout << LvlUpEnemySetter << endl;
	cbt->PlayerLevel = PP->PawnLvl.at(LvlUpEnemySetter);
	cbt->PlayerHP = PP->PawnHealth.at(LvlUpEnemySetter);
	cbt->PlayerAtt = PP->PawnAttack.at(LvlUpEnemySetter);
	cbt->PlayerSpeed = PP->PawnSpeed.at(LvlUpEnemySetter);
	cbt->PlayerEXP = PP->PawnEXP.at(LvlUpEnemySetter);
}

int TurnBasedCombat::InputValidationCheck(int &CombatSelection)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("Please enter a valid input!\n");
			cin >> CombatSelection;
		}
		else
		{
			break;
		}
	}
	return CombatSelection;
}

TurnBasedCombat::~TurnBasedCombat()
{

}
