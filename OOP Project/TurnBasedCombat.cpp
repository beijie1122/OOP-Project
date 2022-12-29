#include "TurnBasedCombat.h"

TurnBasedCombat::TurnBasedCombat()
{

}

void TurnBasedCombat::CheckSpeed(unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP)
{
	CombatOver = false;
	PlayerWins = false;

	OpponentChoice = rand() % 4 + 0;
	cout << "Opponent Chosen: " << OpponentChoice << endl;

	vector<Enemy>::iterator cbt = PP->EnemyList.begin();

	advance(cbt, OpponentChoice);

	if (Character->PlayerSpeed >= cbt->PlayerSpeed)
	{
		CombatOrder = { Character->PlayerName, cbt->PlayerName, Character->PlayerName, cbt->PlayerName };
		int CombatSelection{};

		do
		{
			//HUD for enemies
			cout << cbt->PlayerName << "'s Health: " << cbt->PlayerHP << endl;

			if (CombatOver == false)
			{
				DisplayCombatOrder(CombatOrder);
				if (CombatOrder.at(0) == Character->PlayerName)
				{
					printf("Press 1 to Attack");
					cin >> CombatSelection;

					if (CombatSelection == 1)
					{
						cbt->PlayerHP = cbt->PlayerHP - Character->PlayerAtt;
						printf("You have done %d damage\n", Character->PlayerAtt);
						CheckHealthDuringCombat(Character, cbt);
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
					CheckHealthDuringCombat(Character, cbt);
					CombatOrder.erase(CombatOrder.begin());
					CombatOrder.emplace_back(cbt->PlayerName);
				}
			}
			else
			{
				if (PlayerWins == true)
				{
					PP->EnemyList.erase(cbt);
					PP->CheckAndRegenSpawnTable();
				}
				else if (EnemyWins)
				{
					LevelUpEnemy(cbt, PP);
				}
				break;
			}

		} while (CombatSelection != 9);
	}
	else
	{
		printf("==========\n");
		CombatOrder = { cbt->PlayerName, Character->PlayerName };
		printf("==========\n");
	}

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

void TurnBasedCombat::CheckHealthDuringCombat(unique_ptr<CharacterPlayer> &Character, vector<Enemy>::iterator &cbt)
{
	if (Character->PlayerHP <= 0)
	{
		cout << "DEAD";
		CombatOver = true;
	
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

TurnBasedCombat::~TurnBasedCombat()
{

}
